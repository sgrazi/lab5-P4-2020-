#include "../include/visualizacion.h"

Visualizacion::Visualizacion(){

};
void Visualizacion::setEnVivo(bool b){
  this->enVivo = b;
};
void Visualizacion::setFechaInicioVis(dtFecha fecha){
  this->fechaInicioVis = fecha;
};
void Visualizacion::setFechaFinVis(dtFecha fecha){
  this->fechaFinVis = fecha;
};
bool Visualizacion::getEnVivo(){
  return enVivo;
};
dtFecha Visualizacion::getFechaInicioVis(){
  return fechaInicioVis;
};
dtFecha Visualizacion::getFechaFinVis(){
  return fechaFinVis;
};
void Visualizacion::setUsrCla(UsrCla* c){
  this->usrcla = c;
};
UsrCla* Visualizacion::getUsrCla(){
  return usrcla;
};
dtFecha Visualizacion::generarFecha(){ //TERMINAR, PLACEHOLDER
  return dtFecha(1,1,1,1,1,1);
};
Visualizacion::~Visualizacion(){

};
