#include "../include/monitoreo.h"

void Monitoreo::auxiliar(){};
Monitoreo::Monitoreo(){
  this->setTipo(monitoreo); //invariable, una clase de tipo monitoreo tiene en el atributo "tipo" el valor "monitoreo", se otroga este valor cuando se la crea, es correcto esto?
  this->cantHabilitados = 0;
};
Monitoreo::~Monitoreo(){

};

void Monitoreo::agregarHabilitado(Estudiante* e){
  habilitados[cantHabilitados] = e;
  cantHabilitados++;
};
