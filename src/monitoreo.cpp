#include "../include/monitoreo.h"

bool Monitoreo::estaHabilitado(string s){
  bool res=false;
  for(int i=0;i<cantHabilitados;i++){
    if(habilitados[i]->getEmail()==s)
      res=true;
  }
  return res;
};
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
