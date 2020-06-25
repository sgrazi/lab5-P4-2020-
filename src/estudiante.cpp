#include "../include/estudiante.h"
#include "../include/asignatura.h"

Estudiante::Estudiante(){
  map<string,Asignatura*>* a = new map<string,Asignatura*>;
  this->asignaturas = a;
  set<Clase*>* c = new set<Clase*>;
  this->asistiendo = c;
};
void Estudiante::setCI(string ci){
  this->ci = ci;
};
string Estudiante::getCI(){
  return ci;
};
void Estudiante::inscribir(Asignatura* a){
  asignaturas->insert(pair<string,Asignatura*> (a->getCodigo(),a));
};
void Estudiante::desinscribir(string codigo){
  asignaturas->erase(codigo);
};

map<string,Asignatura*>* Estudiante::getAsignaturas(){
  return asignaturas;
};
set<Clase*>* Estudiante::getAsistiendo(){
  return asistiendo;
};
void Estudiante::asistirClase(Clase* c){
  asistiendo->insert(c);
};
void Estudiante::dejarDeAsistir(Clase* c){
  asistiendo->erase(c);
};
Estudiante::~Estudiante(){

};

set<dtAsignatura> Estudiante::getAsignaturasInscripto(){
  set<dtAsignatura> nuevo;
  for(auto itAsig = asignaturas->begin(); itAsig!=asignaturas->end();++itAsig){
    dtAsignatura *d = new dtAsignatura();
    d->setCodigo(itAsig->second->getCodigo());
    d->setNombre(itAsig->second->getNombre());
    d->setTeorico(itAsig->second->getTeorico());
    d->setPractico(itAsig->second->getPractico());
    d->setMonitoreo(itAsig->second->getMonitoreo());
    nuevo.insert(*d);
  }
  return nuevo;
};

void Estudiante::borrarAsig(string ca){
  asignaturas->erase(ca);
};
