#include "../include/estudiante.h"

Estudiante::Estudiante(){

};
void Estudiante::setCI(string ci){
  this->ci = ci;
};
string Estudiante::getCI(){
  return ci;
};
void Estudiante::desinscribir(string codigo){/*//inventado
  Asignatura *asig = find(codigo,ColeccionGlobalAsignaturas);
  remove(asig,asignaturas);*/
};
Estudiante::~Estudiante(){

};
