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

void ControladorClase::setInfoParaCreacionClase(dtInfoClase i){ this->infoParaCreacionClase = i;};
dtInfoClase ControladorClase::getInfoParaCreacionClase(){ return infoParaCreacionClase;};

void ControladorClase::setClaseAFinalizar(int c){ this->claseAFinalizar = c;};
int ControladorClase::getClaseAFinalizar(){ return claseAFinalizar;};

void ControladorClase::setColEst(map<string,Estudiante*>* c){this->coleccionGlobalEstudiantes=c;};
void ControladorClase::setColDoc(map<string,Docente*>* c){this->coleccionGlobalDocentes=c;};
void ControladorClase::setColAsig(map<int,Asignatura*>* c){this->coleccionGlobalAsignaturas=c;};

//inicio de clase
void ControladorClase::iniciarSesion(string e, string p){
  this->setPasswordUserActual(p);
  this->setEmailUserActual(e);
};

set<dtAsignatura> ControladorClase::consultarAsignaturasDocente(){
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  set<dtAsignatura> nuevo = itDoc->second->getInfo();
  return nuevo;
};

dtInfoClase ControladorClase::infoDocente(int codigoAsig){//retorna un dtInfoClase con el rol del docente en el parametro tipo
  dtInfoClase* dt = new dtInfoClase();
  auto itDoc = this->coleccionGlobalDocentes->find(emailUserActual);
  auto itRol = itDoc->second->getAsignaturas().find(codigoAsig);
  dt->setTipo(itRol->second->getDicta());
  return *dt;
};

void ControladorClase::iniciarClase(string codigoAsig, string nombre, tipoClase tipo, dtFecha fecha){/*
  this->setCodigoAsig(codigoAsig);
  this->setNombreAsig(nombre);*/
};

set<dtEstudiante> ControladorClase::consultarInscriptos(){};
void ControladorClase::agregarHabilitado(string){};
dtInfoClase ControladorClase::desplegarInfoClase(){};
void ControladorClase::confirmarInicio(){};
void ControladorClase::cancelarInicio(){};

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
