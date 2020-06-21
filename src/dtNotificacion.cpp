#include "../include/dtNotificacion.h"

dtNotificacion::dtNotificacion(){};

void dtNotificacion::setCodigoAsig(string c){ this->codigoAsig = c;};
string dtNotificacion::getCodigoAsig() const { return codigoAsig;};

void dtNotificacion::setCodigoClase(string c){ this->codigoClase = c;};
string dtNotificacion::getCodigoClase() const { return codigoClase;};

void dtNotificacion::setIdMensaje(int i){ this->idMensaje = i;};
int dtNotificacion::getIdMensaje() const { return idMensaje;};

void dtNotificacion::setContenidoMensaje(string c){ this->contenidoMensaje = c;};
string dtNotificacion::getContenidoMensaje() const { return contenidoMensaje;};

dtNotificacion::~dtNotificacion(){};
