#include "../include/dtMensaje.h"

dtMensaje::dtMensaje(){};

void dtMensaje::setId(int a){ this->id = a;};
int dtMensaje::getId() const { return id;};

void dtMensaje::setContenido(string a){ this->contenido = a;};
string dtMensaje::getContenido() const { return contenido;};

void dtMensaje::setFecha(dtFecha f){ this->fecha = f;};
dtFecha dtMensaje::getFecha() const { return fecha;};

void dtMensaje::setEnRespuestaA(int a){ this->enRespuestaA = a;};
int dtMensaje::getEnRespuestaA() const { return enRespuestaA;};

void dtMensaje::setClase(int a){ this->clase = a;};
int dtMensaje::getClase() const { return clase;};

void dtMensaje::setAsignatura(int c){ this->asignatura = c;}
int dtMensaje::getAsignatura() const {  return asignatura;};

dtMensaje::~dtMensaje(){};

bool dtMensaje::operator<(const dtMensaje &right){
  return (this->id < right.getId());
};
