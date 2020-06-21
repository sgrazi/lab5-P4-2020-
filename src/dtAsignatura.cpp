#include "../include/dtAsignatura.h"

dtAsignatura::dtAsignatura(){};
void dtAsignatura::setCodigo(string c){  this->codigo = c;};
string dtAsignatura::getCodigo() const {  return codigo;};

void dtAsignatura::setNombre(string n){ this->nombre = n;};
string dtAsignatura::getNombre() const { return nombre;};

void dtAsignatura::setTeorico(bool b){  this->teorico = b;};
bool dtAsignatura::getTeorico() const {  return teorico;};

void dtAsignatura::setPractico(bool b){ this->practico = b;};
bool dtAsignatura::getPractico() const { return practico;};

void dtAsignatura::setMonitoreo(bool b){  this->monitoreo = b;};
bool dtAsignatura::getMonitoreo() const {  return monitoreo;};

dtAsignatura::~dtAsignatura(){};

bool dtAsignatura::operator<(const dtAsignatura &right)const{ //si colecciones se implementan con set esto es necesario
  return (this->codigo < right.getCodigo());
};
