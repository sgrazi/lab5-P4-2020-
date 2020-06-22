#include "../include/usuario.h"
#include "../include/estrategiaNotifs.h"
#include "../include/dtNotificacion.h"
#include "../include/dtMensaje.h"
#include "../include/mensaje.h"
#include "../include/usrCla.h"

#include <set>
#include <iostream>

Usuario::Usuario(){
  this->modoSus = 0;
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
  this->modoSus = 3;//el modo siempre va a ser 3
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
set<int> Usuario::getIdMensajes(){
  return idMensajes;
}
void Usuario::setModoSus(int a){ this->modoSus = a;};
int Usuario::getModoSus(){ return modoSus;};

void Usuario::asistir(UsrCla* c){
  this->clasesParticipa.insert(c);
};
set<UsrCla*> Usuario::getClasesParticipa(){
  return clasesParticipa;
};

bool Usuario::aplicaNotificacion(dtMensaje d){
  bool res = false;
  if(modoSus!=0)
    res =(aplica->aplicaNotificacion(d));
  return res;
};

void Usuario::agregarMensaje(Mensaje* m){
  this->mensajes.insert(m);
  this->idMensajes.insert(m->getId());
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

void Usuario::borrarNotifs(string cc){
  int i=0;
  int size = notificaciones.size();
  for(auto it = notificaciones.begin();i<size;++it){
    if((*it)->getCodigoClase()==cc){
      notificaciones.erase((*it));
      delete (*it);
    }
    i++;
  }
};
