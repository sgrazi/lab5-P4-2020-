#include "../include/docente.h"
#include "../include/clase.h"
#include "../include/dtAsignatura.h"
#include "../include/dtClase.h"
#include "../include/asignatura.h"
#include "../include/rol.h"
#include "../include/dtFecha.h"

const fechaNula dtFecha(0,0,0,0,0,0);

Docente::Docente(){
  map<int,Rol*>* a = new map<int,Rol*>;
  this->asignaturas = a;
  map<int,Clase*>* c = new map<int,Clase*>;
  this->clases = c;
};
string Docente::getInstituto(){
  return instituto;
};
void Docente::setInstituto(string ins){
  this->instituto = ins;
};

map<int,Rol*>* Docente::getAsignaturas(){ return asignaturas;};
map<int,Clase*>* Docente::getClases(){ return clases;};

bool Docente::esDocenteDe(int codigoAsig){
  int aux;
  bool res = false;
  map<int,Rol*> :: iterator it;
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
  this->asignaturas->insert(pair<int,Rol*> (asig->getCodigo(),rolNuevo));//agregago el rol nuevo a la coleccion
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
  clases->insert(pair<int,Clase*> (c->getCodigo(),c));
};

set<dtClase> Docente::clasesATerminar(){
  new set<dtClase> set;
  for(auto it = clases.begin(); it!=clases.end(); ++it){
    if(it->second->getFechaFin() == fechaNula){ //definir esta constante y sobrecargar == para dtFecha
      dtClase* dt = new dtClase();
      dt->setNombre(it->second->getNombre());
      dt->setCodigo(it->second->getCodigo());
      dt->setFechaInicio(it->second->getFechaInicio());
      dt->setFechaFin(fechaNula);
      dt->setTipo(it->second->getTipo());
      dt->setUrl(it->second->getUlr());
      dt->setCreador(this->getEmail());
      dt->setAsig(it->second->getCodigoAsig());
      set.insert(*dt);
    }
  }
  return set;
};

void Docente::desvincularDoc(Rol){/*
  remove(rol,asignaturas);*/
};

Docente::~Docente(){

};
