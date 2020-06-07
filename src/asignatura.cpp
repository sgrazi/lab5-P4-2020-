#include "../include/headers/asignatura.h"

Asignatura::Asignatura();

void Asignatura::setCodigo(string c){ this->codigo = c;};
string Asignatura::getCodigo(){ return codigo;};

void Asignatura::setNombre(string n){ this->nombre = n};
string Asignatura::getNombre(){ return nombre;};

void Asignatura::setTeorico(bool t){  this->teorico = t};
bool Asignatura::getTeorico(){ return teorico;};

void Asignatura::setPractico(bool p){ this->practico = p};
bool Asignatura::getPractico(){ return practico;};

void Asignatura::setMonitoreo(bool m){ this->monitoreo = m};
bool Asignatura::getMonitoreo(){  return monitoreo;};

Asignatura::~Asignatura();
