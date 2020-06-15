#include "../include/dtNotificacion.h"

dtNotificacion::dtNotificacion(){};

void dtNotificacion::setCodigoAsig(int c){ this->codigoAsig = c;};
int dtNotificacion::getCodigoAsig(){ return codigoAsig;};

void dtNotificacion::setCodigoClase(int c){ this->codigoClase = c;};
int dtNotificacion::getCodigoClase(){ return codigoClase;};

void dtNotificacion::setIdMensaje(int i){ this->idMensaje = i;};
int dtNotificacion::getIdMensaje(){ return idMensaje;};

void dtNotificacion::setContenidoMensaje(string c){ this->contenidoMensaje = c;};
string dtNotificacion::getContenidoMensaje(){ return contenidoMensaje;};

dtNotificacion::~dtNotificacion(){};
