#include "../include/dtUsuario.h"

void dtUsuario::setNombre(string n){ this->nombre = n;};
string dtUsuario::getNombre(){ return nombre;};

void dtUsuario::setEmail(string e){ this->email = e;};
string dtUsuario::getEmail(){ return email;};

void dtUsuario::setPassword(string p){  this->password = p;};
string dtUsuario::getPassword(){ return password;};

void dtUsuario::setImagen(string i){  this->imagen = i;};
string dtUsuario::getImagen(){  return imagen;};

void dtUsuario::setModoSus(int m){  this->modoSus = m;};
int dtUsuario::getModoSus(){  return modoSus;};
