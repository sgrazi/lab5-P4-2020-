#include "../include/visualizacion.h"

Visualizacion::Visualizacion(){

};
void Visualizacion::setEnVivo(bool b){
  this->enVivo = b;
};
void Visualizacion::setFechaInicioVis(DtFecha fecha){
  this->FechaInicioVis = fecha;
};
void Visualizacion::setFechaFinVis(DtFecha fecha){
  this->FechaFinVis = fecha;
};
bool Visualizacion::getEnVivo(){
  return enVivo
};
dtFecha Visualizacion::getFechaInicioVis(){
  return FechaInicioVis;
};
dtFecha Visualizacion::getFechaFinVis(){
  return FechaFinVis;
};
dtFecha Visualizacion::generarFecha(){
  return
};
Visualizacion::~Visualizacion(){

};
