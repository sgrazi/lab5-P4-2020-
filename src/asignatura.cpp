#include "../include/asignatura.h"
#include "../include/estudiante.h"
#include "../include/dtFecha.h"

const dtFecha fechaNula(0,0,0,0,0,0)

Asignatura::Asignatura(){//inicializo las colecciones vacias
  map<string,Estudiante*>* a = new map<string,Estudiante*>;
  this->inscriptos = a;
  map<int,Clase*>* b = new map<int,Clase*>;
  this->clases = b;
  map<string,Rol*>* c = new map<string,Rol*>;
  this->docentes = c;
};

void Asignatura::setCodigo(int c){ this->codigo = c;};
int Asignatura::getCodigo() const{ return codigo;};

void Asignatura::setNombre(string n){ this->nombre = n;};
string Asignatura::getNombre()const{ return nombre;};

void Asignatura::setTeorico(bool t){  this->teorico = t;};
bool Asignatura::getTeorico() const{ return teorico;};

void Asignatura::setPractico(bool p){ this->practico = p;};
bool Asignatura::getPractico() const{ return practico;};

void Asignatura::setMonitoreo(bool m){ this->monitoreo = m;};
bool Asignatura::getMonitoreo() const{  return monitoreo;};

Asignatura::~Asignatura(){};

void Asignatura::agregarRol(Rol* rol){
  this->docentes->insert(pair<string,Rol*>(rol->getDoc()->getEmail(),rol));
};

map<string,Estudiante*>* Asignatura::getInscriptos(){
  return inscriptos;
};
map<int,Clase*>* Asignatura::getClases(){
  return clases;
};

map<string,Rol*>* Asignatura::getDocentes(){
  return docentes;
};

void Asignatura::agregarInscripto(Estudiante* est){
  inscriptos->insert(pair<string,Estudiante*> (est->getEmail(),est));
};

void Asignatura::agregarClaseNueva(Clase* c){
  clases->insert(pair<int,Clase*> (c->getCodigo(),c));
};

set<dtClase> Asignatura::getClasesDiferido(){
  set<dtClase> nuevo;
  for(auto itCla = clases->begin(); itCla!=clases->end();++itCla){
    if(itCla->second->getFechaFin() != fechaNula){
      dtClase *d = new dtClase();
      d->setCodigo(itAsig->second->getCodigo());
      d->setNombre(itAsig->second->getNombre());
      d->setUrl(itAsig->second->getUrl());
      d->setFechaInicio(itAsig->second->getFechaInicio());
      d->setFechaFin(itAsig->second->getFechaFin());
      //d->setCreador(itAsig->second->);
      d->setCodigoAsig(this->getCodigo());
      d->setTipo(itAsig->second->getTipo());
      nuevo.insert(*d);
    }
  }
  return nuevo;
};
