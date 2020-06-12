#include "../include/dtUsuario.h"

void dtUsuario::setNombre(string n){ this->nombre = n;};
string dtUsuario::getNombre() const { return nombre;};

void dtUsuario::setEmail(string e){ this->email = e;};
string dtUsuario::getEmail() const { return email;};

void dtUsuario::setPassword(string p){  this->password = p;};
string dtUsuario::getPassword() const { return password;};

void dtUsuario::setImagen(string i){  this->imagen = i;};
string dtUsuario::getImagen() const {  return imagen;};

void dtUsuario::setModoSus(int m){  this->modoSus = m;};
int dtUsuario::getModoSus() const {  return modoSus;};
