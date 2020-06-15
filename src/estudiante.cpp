#include "../include/estudiante.h"
#include "../include/asignatura.h"

Estudiante::Estudiante(){
  map<int,Asignatura*>* a = new map<int,Asignatura*>;
  this->asignaturas = a;
};
void Estudiante::setCI(string ci){
  this->ci = ci;
};
string Estudiante::getCI(){
  return ci;
};

set<dtAsignatura> Estudiante:: getInscripciones(){
  set<dtAsignatura> nuevo;
  map<int,Asignatura*>::iterator it;
  for (it=this->asignaturas->begin(); it!=this->asignaturas->end() ;++it){
    Asignatura* a = it->second;
    dtAsignatura* agregar = new dtAsignatura();
    agregar->setCodigo(a->getCodigo());
    agregar->setNombre(a->getNombre());
    agregar->setMonitoreo(a->getMonitoreo());
    agregar->setPractico(a->getPractico());
    agregar->setTeorico(a->getTeorico());
    nuevo.insert(*agregar);
  }
return nuevo;
};

void Estudiante::inscribir(Asignatura* a){
  asignaturas->insert(pair<int,Asignatura*> (a->getCodigo(),a));
};
void Estudiante::desinscribir(int codigo){/*//inventado
  Asignatura *asig = find(codigo,ColeccionGlobalAsignaturas);
  remove(asig,asignaturas);*/
};
map<int,Asignatura*>* Estudiante::getAsignaturas(){
  return asignaturas;
};
Estudiante::~Estudiante(){

};
