#include "../include/usuario.h"
#include "../include/estrategiaNotifs.h"
#include "../include/dtNotificacion.h"
#include "../include/dtMensaje.h"
#include "../include/mensaje.h"
#include "../include/usrCla.h"

#include <set>
#include <iostream>

Usuario::Usuario(){

};
void Usuario::setNombre(string nombre){
  this->nombre = nombre;
};
void Usuario::setEmail(string email){
  this->email = email;
};
void Usuario::setPassword(string pass){
  this->password = pass;
};
void Usuario::setImagen(string imagen){
  this->imagen = imagen;
};

void Usuario::setAplica(EstrategiaNotifs* e){
  this->aplica = e;
};
string Usuario::getNombre(){
  return nombre;
};
string Usuario::getEmail(){
  return email;
};
string Usuario::getPassword(){
  return password;
};
string Usuario::getImagen(){
  return imagen;
};
set<dtNotificacion*> Usuario::getNotificaciones(){
  return notificaciones;
};
EstrategiaNotifs* Usuario::getAplica(){
  return aplica;
};
set<Mensaje*> Usuario::getMensajes(){
  return mensajes;
};

void Usuario::setModoSus(int a){ this->modoSus = a;};
int Usuario::getModoSus(){ return modoSus;};

void Usuario::asistir(UsrCla* c){
  this->clasesParticipa.insert(c);
};
set<UsrCla*> Usuario::getClasesParticipa(){
  return clasesParticipa;
};

bool Usuario::aplicaNotificacion(dtMensaje d){
  return (aplica->aplicaNotificacion(d));
};

void Usuario::agregarMensaje(Mensaje* m){
  this->mensajes.insert(m);
};

void Usuario::notificar(dtMensaje d){
  dtNotificacion* dt = new dtNotificacion();
  dt->setCodigoAsig(d.getAsignatura());
  dt->setCodigoClase(d.getClase());
  dt->setIdMensaje(d.getId());
  dt->setContenidoMensaje(d.getContenido());
  this->notificaciones.insert(dt);
};
Usuario::~Usuario(){

};
