#include "../include/headers/usuario.h"

Usuario::Usuario(){

};
void Usuario::setNombre(string nombre){
  this->nombre = nombre;
};
void Usuario::setEmail(string email){
  this->email = email;
};
void Usuario::setPassword(string pass){
  this->pass = pass;
};
void Usuario::setImagen(string imagen){
  this->imagen = imagen;
};
void Usuario::setNotificaciones(){ //crea el conjunto de notifiaciones vacio
  this->notificaciones =
};
void Usuario::setAplica(EstrategiaNotifs){
  this->aplica =
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
set(DtNotifiacion) Usuario::getNotificaciones(){
  return notificaciones;
};
EstrategiaNotifs Usuario::getAplica(){
  return aplica;
};
void Usuario::notificar(DtNotifiacion){

};
Usuario::~Usuario(){

};
