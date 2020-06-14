#include "../include/docente.h"
#include "../include/clase.h"
#include "../include/dtAsignatura.h"
#include "../include/dtClase.h"
#include "../include/asignatura.h"
#include "../include/rol.h"

Docente::Docente(){
  //se crean las colecciones vacias ?
};
string Docente::getInstituto(){
  return instituto;
};
void Docente::setInstituto(string ins){
  this->instituto = ins;
};

map<int,Rol*> Docente::getAsignaturas(){ return asignaturas;};

bool Docente::esDocenteDe(int codigoAsig){
  int aux;
  bool res = false;
  map<int,Rol*> :: iterator it;
  for(it=asignaturas.begin(); it!=asignaturas.end(); it++){
    aux = it->first;
    if(aux==codigoAsig)
      res = true;
    if (res==true)
      break;
  };
  return res;
};
Rol Docente::nuevoRol(Asignatura *asig, tipoClase rolDoc){
  Rol *rolNuevo = new Rol(this, asig);
  rolNuevo->setDicta(rolDoc);
  this->asignaturas.insert(pair<int,Rol*> (asig->getCodigo(),rolNuevo));//agregago el rol nuevo a la coleccion
  asig->agregarRol(rolNuevo);
};
set<dtAsignatura> Docente::getInfo(){
  set<dtAsignatura> nuevo;
  for(auto it = this->asignaturas.begin(); it!=this->asignaturas.end(); ++it){//notacion inventada
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
void Docente::agregarClaseNueva(Clase *c){/*
  add(c,clasesCreadas);*/
};

set<dtClase> Docente::clasesATerminar(){
  /*//new set(DtClase)
  foreach clase in clasesCreadas do{
    if clase.getFechaFin() == fechaNula{ //definir esta constante y sobrecargar == para dtFecha
      string n = clase.getNombre();
      string c = clase.getCodigo();
      dtFecha fi = clase.getFechaInicio();
      tipoClase t = clase.getTipo();
      //armar dt
      //agregarlo al set
    }
  }*/
  //return set;
};

void Docente::desvincularDoc(Rol){/*
  remove(rol,asignaturas);*/
};

Docente::~Docente(){

};
