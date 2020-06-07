#include "../include/headers/teorico.h"

Teorico::Teorico(){
  this->tipo = teorico; //invariable, una clase de tipo teorico tiene en el atributo "tipo" el valor "teorico", se otroga este valor cuando se la crea, es correcto esto?
};
void Teorico::setAsistentes(int a){
  this->asistentes = a;
};
int Teorico::getAsistentes(){
  return asistentes;
};
int Teorico::calcularAsistentes(){

};
Teorico::~Teorico(){

};
