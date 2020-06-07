#include "../include/headers/rol.h"

Rol::Rol(){

};
Rol::Rol(Docente* d, Asignatura* a){
  this->doc = d;
  this->asig = a;
};
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
string Rol::getCodigoAsig(){
  return asig.getCodigo();
};
Rol::~Rol(){

};
