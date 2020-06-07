#include "../include/headers/mensaje.h"

Mensaje::Mensaje(){

};
void Mensaje::setId(string id){
  this->id = id;
};
void Mensaje::setContenido(string cont){
  this->contenido = cont;
};
void Mensaje::setFecha(DtFecha fecha){
  this->fecha = fecha;
};
void Mensaje::setEnRespuestaA(Mensaje *ms){
  this->enRespuestaA = ms
};
string Mensaje::getId(){
  return id;
};
string Mensaje::getContenido(){
  return contenido;
};
DtFecha Mensaje::getFecha(){
  return fecha;
};
Mensaje* Mensaje::getEnRespuestaA(){
  return enRespuestaA;
};
Mensaje::~Mensaje(){

};
