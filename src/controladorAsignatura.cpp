#include "../include/controladorAsignatura.h"
#include "../include/dtAsignatura.h"
#include "../include/dtDocente.h"

using namespace std;


ControladorAsignatura::ControladorAsignatura(){};

void ControladorAsignatura::setEmailDocente(string e){  this->emailDocente = e;};
string ControladorAsignatura::getEmailDocente(){  return emailDocente;};

void ControladorAsignatura::setNombreAsig(string n){  this->nombreAsig = n;};
string ControladorAsignatura::getNombreAsig(){ return nombreAsig;};

void ControladorAsignatura::setCodigoAsig(int c){  this->codigoAsig = c;};
int ControladorAsignatura::getCodigoAsig(){ return codigoAsig;};

void ControladorAsignatura::setAceptaTeo(bool b){  this->aceptaTeo = b;};
bool ControladorAsignatura::getAceptaTeo(){ return aceptaTeo;};

void ControladorAsignatura::setAceptaPra(bool b){  this->aceptaPra = b;};
bool ControladorAsignatura::getAceptaPra(){ return aceptaPra;};

void ControladorAsignatura::setAceptaMon(bool b){  this->aceptaMon = b;};
bool ControladorAsignatura::getAceptaMon(){ return aceptaMon;};

void ControladorAsignatura::setRolDoc(tipoClase r){ this->rolDoc = r;};
tipoClase ControladorAsignatura::getRolDoc(){return rolDoc;};

void ControladorAsignatura::setAsigAEliminar(int a){ this->asigAEliminar = a;};
int ControladorAsignatura::getAsigAEliminar(){ return asigAEliminar;};

void ControladorAsignatura::setColAsig(map<int,Asignatura*>* c){ this->coleccionGlobalAsignaturas = c;};
void ControladorAsignatura::setColDoc(map<string,Docente*>* c){ this->coleccionGlobalDocentes = c;};

void ControladorAsignatura::agregarAsignatura(string n, int c, bool t, bool p, bool m){
  this->setNombreAsig(n);
  this->setCodigoAsig(c);
  this->setAceptaTeo(t);
  this->setAceptaPra(p);
  this->setAceptaMon(m);
};

void ControladorAsignatura::confirmarAlta(){
  Asignatura *nueva = new Asignatura();
  nueva->setNombre(getNombreAsig());
  nueva->setCodigo(getCodigoAsig());
  nueva->setTeorico(getAceptaTeo());
  nueva->setPractico(getAceptaPra());
  nueva->setMonitoreo(getAceptaMon());
  this->coleccionGlobalAsignaturas->insert(pair<int,Asignatura*>(nueva->getCodigo(),nueva));
};

void ControladorAsignatura::cancelarAlta(){

};

set<dtAsignatura> ControladorAsignatura::consultarAsignaturas(){
  set<dtAsignatura> nuevo;
  map<int,Asignatura*> :: iterator it;
  for (it=coleccionGlobalAsignaturas->begin(); it!=coleccionGlobalAsignaturas->end() ;++it){
    Asignatura* a = it->second;
    dtAsignatura* agregar = new dtAsignatura();
    agregar->setCodigo(a->getCodigo());
    agregar->setNombre(a->getNombre());
    agregar->setMonitoreo(a->getMonitoreo());
    agregar->setPractico(a->getPractico());
    agregar->setTeorico(a->getTeorico());
    nuevo.insert(*agregar);
  };
  return nuevo;
};

map<string,dtDocente> ControladorAsignatura::consultarDocentesLibres(int codigo){
  map<string,dtDocente> nuevo;
  map<string,Docente*> :: iterator it;
  for (it=coleccionGlobalDocentes->begin(); it!=coleccionGlobalDocentes->end() ;++it){
    Docente* d = it->second;
    if(!(d->esDocenteDe(codigo))){
      dtDocente* agregar = new dtDocente();
      agregar->setNombre(d->getNombre());
      agregar->setEmail(d->getEmail());
      agregar->setPassword(d->getPassword());
      agregar->setImagen(d->getImagen());
      agregar->setInstituto(d->getInstituto());
      //agregar->setModoSus(d->getModoSus());
      nuevo.insert(pair<string, dtDocente>(d->getEmail(), *agregar));
    }
  };
  return nuevo;
};
void ControladorAsignatura::asignarDocente(string e, int c, tipoClase r){
  this->setEmailDocente(e);
  this->setCodigoAsig(c);
  this->setRolDoc(r);
};
void ControladorAsignatura::confirmarAsignacion(){
  auto doc = coleccionGlobalDocentes->find(emailDocente);
  auto asig = coleccionGlobalAsignaturas->find(codigoAsig);
  Rol* nuevo = doc->second->nuevoRol(asig->second,this->rolDoc);
  asig->second->agregarRol(nuevo);
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
