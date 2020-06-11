#include "../include/dtAsignatura.h"

dtAsignatura::dtAsignatura(){};
void dtAsignatura::setCodigo(int c){  this->codigo = c;};
int dtAsignatura::getCodigo(){  return codigo;};

void dtAsignatura::setNombre(string n){ this->nombre = n;};
string dtAsignatura::getNombre(){ return nombre;};

void dtAsignatura::setTeorico(bool b){  this->teorico = b;};
bool dtAsignatura::getTeorico(){  return teorico;};

void dtAsignatura::setPractico(bool b){ this->practico = b;};
bool dtAsignatura::getPractico(){ return practico;};

void dtAsignatura::setMonitoreo(bool b){  this->monitoreo = b;};
bool dtAsignatura::getMonitoreo(){  return monitoreo};

dtAsignatura::~dtAsignatura(){};

bool dtAsignatura::operator<(const dtAsignatura &right){ //si colecciones se implementan con set esto es necesario
  return (this->codigo < right.getCodigo());
};
