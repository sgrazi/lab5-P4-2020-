#include "../include/asignatura.h"
#include "../include/estudiante.h"

Asignatura::Asignatura(){//inicializo las colecciones vacias
  map<string,Estudiante*>* a = new map<string,Estudiante*>;
  this->inscriptos = a;
  map<int,Clase*>* b = new map<int,Clase*>;
  this->clases = b;
  map<string,Docente*>* c = new map<string,Docente*>;
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
  this->docentes.insert(pair<string,Rol*>(rol->getDoc()->getEmail(),rol));
};

map<string,Estudiante*>* Asignatura::getInscriptos(){
  return inscriptos;
};
map<int,Clase*>* Asignatura::getClases(){
  return clases;
};

map<string,Docente*>* Asignatura::getDocentes(){
  return docentes;
};

void Asignatura::agregarInscripto(Estudiante* est){
  inscriptos->insert(pair<string,Estudiante*> (est->getEmail(),est));
};

void Asignatura::agregarClaseNueva(Clase* c){
  clases.insert(pair<int,Clase*> (c->getCodigo(),c));
};

/*bool operator< (const Asignatura &right) const{
return codigo < right.codigo;*/ //si colecciones se implementan con set esto es necesario
