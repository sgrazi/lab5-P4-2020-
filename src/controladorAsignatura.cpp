#include "../include/controladorAsignatura.h"
#include "../include/dtAsignatura.h"

#include <string>

ControladorAsignatura::ControladorAsignatura(){};

void ControladorAsignatura::setEmailDocente(string e){  this->emailDocente = e;};
string ControladorAsignatura::getEmailDocente(){  return emailDocente;};

void ControladorAsignatura::setCodigoAsig(string c){  this->codigoAsig = c;};
string ControladorAsignatura::getCodigoAsig(){ return codigoAsig;};

void ControladorAsignatura::setRolDoc(tipoClase r){ this->rolDoc = r;};
tipoClase ControladorAsignatura::getRolDoc(){return rolDoc;};

void ControladorAsignatura::setAsigAEliminar(int a){ this->asigAEliminar = a;};
int ControladorAsignatura::getAsigAEliminar(){ return asigAEliminar;};

set<dtAsignatura> ControladorAsignatura::consultarAsignaturas(){
  set<dtAsignatura> nuevo;
  map<int,Asignatura> :: iterator it;
  for (it=this->coleccionGlobalAsignaturas->begin(); it!=this->coleccionGlobalAsignaturas->end() ;++it){
    int i= it->first;
    Asignatura* a = it->second;
    dtAsignatura agregar = new dtAsignatura();
    agregar->setCodigo() = a->getCodigo();
    agregar->setNombre() = a->getNombre();
    agregar->setMonitoreo() = a->getMonitoreo();
    agregar->setPractico() =a->getPractico();
    agregar->setTeorico() =a->getTeorico();
    nuevo.insert(agregar);
  };
  return nuevo;
};

set<dtDocente> ControladorAsignatura::consultarDocentesLibres(string){

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
