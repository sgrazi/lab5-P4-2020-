#include "../include/docente.h"
#include "../include/clase.h"
#include "../include/dtAsignatura.h"
#include "../include/dtClase.h"
#include "../include/asignatura.h"
#include "../include/rol.h"
#include "../include/dtFecha.h"

const dtFecha fechaNula(0,0,0,0,0,0);

Docente::Docente(){
  map<string,Rol*>* a = new map<string,Rol*>;
  this->asignaturas = a;
  map<string,Clase*>* c = new map<string,Clase*>;
  this->clases = c;
};
string Docente::getInstituto(){
  return instituto;
};
void Docente::setInstituto(string ins){
  this->instituto = ins;
};

map<string,Rol*>* Docente::getAsignaturas(){ return asignaturas;};
map<string,Clase*>* Docente::getClases(){ return clases;};

bool Docente::esDocenteDe(string codigoAsig){
  string aux;
  bool res = false;
  map<string,Rol*> :: iterator it;
  for(it=asignaturas->begin(); it!=asignaturas->end(); it++){
    aux = it->first;
    if(aux==codigoAsig)
      res = true;
    if (res==true)
      break;
  };
  return res;
};
Rol* Docente::nuevoRol(Asignatura *asig, tipoClase rolDoc){
  Rol *rolNuevo = new Rol(this, asig);
  rolNuevo->setDicta(rolDoc);
  this->asignaturas->insert(pair<string,Rol*> (asig->getCodigo(),rolNuevo));//agregago el rol nuevo a la coleccion
  //asig->agregarRol(rolNuevo); //de esto se encarga controlador Aasignatura en confirmarAsignacion
  return rolNuevo;
};
set<dtAsignatura> Docente::getInfo(){
  set<dtAsignatura> nuevo;
  for(auto it = this->asignaturas->begin(); it!=this->asignaturas->end(); ++it){//notacion inventada
    dtAsignatura *d = new dtAsignatura();
    d->setCodigo(it->second->getAsig()->getCodigo());
    d->setNombre(it->second->getAsig()->getNombre());
    d->setTeorico(it->second->getAsig()->getTeorico());
    d->setPractico(it->second->getAsig()->getPractico());
    d->setMonitoreo(it->second->getAsig()->getMonitoreo());
    nuevo.insert(*d);
  }
  return nuevo;
};
void Docente::agregarClaseNueva(Clase *c){
  clases->insert(pair<string,Clase*> (c->getCodigo(),c));
};

set<dtClase> Docente::clasesATerminar(){
  set<dtClase> nuevo;
  for(auto it = clases->begin(); it!=clases->end(); ++it){
    if(it->second->getFechaFin() == fechaNula && ((it->second->getFechaInicio().getAnio()<=relojSistema->getInstancia()->getAnioSistema()) && (it->second->getFechaInicio().getMes()<=relojSistema->getInstancia()->getMesSistema()) && (it->second->getFechaInicio().getDia()<=relojSistema->getInstancia()->getDiaSistema()) && (it->second->getFechaInicio().getHora()<=relojSistema->getInstancia()->getHoraSistema()) && (it->second->getFechaInicio().getMinuto()<=relojSistema->getInstancia()->getMinSistema()))){
      dtClase* dt = new dtClase();
      dt->setNombre(it->second->getNombre());
      dt->setCodigo(it->second->getCodigo());
      dt->setFechaInicio(it->second->getFechaInicio());
      dt->setFechaFin(fechaNula);
      dt->setTipo(it->second->getTipo());
      dt->setUrl(it->second->getUrl());
      dt->setCreador(this->getEmail());
      dt->setAsig(it->second->getCodigoAsig());
      nuevo.insert(*dt);
      delete dt;
    }
  }
  return nuevo;
};

void Docente::desvincularDoc(string codigoAsignatura){

  this->asignaturas->erase(codigoAsignatura);
};
void Docente::borrarClase(string cc){
  clases->erase(cc);
};
Docente::~Docente(){

};
