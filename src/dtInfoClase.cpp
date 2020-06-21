#include "../include/dtInfoClase.h"
#include "../include/dtFecha.h"
#include "../include/dtEstudiante.h"

void dtInfoClase::setCodigo(string c){  this->codigo = c;};
string dtInfoClase::getCodigo(){  return codigo;};

void dtInfoClase::setNombre(string n){ this->nombre = n;};
string dtInfoClase::getNombre(){ return nombre;};

void dtInfoClase::setUrl(string u){  this->url = u;};
string dtInfoClase::getUrl(){ return url;};

void dtInfoClase::setFechaInicio(dtFecha fi){ this->fechaInicio = fi;};
dtFecha dtInfoClase::getFechaInicio(){ return fechaInicio;};

void dtInfoClase::setFechaFin(dtFecha ff){ this->fechaFin = ff;};
dtFecha dtInfoClase::getFechaFin(){  return fechaFin;};

void dtInfoClase::setTipo(tipoClase t){  this->tipo = t;};
tipoClase dtInfoClase::getTipo(){  return tipo;};

void dtInfoClase::setIniciadaPor(string i){  this->iniciadaPor = i;};
string dtInfoClase::getIniciadaPor(){  return iniciadaPor;};

void dtInfoClase::setAsistentes(int a){  this->asistentes = a;};
int dtInfoClase::getAsistentes(){  return asistentes;};

void dtInfoClase::agregarHabilitado(string email){
  this->habilitados[cantHabilitados] = email;
  this->cantHabilitados++;
};
int dtInfoClase::getCantHabilitados(){
  return cantHabilitados;
};
array<string, 15> dtInfoClase::getHabilitados(){
  return habilitados;
};
