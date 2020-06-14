#include "../include/monitoreo.h"

Monitoreo::Monitoreo(){
  this->setTipo(monitoreo); //invariable, una clase de tipo monitoreo tiene en el atributo "tipo" el valor "monitoreo", se otroga este valor cuando se la crea, es correcto esto?
};
Monitoreo::~Monitoreo(){

};
void Monitoreo::setNombre(string n){
  this->setNombre(n);
};
