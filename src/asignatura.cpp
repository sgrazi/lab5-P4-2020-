#include "../include/headers/asignatura.h"

Asignatura::Asignatura(){};

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

/*bool operator< (const Asignatura &right) const{
return codigo < right.codigo;*/ //si colecciones se implementan con set esto es necesario
