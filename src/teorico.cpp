#include "../include/teorico.h"

Teorico::Teorico(){
  this->setTipo(teorico); //invariable, una clase de tipo teorico tiene en el atributo "tipo" el valor "teorico", se otroga este valor cuando se la crea, es correcto esto?
};
void Teorico::setAsistentes(int a){
  this->asistentes = a;
};
int Teorico::getAsistentes(){
  return asistentes;
};
int Teorico::calcularAsistentes(){
  int i = 0;
  for(auto it = getParticipantes().begin(); it!=getParticipantes().end(); ++it){
    (*it)->marcarFin(this->getFechaFin());
    i++;
  }
  this->setAsistentes(i);
  return i;
};
Teorico::~Teorico(){

};
