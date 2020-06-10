#include "../include/headers/usuario.h"
#include "../include/headers/estrategiaNotifs.h"
#include "../include/dts/dtNotificacion.h"
#include <set>


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
void Usuario::setNotificaciones(){
  //crea el conjunto de notifiaciones vacio
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
set<DtNotificacion> Usuario::getNotificaciones(){
  return notificaciones;
};
EstrategiaNotifs* Usuario::getAplica(){
  return aplica;
};
void Usuario::notificar(DtNotificacion){

};
Usuario::~Usuario(){

};
