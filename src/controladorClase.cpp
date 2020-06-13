#include "../include/controladorClase.h"


ControladorClase::ControladorClase(){

};
void ControladorClase::setPasswordUserActual(string p){ this->passwordUserActual= p;};
string ControladorClase::getPasswordUserActual(){ return passwordUserActual;};

void ControladorClase::setEmailUserActual(string e){  this->emailUserActual = e;};
string ControladorClase::getEmailUserActual(){  return emailUserActual;};

void ControladorClase::setInfoParaCreacionClase(DtInfoClase i){ this->infoParaCreacionClase = i;};
DtInfoClase ControladorClase::getInfoParaCreacionClase(){ return infoParaCreacionClase;};

void ControladorClase::setClaseAFinalizar(int c){ this->claseAFinalizar = c;};
int ControladorClase::getClaseAFinalizar(){ return claseAFinalizar};

//inicio de clase
void ControladorClase::iniciarSesion(string e, string p){
  this->setPasswordUserActual(p);
  this->setEmailUserActual(e);
};
set<DtAsignatura> ControladorClase::consultarAsignaturasDocente();
DtInfoClase ControladorClase::infoDocente(string);
void ControladorClase::iniciarClase(string,string,DtFecha);
set<DtEstudiante> ControladorClase::consultarInscriptos();
void ControladorClase::agregarHabilitado(string);
DtInfoClase ControladorClase::desplegarInfoClase();
void ControladorClase::confirmarInicio();
void ControladorClase::cancelarInicio();

string ControladorClase::generarCodigo();
string ControladorClase::generarUrl(clase);
DtFecha ControladorClase::generarFecha();
set<DtClase> ControladorClase::consultarClasesEnVivo();
DtClase ControladorClase::finalizarClase(string);
void ControladorClase::confirmarFin();
void ControladorClase::cancelarFin();
set<DtAsignatura> ControladorClase::consultarAsigIns();
set<DtClase> ControladorClase::consultarClasesDiferido(string);
DtClase ControladorClase::AsistirClaseDiferido(string);
set<DtMensaje> ControladorClase::confirmarAsistencia();
void ControladorClase::cancelarAsistencia();
set<DtInfoClase> ControladorClase::desplegarInfoClases(string);
void ControladorClase::confirmarEnvio();

ControladorClase::~ControladorClase()
