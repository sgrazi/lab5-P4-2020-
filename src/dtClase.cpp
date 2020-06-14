#include "../include/dtClase.h"

dtClase::dtClase(){};

void dtClase::setNombre(string n){ this->nombre = n;};
string dtClase::getNombre(){ return nombre;};

void dtClase::setCodigo(int c){ this->codigo = c;};
int dtClase::getCodigo(){ return codigo;};

void dtClase::setUrl(string u){ this->url = u;};
string dtClase::getUrl(){ return url;};

void dtClase::setFechaInicio(dtFecha f){ this->fechaInicio = f;};
dtFecha dtClase::getFechaInicio(){ return fechaInicio;};

void dtClase::setFechaFin(dtFecha f){ this->fechaFin = f;};
dtFecha dtClase::getFechaFin(){ return fechaFin;};

void dtClase::setTipo(tipoClase t){ this->tipo = t;};
tipoClase dtClase::getTipo(){ return tipo;};

void dtClase::setCreador(string c){ this->creador = c;};
string dtClase::getCreador(){ return creador;};

void dtClase::setAsig(int a){ this->codigoAsig = a;};
int dtClase::getAsig(){ return codigoAsig;};

dtClase::~dtClase(){};
