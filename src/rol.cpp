#include "../include/rol.h"

class Docente;
class Asignatura;


Rol::Rol(){

};
Rol::Rol(Docente* d, Asignatura* a){
  this->doc = d;
  this->asig = a;
};

void Rol::setDicta(tipoClase t){ this->dicta = t;};
tipoClase Rol::getDicta(){  return dicta;};

void Rol::setDoc(Docente* d){
  this->doc = d;
};
void Rol::setAsig(Asignatura* a){
  this->asig = a;
};
Docente* Rol::getDoc(){
  return doc;
};
Asignatura* Rol::getAsig(){
  return asig;
};
int Rol::getCodigoAsig(){
  return asig->getCodigo();
};
Rol::~Rol(){

};
