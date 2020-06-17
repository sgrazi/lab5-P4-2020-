#include "../include/dtFecha.h"
#include <iostream>
#include <cmath>

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

int dtFecha::getAnio() const { return anio;};
int dtFecha::getMes() const { return mes;};
int dtFecha::getDia() const { return dia;};
int dtFecha::getHora() const { return hora;};
int dtFecha::getMinuto() const { return minuto;};
int dtFecha::getSegundo() const { return segundo;};

bool dtFecha::operator==(const dtFecha& fecha) const{
  return ((this->anio == fecha.getAnio())&&(this->mes == fecha.getMes())&&(this->dia == fecha.getDia())&&(this->hora == fecha.getHora())&&(this->minuto == fecha.getMinuto())&&(this->segundo == fecha.getSegundo()));
};

int dtFecha::operator-(const dtFecha& y){
  return (this->anio*365*24*60*60 - y.getAnio()*365*24*60*60) + round((this->mes*30.416*24*60*60)-(y.getMes()*30.416*24*60*60)) + (this->dia*24*60*60 - y.getDia()*24*60*60) + (this->hora*60*60 - y.getHora()*60*60) + (this->minuto*60 - y.getMinuto()*60) + (this->segundo - y.getSegundo());
};
