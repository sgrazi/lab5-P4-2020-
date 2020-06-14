#include "../include/dtInfoClase.h"
#include "../include/dtFecha.h"
#include "../include/dtEstudiante.h"

void setCodigo(int c){  this->codigo = c;};
int getCodigo(){  return codigo;};

void setNombre(string n){ this->nombre = n;};
string getNombre(){ return nombre;};

void setUrl(string u){  this->url = u;};
string getUrl(){ return url;};

void setFechaInicio(dtFecha fi){ this->fechaInicio = fi;};
dtFecha getFechaInicio(){ return fechaInicio;};

void setFechaFin(dtFecha ff){ this->fechaFin = ff;};
dtFecha getFechaFin(){  return fechaFin;};

void setTipo(tipoClase t){  this->tipo = t;};
tipoClase getTipo(){  return tipo;};

void setIniciadaPor(string i){  this->iniciadaPor = i;};
string getIniciadaPor(){  return iniciadaPor;};

void setAsistentes(int a){  this->asistentes = a;};
int getAsistentes(){  return asistentes;};
