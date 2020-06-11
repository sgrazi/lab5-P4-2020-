#include "../include/mensaje.h"

Mensaje::Mensaje(){

};
void Mensaje::setId(int id){
  this->id = id;
};
void Mensaje::setContenido(string cont){
  this->contenido = cont;
};
void Mensaje::setFecha(DtFecha fecha){
  this->fecha = fecha;
};
void Mensaje::setEnRespuestaA(Mensaje *ms){
  this->enRespuestaA = ms;
};
int Mensaje::getId(){
  return id;
};
string Mensaje::getContenido(){
  return contenido;
};
dtFecha Mensaje::getFecha(){
  return fecha;
};
Mensaje* Mensaje::getEnRespuestaA(){
  return enRespuestaA;
};
Mensaje::~Mensaje(){

};
/*bool operator<(const Mensaje &right){
  return id < right.id;
};*/ //si colecciones se implementan con set esto es necesario
