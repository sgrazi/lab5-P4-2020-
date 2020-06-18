#include "../include/controladorClase.h"
#include "../include/estudiante.h"
#include "../include/docente.h"
#include "../include/asignatura.h"
#include "../include/clase.h"
#include "../include/teorico.h"
#include "../include/practico.h"
#include "../include/monitoreo.h"
#include "../include/dtAsignatura.h"
#include "../include/dtInfoClase.h"
#include "../include/dtEstudiante.h"
#include "../include/dtFecha.h"
#include "../include/dtClase.h"
#include "../include/dtMensaje.h"
#include "../include/visualizacion.h"
#include "../include/usrCla.h"
#include <iostream>
#include <string>
#include <set>
#include <map>

const dtFecha fechaNula(0,0,0,0,0,0);

using namespace std;

ControladorClase* ControladorClase::instancia = NULL;

ControladorClase::ControladorClase(){

};

ControladorClase* ControladorClase::getInstancia() {
  if (instancia == NULL)
    instancia = new ControladorClase();
  return instancia;
};

void ControladorClase::setPasswordUserActual(string p){ this->passwordUserActual= p;};
string ControladorClase::getPasswordUserActual(){ return passwordUserActual;};

void ControladorClase::setEmailUserActual(string e){  this->emailUserActual = e;};
string ControladorClase::getEmailUserActual(){  return emailUserActual;};

void ControladorClase::setContenidoMensaje(string c){ this->contenidoMensaje = c;};
string ControladorClase::getContenidoMensaje(){ return contenidoMensaje;};

void ControladorClase::setIdAResponder(int id){ this->idAResponder = id;};
int ControladorClase::getIdAResponder(){ return idAResponder;};

void ControladorClase::setCodigoClase(int c){ this->codigoClase = c;};
int ControladorClase::getCodigoClase(){ return codigoClase;};

//void ControladorClase::setInfoParaCreacionClase(dtInfoClase *i){ this->infoParaCreacionClase = i;};
//dtInfoClase* ControladorClase::getInfoParaCreacionClase(){ return infoParaCreacionClase;};

void ControladorClase::setClaseAFinalizar(int c){ this->claseAFinalizar = c;};
int ControladorClase::getClaseAFinalizar(){ return claseAFinalizar;};

void ControladorClase::setColEst(map<string,Estudiante*>* c){this->coleccionGlobalEstudiantes=c;};
void ControladorClase::setColDoc(map<string,Docente*>* c){this->coleccionGlobalDocentes=c;};
void ControladorClase::setColAsig(map<int,Asignatura*>* c){this->coleccionGlobalAsignaturas=c;};
void ControladorClase::setColCla(map<int,Clase*>* c){this->coleccionGlobalClases=c;};
void ControladorClase::setColMens(map<int,Mensaje*>* c){this->coleccionGlobalMensajes=c;};

void ControladorClase::setHandler(HandlerMensajes* h){ this->handler = h;};

//INICIO DE CLASE
void ControladorClase::iniciarSesion(string e, string p){
  this->setPasswordUserActual(p);
  this->setEmailUserActual(e);
};

set<dtAsignatura> ControladorClase::consultarAsignaturasDocente(){
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  set<dtAsignatura> nuevo = itDoc->second->getInfo();
  return nuevo;
};
//para mi esta funcion no es necesaria
/*se supone que aca se creaba un dtInfoClase y se empezaba a guardar info
para despues usarla en el confirmar, pero no es necesario, lo puedo empezar a
hacer en iniciarClase*/
tipoClase ControladorClase::rolDocente(int codigoAsig){//retorna un tipoClase con el rol del docente en el parametro tipo
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  auto itRol = itDoc->second->getAsignaturas()->find(codigoAsig);
  return itRol->second->getDicta();
};

void ControladorClase::iniciarClase(int codigoAsig, string nombre, tipoClase tipo, dtFecha fecha){
  dtInfoClase* dt = new dtInfoClase();
  dt->setIniciadaPor(emailUserActual);
  dt->setCodigo(codigoAsig);
  dt->setNombre(nombre);
  dt->setTipo(tipo);
  dt->setFechaInicio(fecha);
  this->infoParaCreacionClase = dt;
  //cout << "dtInfoClase creado\n";
};

map<string,dtEstudiante*> ControladorClase::consultarInscriptos(){
  map<string,dtEstudiante*> set;
  auto itAsig = this->coleccionGlobalAsignaturas->find(infoParaCreacionClase->getCodigo());//busco mi asignatura
  for(auto it = itAsig->second->getInscriptos()->begin(); it!=itAsig->second->getInscriptos()->end(); it++){
    dtEstudiante* nuevo = new dtEstudiante();
    nuevo->setNombre(it->second->getNombre());
    nuevo->setEmail(it->second->getEmail());
    nuevo->setImagen(it->second->getImagen());
    nuevo->setCI(it->second->getCI());
    set.insert(pair<string,dtEstudiante*> (nuevo->getEmail(),nuevo));
  }
  return set;
};

void ControladorClase::agregarHabilitado(string email){//que pasa si quiero agregar mas de 15
  infoParaCreacionClase->agregarHabilitado(email);
};

dtInfoClase ControladorClase::desplegarInfoClase(){
  return *infoParaCreacionClase;
};
void ControladorClase::confirmarInicio(){//se separa en dos casos que hacen lo mismo, no se por que si no es asi tira seg faul
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  auto itAsig = this->coleccionGlobalAsignaturas->find(infoParaCreacionClase->getCodigo());
  Clase* clase;
  Teorico* teoAux;
  Monitoreo* monAux;
  if(infoParaCreacionClase->getTipo() == teorico){
    clase = new Teorico();
  }
  else
    if(infoParaCreacionClase->getTipo() == practico)
      clase = new Practico();
    else
      clase = new Monitoreo();

  if(infoParaCreacionClase->getTipo() == teorico){
    teoAux = dynamic_cast<Teorico*>(clase);
    teoAux->setAsistentes(0);
    teoAux->setCodigo(itAsig->second->getClases()->size());//fijarme cantidad de clases en la asignatura y ponerle codigo igual a eso +1
    teoAux->setNombre(infoParaCreacionClase->getNombre());
    teoAux->setUrl("clases.com/" + clase->getCodigo());
    teoAux->setFechaInicio(infoParaCreacionClase->getFechaInicio());
    teoAux->setFechaFin(fechaNula);
    teoAux->setCreador(itDoc->second);
    teoAux->setAsig(itAsig->second);
    teoAux->setTipo(infoParaCreacionClase->getTipo());

    itDoc->second->agregarClaseNueva(teoAux);
    itAsig->second->agregarClaseNueva(teoAux);

    this->coleccionGlobalClases->insert(pair<int,Clase*> (teoAux->getCodigo(),teoAux));
  }
  else{
    if(infoParaCreacionClase->getTipo() == monitoreo){
      monAux = dynamic_cast<Monitoreo*>(clase);
      monAux->setCodigo(itAsig->second->getClases()->size());//fijarme cantidad de clases en la asignatura y ponerle codigo igual a eso +1
      monAux->setNombre(infoParaCreacionClase->getNombre());
      monAux->setUrl("clases.com/" + clase->getCodigo());
      monAux->setFechaInicio(infoParaCreacionClase->getFechaInicio());
      monAux->setFechaFin(fechaNula);
      monAux->setCreador(itDoc->second);
      monAux->setAsig(itAsig->second);
      monAux->setTipo(infoParaCreacionClase->getTipo());

      auto arregloEmails = infoParaCreacionClase->getHabilitados();
      for(int i=0;i<infoParaCreacionClase->getCantHabilitados();++i){//creo la lista de habilitados
        monAux->agregarHabilitado(this->coleccionGlobalEstudiantes->find(arregloEmails[i])->second);
      }
      itDoc->second->agregarClaseNueva(monAux);
      itAsig->second->agregarClaseNueva(monAux);

      this->coleccionGlobalClases->insert(pair<int,Clase*> (monAux->getCodigo(),monAux));
    }
    else{ //practico
      clase->setCodigo(itAsig->second->getClases()->size());//fijarme cantidad de clases en la asignatura y ponerle codigo igual a eso +1
      clase->setNombre(infoParaCreacionClase->getNombre());
      clase->setUrl("clases.com/" + clase->getCodigo());
      clase->setFechaInicio(infoParaCreacionClase->getFechaInicio());
      clase->setFechaFin(fechaNula);
      clase->setCreador(itDoc->second);
      clase->setAsig(itAsig->second);
      clase->setTipo(infoParaCreacionClase->getTipo());

      itDoc->second->agregarClaseNueva(clase);
      itAsig->second->agregarClaseNueva(clase);

      this->coleccionGlobalClases->insert(pair<int,Clase*> (clase->getCodigo(),clase));
    }

  }

};

void ControladorClase::cancelarInicio(){};

//FINALIZACION DE CLASE

set<dtClase> ControladorClase::consultarClasesEnVivo(){
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  return itDoc->second->clasesATerminar();
};

set<dtClase> ControladorClase::consultarClasesEnVivoDeAsig(int codigoAsig){
auto itDoc = this->coleccionGlobalAsignaturas->find(codigoAsig);
return itDoc->second->clasesEnVivo();

};

void ControladorClase::finalizarClase(int codigo){
  this->claseAFinalizar = codigo;
};

void ControladorClase::confirmarFin(){
  auto itCla = coleccionGlobalClases->find(this->claseAFinalizar);
  dtFecha fechaFin = generarFecha();
  itCla->second->setFechaFin(fechaFin);
/*
  if(itCla->second->getTipo()==teorico)
      itCla->second->calcularAsistentes();*/
};

void ControladorClase::cancelarFin(){

};

dtFecha ControladorClase::generarFecha(){//NO TERMINADA, HAY QUE IMPLEMENTAR EL RELOJ DEL SISTEMA QUE ELLOS PIDEN
  return dtFecha(1,1,1,1,1,1);
};

//ENVIO DE MENSAJE

set<dtClase> ControladorClase::consultarClasesParticipando(){
  set<dtClase> nuevo;
  auto itUser = coleccionGlobalEstudiantes->find(emailUserActual);
  set<UsrCla*> lista = itUser->second->getClasesParticipa();
  for(auto itLista = lista.begin(); itLista!=lista.end(); itLista++){
    dtClase *dt = new dtClase();
    dt->setNombre((*itLista)->getClase()->getNombre());
    dt->setCodigo((*itLista)->getClase()->getCodigo());
    dt->setFechaInicio((*itLista)->getClase()->getFechaInicio());
    dt->setFechaFin((*itLista)->getClase()->getFechaFin());
    dt->setTipo((*itLista)->getClase()->getTipo());
    dt->setUrl((*itLista)->getClase()->getUrl());
    dt->setCreador((*itLista)->getClase()->getEmailCreador());
    dt->setAsig((*itLista)->getClase()->getCodigoAsig());
    nuevo.insert(*dt);
  }
  return nuevo;
};

set<dtMensaje> ControladorClase::consultarMensajes(int codigoClase){
  setCodigoClase(codigoClase);
  set<dtMensaje> nuevo;
  auto itCla = coleccionGlobalClases->find(codigoClase);
  set<Mensaje*> mensajes = itCla->second->getMensajes();
  for(auto itMens = mensajes.begin(); itMens!=mensajes.end(); itMens++){
    dtMensaje *dt = new dtMensaje();
    dt->setId((*itMens)->getId());
    dt->setContenido((*itMens)->getContenido());
    dt->setFecha((*itMens)->getFecha());
    dt->setEnRespuestaA((*itMens)->getEnRespuestaA()->getId());
    dt->setClase((*itMens)->getClase()->getCodigo());
    dt->setAsignatura((*itMens)->getClase()->getCodigoAsig());
  }
  return nuevo;
};

void ControladorClase::enviarMensaje(string contenido){
  this->setContenidoMensaje(contenido);
  this->setIdAResponder(-1);//si no es respuesta a nada lo dejo constante -1
};

void ControladorClase::enviarRespuesta(int id,string contenido){
  this->setContenidoMensaje(contenido);
  this->setIdAResponder(id);
};

void ControladorClase::confirmarEnvio(){
  dtFecha fecha = generarFecha();
  Mensaje* m = this->handler->agregarMensaje(coleccionGlobalMensajes->size(), (idAResponder!=-1), idAResponder, contenidoMensaje, fecha, getCodigoClase());
  auto itUser = coleccionGlobalEstudiantes->find(emailUserActual);
  itUser->second->agregarMensaje(m);
};

void ControladorClase::cancelarEnvio(){

};

//ASITENCIA A CLASE EN VIVO
set<dtAsignatura> ControladorClase::consultarAsigIns(){
  auto itEst = coleccionGlobalEstudiantes->find(emailUserActual);
  return itEst->second->getAsignaturasInscripto();
};

/*
set<dtClase> ControladorClase::consultarClasesDiferido(int a){
};
dtClase ControladorClase::AsistirClaseDiferido(int){};*/

set<dtClase> ControladorClase::consultarClasesVivo(int a){
  set<dtClase> nuevo;
  for(auto itCla=coleccionGlobalAsignaturas->find(a)->second->getClases()->begin(); itCla!=coleccionGlobalAsignaturas->find(a)->second->getClases()->end(); ++itCla){
    if(itCla->second->getFechaFin()==fechaNula){
      dtClase *dt = new dtClase();
      dt->setNombre(itCla->second->getNombre());
      dt->setCodigo(itCla->second->getCodigo());
      dt->setFechaInicio(itCla->second->getFechaInicio());
      dt->setFechaFin(itCla->second->getFechaFin());
      dt->setTipo(itCla->second->getTipo());
      dt->setUrl(itCla->second->getUrl());
      dt->setCreador(itCla->second->getEmailCreador());
      dt->setAsig(itCla->second->getCodigoAsig());
      nuevo.insert(*dt);
    }
  }
  return nuevo;
};

dtClase ControladorClase::asistirClaseVivo(int codigoClase){
  this->claseAFinalizar = codigoClase; //usa claseAFinalizar porque es la variable mas parecida?
  dtClase* dt = new dtClase();
  auto it = coleccionGlobalClases->find(codigoClase);

  dt->setNombre(it->second->getNombre());
  dt->setCodigo(it->second->getCodigo());
  dt->setFechaInicio(it->second->getFechaInicio());
  dt->setFechaFin(fechaNula);
  dt->setTipo(it->second->getTipo());
  dt->setUrl(it->second->getUrl());
  dt->setCreador(it->second->getEmailCreador());
  dt->setAsig(it->second->getCodigoAsig());

  return *dt;
};

void ControladorClase::confirmarAsistenciaVivo(){
  Estudiante* est = this->coleccionGlobalEstudiantes->find(this->emailUserActual)->second; // busco el estudiante
  Clase* clase = this->coleccionGlobalClases->find(this->claseAFinalizar)->second; //busco la clase

  UsrCla* asistencia = NULL;
  auto it = est->getClasesParticipa().begin();
  bool sigue = true; //SE BUSCA SI YA EXISTIA UN USRCLA
  while(it!=est->getClasesParticipa().end() && sigue ){
    //UsrCla *current = *it;
    if ((*it)->getClase()->getCodigo() == clase->getCodigo() ) {
      sigue = false;
      asistencia = *it; //verificar si es = it o = *it
    }
    else
      ++it;
  };
                           //SI NO EXISTIA SE GENERA Y ASOCIA
  if(asistencia==NULL){
    asistencia = new UsrCla();
    asistencia->setEstudiante(est);
    asistencia->setClase(clase);
    est->asistir(asistencia);
    clase->nuevaVis(asistencia);
  };
                           // SETEO GENERAL DE LA VISUALIZACION
  Visualizacion* vis = new Visualizacion();
  vis->setEnVivo(true);
  vis->setFechaInicioVis(generarFecha());
  asistencia->setVisualizacion(vis); //ver.h y arreglar esta funcion
};

void ControladorClase::cancelarAsistencia(){

};

//FINALIZACION ASISTENCIA A CLASE EN VIVO

set<dtClase*> ControladorClase::consultarClasesParticipandoVivo(){
  set<dtClase*> clasesAsistiendo;
  auto itEst = this->coleccionGlobalEstudiantes->find(this->emailUserActual);
  Estudiante* est = itEst->second; // busco el estudiante

  for(auto it =est->getClasesParticipa().begin(); it!=est->getClasesParticipa().end();++it){ //for que recorre la coleccion de UsrCla
    bool buscando = true;
    UsrCla* usercla =  (*it);/*
    if(hola==NULL)
      cout << "r";
    else{
      Clase* c = hola->getClase();
      if(c==NULL)
        cout << "r2";
      else
        cout << c->getNombre();
    }*/
    set<Visualizacion*> coleccionVis = (*it)->getVis();
    auto itVis = coleccionVis.begin();
    while(itVis!=coleccionVis.end() && buscando){ //While que recorre las visualizaciones del UsrCla buscando si hay alguna en vivo
      if ((*itVis)->getEnVivo()==true && (*itVis)->getFechaFinVis()==fechaNula){
        buscando = false;
      }
      else
        ++itVis;
    };

    if(!buscando){
      dtClase* dt = new dtClase();
      /*Clase* cla = it->getClase();
      if(cla==NULL){
        cout << "opa2";
      }*/
      dt->setNombre(usercla->getClase()->getNombre());
      dt->setCodigo(usercla->getClase()->getCodigo());
      dt->setFechaInicio(usercla->getClase()->getFechaInicio());
      dt->setFechaFin(usercla->getClase()->getFechaFin());
      dt->setTipo(usercla->getClase()->getTipo());
      dt->setUrl(usercla->getClase()->getUrl());
      dt->setCreador(usercla->getClase()->getEmailCreador());
      dt->setAsig(usercla->getClase()->getCodigoAsig());
      clasesAsistiendo.insert(dt);
    }
  };
  return clasesAsistiendo;
};

void ControladorClase::finalizarAsistencia(int codigoClase) {
  this->setClaseAFinalizar(codigoClase);
};

void ControladorClase::confirmarSalida(){
  auto itEst = this->coleccionGlobalEstudiantes->find(this->emailUserActual);
  Estudiante* est = itEst->second; // busco el estudiante


  auto it = est->getClasesParticipa().begin();
  bool sigue = true; // SE BUSCA EL UsrCla DE LA CLASE DE LA QUE SE VA A SALIR

  UsrCla* asistencia = NULL;

  while( it!=est->getClasesParticipa().end() && sigue ) {
    if ((*it)->getClase()->getCodigo() == this->claseAFinalizar) {
      sigue = false;
      asistencia = *it;
    }
    else
      ++it;
    };

  auto itVis=asistencia->getVis().begin();
  sigue = true;

  while(itVis!=asistencia->getVis().end() && sigue ){
    if((*itVis)->getEnVivo()== true && (*itVis)->getFechaFinVis()== fechaNula){
      sigue = false;
      (*itVis)->setFechaFinVis(generarFecha());
    }
    else
      ++itVis;
  }
};


void ControladorClase::cancelarSalida(){};

set<DtTiempoDeClase> ControladorClase::consultarTiempoClaseDocente(int codigo){
  set<DtTiempoDeClase> nuevo;
  auto itAsig = this->coleccionGlobalAsignaturas->find(codigo);
  int tiempo=0;
  int divisor=0;
  for(auto itCla =itAsig->second->getClases()->begin(); itCla!=itAsig->second->getClases()->end();++itCla){
   if(itCla->second->getEmailCreador()==this->emailUserActual){
    tiempo=0;
    divisor=0;
    DtTiempoDeClase *tiempoClase= new DtTiempoDeClase();
    tiempoClase->setNombre(itCla->second->getNombre());
    tiempoClase->setCodClase(itCla->second->getCodigo());
    for(auto itEstCla =itCla->second->getParticipantes().begin(); itEstCla!=itCla->second->getParticipantes().end();++itEstCla){
      for(auto itVis =(*itEstCla)->getVis().begin(); itVis!=(*itEstCla)->getVis().end();++itVis){
        if((*itVis)->getEnVivo()==true && !((*itVis)->getFechaFinVis()==fechaNula)){
          divisor++;
          tiempo+=3600*((*itVis)->getFechaFinVis().getHora() - (*itVis)->getFechaInicioVis().getHora());
          tiempo+=60*((*itVis)->getFechaFinVis().getMinuto() - (*itVis)->getFechaInicioVis().getMinuto());
          tiempo+=((*itVis)->getFechaFinVis().getSegundo() - (*itVis)->getFechaInicioVis().getSegundo());
          tiempoClase->setTiempo(tiempoClase->getTiempo()+tiempo);
        }
      }
    }
    if(divisor!=0){
      tiempoClase->setTiempo(tiempoClase->getTiempo()/divisor);
      nuevo.insert(*tiempoClase);
    }
    else{
      tiempoClase->setTiempo(0);
      nuevo.insert(*tiempoClase);
    }
   }
  }
  return nuevo;
};


//set<dtInfoClase> ControladorClase::desplegarInfoClases(string){};

ControladorClase::~ControladorClase(){};
