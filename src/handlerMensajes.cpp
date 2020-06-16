#include "../include/handlerMensajes.h"
#include "../include/usuario.h"
#include "../include/mensaje.h"
#include "../include/clase.h"
#include "../include/dtMensaje.h"
#include <iostream>

HandlerMensajes::HandlerMensajes(){
  map<string,Usuario*>* a = new map<string,Usuario*>;
  this->observers = a;
};

void HandlerMensajes::setColMens(map<int,Mensaje*>* c){ this->coleccionGlobalMensajes = c;};
void HandlerMensajes::setColCla(map<int,Clase*>* c){ this->coleccionGlobalClases = c;};

Mensaje* HandlerMensajes::agregarMensaje(int codigo, bool esRespuesta, int idRes, string contenidoMensaje, dtFecha fecha, int codigoClase){ //cual es el tipo de retorno? en el dcd no estaba, puse void

  dtMensaje *dt = new dtMensaje();//creo el dtMensaje para pasar a las estrategias
  dt->setId(codigo);
  if(esRespuesta)
    dt->setEnRespuestaA(idRes);
  else
    dt->setEnRespuestaA(-1);
  dt->setContenido(contenidoMensaje);
  dt->setFecha(fecha);
  dt->setClase(codigoClase);
  dt->setAsignatura(this->coleccionGlobalClases->find(codigoClase)->second->getCodigoAsig());

  Mensaje* nuevo = new Mensaje();//creo el mensaje nuevo
  nuevo->setId(codigo);
  nuevo->setFecha(fecha);
  nuevo->setContenido(contenidoMensaje);
  if(esRespuesta)
    nuevo->setEnRespuestaA(coleccionGlobalMensajes->find(idRes)->second);
  else
    nuevo->setEnRespuestaA(NULL);
  nuevo->setClase(coleccionGlobalClases->find(codigoClase)->second);

  coleccionGlobalMensajes->insert(pair<int,Mensaje*>(codigo,nuevo));//agrego el mensaje a la coleccion global

  for(auto itObs = observers->begin(); itObs!=observers->end(); ++itObs){//notifico a los observers
    bool aplica = itObs->second->aplicaNotificacion(*dt);
    if(aplica)
      itObs->second->notificar(*dt);
  }

  delete dt;

  return nuevo;
};

void HandlerMensajes::agregarObs(Usuario*){

};
void HandlerMensajes::eliminarObs(Usuario*){

};
HandlerMensajes::~HandlerMensajes(){

};
