#include "../include/dtFecha.h"

dtFecha::dtFecha(){

};
dtFecha::dtFecha(int a,int m,int d,int h,int mi,int s){
  this->anio = a;
  this->mes = m;
  this->dia = d;
  this->hora = h;
  this->minuto = mi;
  this->segundo = s;
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

int dtFecha::getAnio(){ return anio;};
int dtFecha::getMes(){ return mes;};
int dtFecha::getDia(){ return dia;};
int dtFecha::getHora(){ return hora;};
int dtFecha::getMinuto(){ return minuto;};
int dtFecha::getSegundo(){ return segundo;};

bool dtFecha::operator==(const dtFecha& fecha) const{
  return ((this->anio == fecha.getAnio())&&(this->mes == fecha.getMes())&&(this->dia == fecha.getDia())&&(this->hora == fecha.getHora())&&(this->minuto == fecha.getMinuto())&&(this->segundo = fecha.getSegundo()) )
};
