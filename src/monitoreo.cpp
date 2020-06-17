#include "../include/monitoreo.h"

void Monitoreo::setNombre(string nom){this->setNombre(nom);};

Monitoreo::Monitoreo(){
  this->setTipo(monitoreo); //invariable, una clase de tipo monitoreo tiene en el atributo "tipo" el valor "monitoreo", se otroga este valor cuando se la crea, es correcto esto?
};
Monitoreo::~Monitoreo(){

};
