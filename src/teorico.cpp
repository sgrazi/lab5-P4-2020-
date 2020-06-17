#include "../include/teorico.h"
#include "../include/dtFecha.h"
#include "../include/visualizacion.h"

#include <iostream>

const dtFecha fechaNula(0,0,0,0,0,0);

Teorico::Teorico(){
  this->setTipo(teorico); //invariable, una clase de tipo teorico tiene en el atributo "tipo" el valor "teorico", se otroga este valor cuando se la crea, es correcto esto?
};

void Teorico::setNombre(string nom){this->setNombre(nom);};

void Teorico::setAsistentes(int a){
  this->asistentes = a;
};
int Teorico::getAsistentes(){
  return asistentes;
};
/* VIEJO
int Teorico::calcularAsistentes(){
  int i = 0;
  for(auto it = getParticipantes().begin(); it!=getParticipantes().end(); ++it){
    auto visualizaciones = (*it)->getVis().begin();//
    if((*visualizaciones)->getFechaInicioVis()==fechaNula)
      cout << "1";
    /*
    if((*visualizaciones)->getFechaFinVis() == fechaNula){ //la visualizacion mas reciente siempre esta al inicio
      (*it)->marcarFin(this->getFechaFin());//como es clase en vivo solo hay una visualizacion
      i++;
    }
  }
  this->setAsistentes(i);
  return i;
};*/
Teorico::~Teorico(){

};
