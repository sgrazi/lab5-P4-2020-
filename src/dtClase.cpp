#include "../include/dtClase.h"

dtClase::dtClase(){};

void dtClase::setNombre(string n){ this->nombre = n;};
string dtClase::getNombre() const { return nombre;};

void dtClase::setCodigo(int c){ this->codigo = c;};
int dtClase::getCodigo() const { return codigo;};

void dtClase::setUrl(string u){ this->url = u;};
string dtClase::getUrl() const { return url;};

void dtClase::setFechaInicio(dtFecha f){ this->fechaInicio = f;};
dtFecha dtClase::getFechaInicio() const { return fechaInicio;};

void dtClase::setFechaFin(dtFecha f){ this->fechaFin = f;};
dtFecha dtClase::getFechaFin() const { return fechaFin;};

void dtClase::setTipo(tipoClase t){ this->tipo = t;};
tipoClase dtClase::getTipo() const { return tipo;};

void dtClase::setCreador(string c){ this->creador = c;};
string dtClase::getCreador() const { return creador;};

void dtClase::setAsig(int a){ this->codigoAsig = a;};
int dtClase::getAsig() const { return codigoAsig;};

dtClase::~dtClase(){};

bool dtClase::operator<(const dtClase &right)const{
  return (codigo < right.getCodigo());
};
