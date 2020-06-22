#include "../include/clase.h"
#include "../include/asignatura.h"
#include "../include/visualizacion.h"
#include "../include/usrCla.h"
Clase::Clase(){

};
void Clase::auxiliar(){};

void Clase::setNombre(string nombre){
  this->nombre = nombre;
};
void Clase::setCodigo(string codigo){
  this->codigo = codigo;
};
void Clase::setUrl(string url){
  this->url = url;
};
void Clase::setFechaInicio(dtFecha fecha){
  this->fechaInicio = fecha;
};
void Clase::setFechaFin(dtFecha fecha){
  this->fechaFin = fecha;
};
void Clase::setCreador(Docente* d){
  this->creador = d;
};
void Clase::setAsig(Asignatura* a){
  this->asig = a;
};
void Clase::setTipo(tipoClase t){
  this->tipo = t;
};
tipoClase Clase::getTipo(){
  return tipo;
};
string Clase::getNombre(){
  return nombre;
};
string Clase::getCodigo(){
  return codigo;
};
string Clase::getUrl(){
  return url;
};
dtFecha Clase::getFechaInicio(){
  return fechaInicio;
};
dtFecha Clase::getFechaFin(){
  return fechaFin;
};
set<Mensaje*> Clase::getMensajes(){
  return mensajes;
};
set<UsrCla*> Clase::getParticipantes(){
  return participantes;
};

string Clase::getEmailCreador(){
  return creador->getEmail();
};

string Clase::getCodigoAsig(){
  return asig->getCodigo();
};
void Clase::nuevaVis(UsrCla* c){//inserta el usrcla
  participantes.insert(c);
};

void Clase::agregarMensaje(Mensaje* m){
  this->mensajes.insert(m);
};

/*set<Visualizacion*> getVis(){
  set<Visualizacion*> nuevo;
  for(auto it = participantes.begin(); it!=participantes.end(); ++it){//para cada usrcla en la clase
    set<Visualizacion*> visualizacionesUsuario = (*it)->getVis();
    for(auto it2 = visualizacionesUsuario.begin(); it2!=visualizacionesUsuario.end();it2++){//para cada visualizacion de ese usrcla
      nuevo.insert(*it2);
    }
  }
  return nuevo;
};*/

void Clase::visualizar(Estudiante* e){/*
  //puse las funciones member find y add como si existieran, no vi nada de la implementacion de coleccion que nos dieron
  bool existe = estParticipantes.member(email);
  if existe
    Estudiante *repro = find(email);
  else
    EstCla *repro = new EstCla();
    estParticipantes.add(repro);*/
};


Clase::~Clase(){
  for(auto itmsj =this->mensajes.begin(); itmsj!=this->mensajes.end();++itmsj){
    auto itmsj2=itmsj;
    delete *itmsj2;
  }
  for(auto itestcla =this->participantes.begin(); itestcla!=this->participantes.end();++itestcla){
    auto itestcla2 = itestcla;
    delete *itestcla2;
  }
};
