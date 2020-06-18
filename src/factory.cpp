#include "../include/factory.h"
#include "../include/controladorAsignatura.h"
#include "../include/controladorClase.h"
#include "../include/controladorUsuario.h"
#include <iostream>

Factory* Factory::instancia = NULL;

Factory::Factory(){};
Factory* Factory::getInstancia() {
  if (instancia == NULL)
    instancia = new Factory();
  return instancia;
};
IControladorClase* Factory::getIClase(){
  ControladorClase *cc = ControladorClase::getInstancia();
  return cc;
};
IControladorAsignatura* Factory::getIAsignatura(){
  ControladorAsignatura *ca = ControladorAsignatura::getInstancia();
  return ca;
};
IControladorUsuario* Factory::getIUsuario(){
  ControladorUsuario *cu = ControladorUsuario::getInstancia();
  return cu;
};
Factory::~Factory(){};
