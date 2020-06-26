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

void ControladorClase::setCodigoClase(string c){ this->codigoClase = c;};
string ControladorClase::getCodigoClase(){ return codigoClase;};

//void ControladorClase::setInfoParaCreacionClase(dtInfoClase *i){ this->infoParaCreacionClase = i;};
//dtInfoClase* ControladorClase::getInfoParaCreacionClase(){ return infoParaCreacionClase;};

void ControladorClase::setClaseAFinalizar(string c){ this->claseAFinalizar = c;};
string ControladorClase::getClaseAFinalizar(){ return claseAFinalizar;};

void ControladorClase::setColEst(map<string,Estudiante*>* c){this->coleccionGlobalEstudiantes=c;};
void ControladorClase::setColDoc(map<string,Docente*>* c){this->coleccionGlobalDocentes=c;};
void ControladorClase::setColAsig(map<string,Asignatura*>* c){this->coleccionGlobalAsignaturas=c;};
void ControladorClase::setColCla(map<string,Clase*>* c){this->coleccionGlobalClases=c;};
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
tipoClase ControladorClase::rolDocente(string codigoAsig){//retorna un tipoClase con el rol del docente en el parametro tipo
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  auto itRol = itDoc->second->getAsignaturas()->find(codigoAsig);
  return itRol->second->getDicta();
};

void ControladorClase::iniciarClase(string codigoAsig, string nombre, tipoClase tipo, dtFecha fecha){
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
    std::string s = std::to_string(coleccionGlobalClases->size());
    teoAux->setCodigo(s);//fijarme cantidad de clases en la asignatura y ponerle codigo igual a eso +1
    teoAux->setNombre(infoParaCreacionClase->getNombre());
    teoAux->setUrl("clases.com/" + clase->getCodigo());
    teoAux->setFechaInicio(infoParaCreacionClase->getFechaInicio());
    teoAux->setFechaFin(fechaNula);
    teoAux->setCreador(itDoc->second);
    teoAux->setAsig(itAsig->second);
    teoAux->setTipo(infoParaCreacionClase->getTipo());

    itDoc->second->agregarClaseNueva(teoAux);
    itAsig->second->agregarClaseNueva(teoAux);

    this->coleccionGlobalClases->insert(pair<string,Clase*> (teoAux->getCodigo(),teoAux));
  }
  else{
    if(infoParaCreacionClase->getTipo() == monitoreo){
      monAux = dynamic_cast<Monitoreo*>(clase);
      std::string s2 = std::to_string(coleccionGlobalClases->size());
      monAux->setCodigo(s2);//fijarme cantidad de clases en la asignatura y ponerle codigo igual a eso +1
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

      this->coleccionGlobalClases->insert(pair<string,Clase*> (monAux->getCodigo(),monAux));
    }
    else{ //practico
      std::string s3 = std::to_string(coleccionGlobalClases->size());
      clase->setCodigo(s3);//fijarme cantidad de clases en la asignatura y ponerle codigo igual a eso +1
      clase->setNombre(infoParaCreacionClase->getNombre());
      clase->setUrl("clases.com/" + clase->getCodigo());
      clase->setFechaInicio(infoParaCreacionClase->getFechaInicio());
      clase->setFechaFin(fechaNula);
      clase->setCreador(itDoc->second);
      clase->setAsig(itAsig->second);
      clase->setTipo(infoParaCreacionClase->getTipo());

      itDoc->second->agregarClaseNueva(clase);
      itAsig->second->agregarClaseNueva(clase);

      this->coleccionGlobalClases->insert(pair<string,Clase*> (clase->getCodigo(),clase));
    }

  }

};

void ControladorClase::cancelarInicio(){};

//FINALIZACION DE CLASE

set<dtClase> ControladorClase::consultarClasesEnVivo(){
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  return itDoc->second->clasesATerminar();
};

set<dtClase> ControladorClase::consultarClasesEnVivoDeAsig(string codigoAsig){
auto itDoc = this->coleccionGlobalAsignaturas->find(codigoAsig);
return itDoc->second->clasesEnVivo();

};

void ControladorClase::finalizarClase(string codigo){
  this->claseAFinalizar = codigo;
};

void ControladorClase::confirmarFin(){
  auto itCla = coleccionGlobalClases->find(this->claseAFinalizar);
  dtFecha fechaFin = generarFecha();
  itCla->second->setFechaFin(fechaFin);

  set<UsrCla*> participantes = itCla->second->getParticipantes();

  for(UsrCla *itUser: participantes) {
    auto itVis = (itUser)->getVis().begin();
    if((*itVis)->getFechaFinVis() == fechaNula){//finalizo la asistencia
      iniciarSesion((itUser)->getEst()->getEmail(),(itUser)->getEst()->getPassword());
      finalizarAsistencia(claseAFinalizar);
      confirmarSalida();
    }
  }

  /*for(auto itUser = participantes.begin(); itUser!=participantes.end(); itUser++){//para cada visualizacion que no haya terminado
    auto itVis = (*itUser)->getVis().begin();
    if((*itVis)->getFechaFinVis() == fechaNula){//finalizo la asistencia
      iniciarSesion((*itUser)->getEst()->getEmail(),(*itUser)->getEst()->getPassword());
      finalizarAsistencia(claseAFinalizar);
      confirmarSalida();
    }
  }*/
  iniciarSesion(itCla->second->getEmailCreador(),"password que no importa porque nunca verificamos");//vuelvo a dejar al docente como el usuario actual};
}

void ControladorClase::cancelarFin(){

};

void ControladorClase::setReloj (Reloj* reloj) {
this->relojSistema = reloj;
};

dtFecha ControladorClase::generarFecha(){//NO TERMINADA, HAY QUE IMPLEMENTAR EL RELOJ DEL SISTEMA QUE ELLOS PIDEN
  return dtFecha(relojSistema->getInstancia()->getAnioSistema(),relojSistema->getInstancia()->getMesSistema(),relojSistema->getInstancia()->getDiaSistema(),relojSistema->getInstancia()->getHoraSistema(),relojSistema->getInstancia()->getMinSistema(),0);
};

//ENVIO DE MENSAJE

set<dtClase> ControladorClase::consultarClasesParticipando(){
  set<dtClase> nuevo;
  if(coleccionGlobalEstudiantes->count(emailUserActual)){
    auto itUser = coleccionGlobalEstudiantes->find(emailUserActual);
    set<UsrCla*> lista = itUser->second->getClasesParticipa();
    for(auto itLista = lista.begin(); itLista!=lista.end(); itLista++){
      auto itVis = (*itLista)->getVis().begin();
      if((*itVis)->getFechaFinVis() == fechaNula){//si la visualizacion mas reciente aun no termino (esta viendo aun)
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
        delete dt;
      }
    }
  }
  else{
    auto itUser = coleccionGlobalDocentes->find(emailUserActual);
    nuevo = itUser->second->clasesATerminar();
  }
  return nuevo;
};

set<dtMensaje> ControladorClase::consultarMensajes(string codigoClase){
  setCodigoClase(codigoClase);
  set<dtMensaje> nuevo;
  auto itCla = coleccionGlobalClases->find(codigoClase);
  set<Mensaje*> mensajes = itCla->second->getMensajes();
  for(auto itMens = mensajes.begin(); itMens!=mensajes.end(); itMens++){
    dtMensaje *dt = new dtMensaje();
    dt->setId((*itMens)->getId());
    dt->setContenido((*itMens)->getContenido());
    dt->setFecha((*itMens)->getFecha());
    if((*itMens)->getEnRespuestaA())
      dt->setEnRespuestaA((*itMens)->getEnRespuestaA()->getId());
    else
      dt->setEnRespuestaA(-1);
    dt->setClase((*itMens)->getClase()->getCodigo());
    dt->setAsignatura((*itMens)->getClase()->getCodigoAsig());
    nuevo.insert(*dt);
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
  int size = coleccionGlobalMensajes->size();
  string cc = getCodigoClase();
  Mensaje* m = this->handler->agregarMensaje(size, (idAResponder!=-1), idAResponder, contenidoMensaje, fecha, cc);
  if(coleccionGlobalEstudiantes->count(emailUserActual)){//si es estudiante
    auto itUser = coleccionGlobalEstudiantes->find(emailUserActual);
    itUser->second->agregarMensaje(m);
  }
  else{
    auto itUser = coleccionGlobalDocentes->find(emailUserActual);
    itUser->second->agregarMensaje(m);
  }
  auto itCla = coleccionGlobalClases->find(codigoClase);
  itCla->second->agregarMensaje(m);

};

void ControladorClase::cancelarEnvio(){

};

//ASITENCIA A CLASE EN VIVO
set<dtAsignatura> ControladorClase::consultarAsigIns(){
  auto itEst = coleccionGlobalEstudiantes->find(emailUserActual);
  return itEst->second->getAsignaturasInscripto();
};

set<dtClase> ControladorClase::consultarClasesVivo(string a){
  set<dtClase> nuevo;
  for(auto itCla=coleccionGlobalAsignaturas->find(a)->second->getClases()->begin(); itCla!=coleccionGlobalAsignaturas->find(a)->second->getClases()->end(); ++itCla){
    if(itCla->second->getFechaFin()==fechaNula && ((itCla->second->getFechaInicio().getAnio()<=relojSistema->getInstancia()->getAnioSistema()) && (itCla->second->getFechaInicio().getMes()<=relojSistema->getInstancia()->getMesSistema()) && (itCla->second->getFechaInicio().getDia()<=relojSistema->getInstancia()->getDiaSistema()) && (itCla->second->getFechaInicio().getHora()<=relojSistema->getInstancia()->getHoraSistema()) && (itCla->second->getFechaInicio().getMinuto()<=relojSistema->getInstancia()->getMinSistema()))){
      if(itCla->second->getTipo()!=monitoreo){
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
      else{//verifico si esta habilitado
        if(itCla->second->estaHabilitado(emailUserActual)){
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
    }
  }
  return nuevo;
};


dtClase ControladorClase::asistirClaseVivo(string codigoClase){
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
  est->asistirClase(clase);
  UsrCla* asistencia = NULL;
  set<UsrCla*> uc = est->getClasesParticipa();
  for (UsrCla *it: uc) {
    if ((it)->getClase()->getCodigo() == clase->getCodigo() ) {
      asistencia = it; //verificar si es = it o = *it
      break;
    }
  }/*
  for(unsigned int i=0; i!=est->getClasesParticipa().size();i++){
    if ((*it)->getClase()->getCodigo() == clase->getCodigo() ) {
      asistencia = *it; //verificar si es = it o = *it
      i=est->getClasesParticipa().size();
    }
    else
      ++it;
  };*/
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
  vis->setFechaFinVis(fechaNula);
  asistencia->setVisualizacion(vis); //ver.h y arreglar esta funcion

};

void ControladorClase::cancelarAsistencia(){

};

//FINALIZACION ASISTENCIA A CLASE EN VIVO

set<dtClase*> ControladorClase::consultarClasesParticipandoVivo(){
  set<dtClase*> clasesAsistiendo;
  auto itEst = this->coleccionGlobalEstudiantes->find(this->emailUserActual);
  Estudiante* est = itEst->second; // busco el estudiante
  for(auto it=est->getAsistiendo()->begin();it!=est->getAsistiendo()->end();it++){
    dtClase* dt = new dtClase();
    dt->setNombre((*it)->getNombre());
    dt->setCodigo((*it)->getCodigo());
    dt->setFechaInicio((*it)->getFechaInicio());
    dt->setFechaFin((*it)->getFechaFin());
    dt->setTipo((*it)->getTipo());
    dt->setUrl((*it)->getUrl());
    dt->setCreador((*it)->getEmailCreador());
    dt->setAsig((*it)->getCodigoAsig());
    clasesAsistiendo.insert(dt);
  }
  return clasesAsistiendo;
};

void ControladorClase::finalizarAsistencia(string codigoClase) {
  this->setClaseAFinalizar(codigoClase);
};

void ControladorClase::confirmarSalida(){
  auto itCla = this->coleccionGlobalClases->find(claseAFinalizar);
  auto itEst = this->coleccionGlobalEstudiantes->find(this->emailUserActual);
  Estudiante* est = itEst->second; // busco el estudiante
  est->dejarDeAsistir(itCla->second);

  //auto it = est->getClasesParticipa().begin();
  //bool sigue = true; // SE BUSCA EL UsrCla DE LA CLASE DE LA QUE SE VA A SALIR
  UsrCla* asistencia;

  set<UsrCla*> clasesParticipa = est->getClasesParticipa();
  for (UsrCla *it: clasesParticipa) {
    if ((it)->getClase()->getCodigo() == this->claseAFinalizar) {
      asistencia = it;
      break;
    }
  }
/*
  UsrCla* asistencia = NULL;
  unsigned int i=0;
  while( i!=est->getClasesParticipa().size() && sigue ) {
    if ((*it)->getClase()->getCodigo() == this->claseAFinalizar) {
      sigue = false;
      asistencia = *it;
    }
    else
      ++it;
    i++;
    };
*/
  auto itVis=asistencia->getVis().begin();
  bool sigue = true;
  unsigned int j=0;
  while(j!=asistencia->getVis().size() && sigue ){
    if((*itVis)->getEnVivo()== true && (*itVis)->getFechaFinVis()== fechaNula){
      sigue = false;
      (*itVis)->setFechaFinVis(generarFecha());
    }
    else
      ++itVis;
    j++;
  }
};


void ControladorClase::cancelarSalida(){};

//TIEMPO DE ASISTENCIA A CLASE

set<DtTiempoDeClase> ControladorClase::consultarTiempoClaseDocente(string codigo){
  set<DtTiempoDeClase> nuevo;
  auto itAsig = this->coleccionGlobalAsignaturas->find(codigo);
  int tiempo=0;
  int divisor=0;
  bool primera;

  map<string,Clase*>* clasesParticipa = itAsig->second->getClases();
  for (auto const& itCla: *clasesParticipa){
    if(itCla.second->getEmailCreador()==this->emailUserActual){
      tiempo=0;
      divisor=0;
      DtTiempoDeClase *tiempoClase= new DtTiempoDeClase();
      tiempoClase->setNombre(itCla.second->getNombre());
      tiempoClase->setCodClase(itCla.second->getCodigo());
      tiempoClase->setTiempo(0);
      set<UsrCla*> nombre = itCla.second->getParticipantes();
      for (UsrCla *itEstCla: nombre) {
        primera=true;
        set<Visualizacion*> sett = itEstCla->getVis();
        for (Visualizacion *itVis: sett) {
          if(itVis->getEnVivo()==true && !(itVis->getFechaFinVis()==fechaNula)){
            tiempo=0;
            tiempo+=itVis->getFechaFinVis() - itVis->getFechaInicioVis();
            tiempoClase->setTiempo(tiempoClase->getTiempo()+tiempo);
            if(primera){
              divisor++;
              primera=false;
            }
          }
          /*
          for(auto itVis = sett.begin(); itVis!=sett.end();++itVis){
            if((*itVis)->getEnVivo()==true && !((*itVis)->getFechaFinVis()==fechaNula)){
              tiempo+=(*itVis)->getFechaFinVis() - (*itVis)->getFechaInicioVis();
              tiempoClase->setTiempo(tiempoClase->getTiempo()+tiempo);
              if(primera){
                divisor++;
                primera=false;
              }
            }
          }*/
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
  /*
  for(auto itCla =itAsig->second->getClases()->begin(); itCla!=itAsig->second->getClases()->end();++itCla){
    if(itCla->second->getEmailCreador()==this->emailUserActual){
      tiempo=0;
      divisor=0;
      DtTiempoDeClase *tiempoClase= new DtTiempoDeClase();
      tiempoClase->setNombre(itCla->second->getNombre());
      tiempoClase->setCodClase(itCla->second->getCodigo());
      for(auto itEstCla =itCla->second->getParticipantes().begin(); itEstCla!=itCla->second->getParticipantes().end();++itEstCla){
        primera=true;
        set<Visualizacion*> sett = (*itEstCla)->getVis();
        for(auto itVis = sett.begin(); itVis!=sett.end();++itVis){
          if((*itVis)->getEnVivo()==true && !((*itVis)->getFechaFinVis()==fechaNula)){
            tiempo+=(*itVis)->getFechaFinVis() - (*itVis)->getFechaInicioVis();
            tiempoClase->setTiempo(tiempoClase->getTiempo()+tiempo);
            if(primera){
              divisor++;
              primera=false;
            }
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
  }*/
  return nuevo;
};


//set<dtInfoClase> ControladorClase::desplegarInfoClases(string){};

ControladorClase::~ControladorClase(){};
