#include "../include/dtFecha.h"

dtFecha::dtFecha(){

};
void dtFecha::setAnio(int a){
  this->anio = a;
};
void dtFecha::setMes(int m){
  this->mes = m;
};
void dtFecha::setDia(int d){
  this->dia = d;
};
void dtFecha::setHora(int h){
  this->hora = h;
};
void dtFecha::setMinuto(int m){
  this->minuto = m;
};
void dtFecha::setSegundo(int s){
  this->segundo = s;
};
dtFecha dtFecha::getFecha(){
  return *this;
};
dtFecha::~dtFecha(){};
