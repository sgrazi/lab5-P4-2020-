#include "../include/clase.h"

Clase::Clase(){

};

void Clase::setNombre(string nombre){
  this->nombre = nombre;
};
void Clase::setCodigo(int codigo){
  this->codigo = codigo;
};
void Clase::setUrl(string url){
  this->url = url;
};
void Clase::setFechaInicio(dtFecha fecha){
  this->fechaInicio = fecha;
};
void Clase::setFechaFin(dtFecha fecha){
  this->fechaFin = fecha;
};
void Clase::setCreador(Docente* d){
  this->creador = d;
};
void Clase::setAsig(Asignatura* a){
  this->asig = a;
};
void Clase::setTipo(tipoClase t){
  this->tipo = t;
};
tipoClase Clase::getTipo(){
  return tipo;
};
string Clase::getNombre(){
  return nombre;
};
int Clase::getCodigo(){
  return codigo;
};
string Clase::getUrl(){
  return url;
};
dtFecha Clase::getFechaInicio(){
  return fechaInicio;
};
dtFecha Clase::getFechaFin(){
  return fechaFin;
};
void Clase::visualizar(Estudiante* e){/*
  //puse las funciones member find y add como si existieran, no vi nada de la implementacion de coleccion que nos dieron
  bool existe = estParticipantes.member(email);
  if existe
    Estudiante *repro = find(email);
  else
    EstCla *repro = new EstCla();
    estParticipantes.add(repro);*/
};


Clase::~Clase(){

};
