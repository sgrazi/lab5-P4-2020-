#include "../include/reloj.h"
#include <iostream>

Reloj* Reloj::instancia = NULL;

Reloj::Reloj(){};
//Reloj Reloj::Reloj(int anio,int mes,int dia,int hora,int min):anio(anio),mes(mes),dia(dia),hora(hora),min(min){};
void Reloj::setAnioSistema(int anio){this->anio=anio;};
void Reloj::setMesSistema(int mes){this->mes=mes;};
void Reloj::setDiaSistema(int dia){this->dia=dia;};
void Reloj::setHoraSistema(int hora){this->hora=hora;};
void Reloj::setMinSistema(int min){this->min=min;};
void Reloj::setFechaSistema(int anio,int mes,int dia,int hora,int min){
  setAnioSistema(anio);
  setMesSistema(mes);
  setDiaSistema(dia);
  setHoraSistema(hora);
  setMinSistema(min);
};
int Reloj::getAnioSistema(){return anio;};
int Reloj::getMesSistema(){return mes;};
int Reloj::getDiaSistema(){return dia;};
int Reloj::getHoraSistema(){return hora;};
int Reloj::getMinSistema(){return min;};
void getFechaSisema(){};
Reloj* Reloj::getInstancia() {
  if (instancia == NULL)
    instancia = new Reloj();
  return instancia;
};
