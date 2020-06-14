#include "../include/controladorClase.h"
#include "../include/estudiante.h"
#include "../include/docente.h"
#include "../include/asignatura.h"
#include "../include/dtAsignatura.h"
#include "../include/dtInfoClase.h"
#include "../include/dtEstudiante.h"
#include "../include/dtFecha.h"
#include "../include/dtClase.h"
#include "../include/dtMensaje.h"
#include <string>
#include <set>
#include <map>

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
  auto itRol = itDoc->second->getAsignaturas().find(codigoAsig);
  return itRol->second->getDicta();
};

void ControladorClase::iniciarClase(int codigoAsig, string nombre, tipoClase tipo, dtFecha fecha){
  dtInfoClase* dt = new dtInfoClase();
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  auto itRol = itDoc->second->getAsignaturas().find(codigoAsig);
  dt->setIniciadaPor(emailUserActual);
  dt->setCodigo(codigoAsig);
  dt->setNombre(nombre);
  dt->setTipo(tipo);
  dt->setFechaInicio(fecha);
  this->infoParaCreacionClase = dt;
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
  return infoParaCreacionClase;
};
void ControladorClase::confirmarInicio(){
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  auto itAsig = this->coleccionGlobalAsignaturas->find(infoParaCreacionClase->getCodigo());

  if(infoParaCreacionClase->getTipo() == teorico)
    Teorico *clase = new Teorico();
  else
    if(infoParaCreacionClase->getTipo() == practico)
      Practico *clase = new Practico();
    else
      Monitoreo *clase = new Monitoreo();

  clase->setCodigo(itAsig->second->getClases()->size());//fijarme cantidad de clases en la asignatura y ponerle codigo igual a eso +1
  clase->setNombre(infoParaCreacionClase->getNombre());
  clase->setUrl("clases.com/" + clase->getCodigo());
  clase->setFechaInicio(infoParaCreacionClase->getFechaInicio());
  clase->setCreador(itDoc->second);
  clase->setAsig(itAsig->second);
  clase->setTipo(infoParaCreacionClase->getTipo());

  itDoc->second->agregarClaseNueva(clase);
  itAsig->second->agregarClaseNueva(clase);

};

void ControladorClase::cancelarInicio(){

};

string ControladorClase::generarCodigo(){};
string ControladorClase::generarUrl(Clase*){};
dtFecha ControladorClase::generarFecha(){};
set<dtClase> ControladorClase::consultarClasesEnVivo(){};
dtClase ControladorClase::finalizarClase(string){};
void ControladorClase::confirmarFin(){};
void ControladorClase::cancelarFin(){};
set<dtAsignatura> ControladorClase::consultarAsigIns(){};
set<dtClase> ControladorClase::consultarClasesDiferido(string){};
dtClase ControladorClase::AsistirClaseDiferido(string){};
set<dtMensaje> ControladorClase::confirmarAsistencia(){};
void ControladorClase::cancelarAsistencia(){};
set<dtInfoClase> ControladorClase::desplegarInfoClases(string){};
void ControladorClase::confirmarEnvio(){};

ControladorClase::~ControladorClase(){};
