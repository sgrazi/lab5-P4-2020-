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
#include <string>
#include <set>
#include <map>

const dtFecha fechaNula(0,0,0,0,0,0);

using namespace std;

ControladorClase::ControladorClase(){

};
void ControladorClase::setPasswordUserActual(string p){ this->passwordUserActual= p;};
string ControladorClase::getPasswordUserActual(){ return passwordUserActual;};

void ControladorClase::setEmailUserActual(string e){  this->emailUserActual = e;};
string ControladorClase::getEmailUserActual(){  return emailUserActual;};

//void ControladorClase::setInfoParaCreacionClase(dtInfoClase *i){ this->infoParaCreacionClase = i;};
//dtInfoClase* ControladorClase::getInfoParaCreacionClase(){ return infoParaCreacionClase;};

void ControladorClase::setClaseAFinalizar(int c){ this->claseAFinalizar = c;};
int ControladorClase::getClaseAFinalizar(){ return claseAFinalizar;};

void ControladorClase::setColEst(map<string,Estudiante*>* c){this->coleccionGlobalEstudiantes=c;};
void ControladorClase::setColDoc(map<string,Docente*>* c){this->coleccionGlobalDocentes=c;};
void ControladorClase::setColAsig(map<int,Asignatura*>* c){this->coleccionGlobalAsignaturas=c;};
void ControladorClase::setColCla(map<int,Clase*>* c){this->coleccionGlobalClases=c;};

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
void ControladorClase::confirmarInicio(){
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  auto itAsig = this->coleccionGlobalAsignaturas->find(infoParaCreacionClase->getCodigo());
  Clase* clase;
  if(infoParaCreacionClase->getTipo() == teorico)
    clase = new Teorico();
  else
    if(infoParaCreacionClase->getTipo() == practico)
      clase = new Practico();
    else
      clase = new Monitoreo();

  clase->setCodigo(itAsig->second->getClases()->size());//fijarme cantidad de clases en la asignatura y ponerle codigo igual a eso +1
  clase->setNombre(infoParaCreacionClase->getNombre());
  clase->setUrl("clases.com/" + clase->getCodigo());
  clase->setFechaInicio(infoParaCreacionClase->getFechaInicio());
  clase->setFechaFin(fechaNula);
  clase->setCreador(itDoc->second);
  clase->setAsig(itAsig->second);
  clase->setTipo(infoParaCreacionClase->getTipo());

  //FALTA PARTE DE LA LISTA DE HABILITADOS DEL MONITOREO

  itDoc->second->agregarClaseNueva(clase);
  itAsig->second->agregarClaseNueva(clase);

  this->coleccionGlobalClases->insert(pair<int,Clase*> (clase->getCodigo(),clase));

};

void ControladorClase::cancelarInicio(){

};




//FINALIZACION DE CLASE

set<dtClase> ControladorClase::consultarClasesEnVivo(){
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  return itDoc->second->clasesATerminar();
};

void ControladorClase::finalizarClase(int codigo){
  this->claseAFinalizar = codigo;
};

void ControladorClase::confirmarFin(){
  auto itCla = coleccionGlobalClases->find(this->claseAFinalizar);
  dtFecha fechaFin = generarFecha();
  itCla->second->setFechaFin(fechaFin);

  if(itCla->second->getTipo()==teorico)
      itCla->second->calcularAsistentes();
};

void ControladorClase::cancelarFin(){

};

dtFecha ControladorClase::generarFecha(){//NO TERMINADA, HAY QUE IMPLEMENTAR EL RELOJ DEL SISTEMA QUE ELLOS PIDEN
  return dtFecha(1,1,1,1,1,1);
};


set<dtAsignatura> ControladorClase::consultarAsigIns(){};
set<dtClase> ControladorClase::consultarClasesDiferido(string){};
dtClase ControladorClase::AsistirClaseDiferido(string){};
set<dtMensaje> ControladorClase::confirmarAsistencia(){};
void ControladorClase::cancelarAsistencia(){};
set<dtInfoClase> ControladorClase::desplegarInfoClases(string){};
void ControladorClase::confirmarEnvio(){};

ControladorClase::~ControladorClase(){};
