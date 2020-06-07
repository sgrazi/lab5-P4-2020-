#include "../include/headers/ControladorAsignatura.h"

ControladorAsignatura::ControladorAsignatura();

void ControladorAsignatura::setEmailDocente(string e){  this->emailDocente = e;};
string ControladorAsignatura::getEmailDocente(){  return emailDocente;};

void ControladorAsignatura::setCodigoAsig(string c){  this->codigoAsig = c;};
string ControladorAsignatura::getCodigoAsig(){ return codigoAsig;};

void ControladorAsignatura::setRolDoc(tipoClase r){ this->rolDoc = r;};
tipoClase ControladorAsignatura::getRolDoc( return rolDoc;);

void ControladorAsignatura::setAsigAEliminar(string a){ this->asigAEliminar = a;};
string ControladorAsignatura::getAsigAEliminar(){ return asigAEliminar;};

Set(DtAsignatura) ControladorAsignatura::consultarAsignaturas(){
  //set(DtAsignatura) nuevo
  foreach asig in ColeccionGlobalAsignaturas do{
    string c = asig.getCodigo();
    string n = asig.getNombre();
    //armar dt
    //agregarlo al set nuevo
  }
  //return nuevo;
};
Set(DtDocente) ControladorAsignatura::consultarDocentesLibres(string){

};
void ControladorAsignatura::asignarDocente(string,string,tipoClase){

};
void ControladorAsignatura::confirmarAsignacion(){

};
void ControladorAsignatura::cancelarAsignacion(){

};
void ControladorAsignatura::eliminarAsignatura(string){

};
void ControladorAsignatura::confirmarElim(){

};
void ControladorAsignatura::cancelarElim(){

};

ControladorAsignatura::~ControladorAsignatura(){

};
