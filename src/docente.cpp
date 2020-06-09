#include "../include/headers/docente.h"

Docente::Docente(){
  //se crean las colecciones vacias ?
};
string Docente::getInstituto(){
  return instituto;
};
void Docente::setInstituto(string ins){
  this->instituto = ins;
};
bool Docente::esDocenteDe(string codigoAsig){
  string aux;
  bool res = false;
  foreach rol in roles do{//notacion inventada
    aux = rol.getCodigoAsig();
    if aux==codigoAsig
      res = true;
  };
  return res;
};
Rol Docente::nuevoRol(Asignatura asig){
  Rol *rolNuevo = new Rol(this, &asig);//paso puntero a doc implicito y direcicon de asig? funciona?//falta el tipo del rol
  add(rolNuevo,this.roles);//agregago el rol nuevo a la coleccion
  //asig.agregarRol(rolNuevo);
};
set(DtAsignatura) Docente::getInfo(){
  //new set(DtAsignatura)
  foreach rol in roles do{//notacion inventada
    string c = rol.getAsig().getCodigo();
    string n = rol.getAsig().getNombre();
    bool t = rol.getAsig().getTeorico();
    bool p = rol.getAsig().getPractico();
    bool m = rol.getAsig().getMonitoreo();
    //armar dt
    //agregarlo al set
  }
  //return set;
};
void Docente::agregarClaseNueva(Clase c){
  add(c,clasesCreadas);
};

set(DtClase) Docente::clasesATerminar(){
  //new set(DtClase)
  foreach clase in clasesCreadas do{
    if clase.getFechaFin() == fechaNula{ //definir esta constante y sobrecargar == para dtFecha
      string n = clase.getNombre();
      string c = clase.getCodigo();
      dtFecha fi = clase.getFechaInicio();
      tipoClase t = clase.getTipo();
      //armar dt
      //agregarlo al set
    }
  }
  //return set;
};

void Docente::desvincularDoc(rol){
  remove(rol,roles);
};

Docente::~Docente(){

};
