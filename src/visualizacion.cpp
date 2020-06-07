#include "../include/headers/visualizacion.h"

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
DtFecha Visualizacion::getFechaInicioVis(){
  return FechaInicioVis;
};
DtFecha Visualizacion::getFechaFinVis(){
  return FechaFinVis;
};
DtFecha Visualizacion::generarFecha(){
  return
};
Visualizacion::~Visualizacion(){

};
