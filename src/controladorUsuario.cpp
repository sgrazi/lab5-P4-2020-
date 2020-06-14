#include "../include/controladorUsuario.h"
#include "../include/docente.h"
#include "../include/estudiante.h"
#include "../include/estrategiaModoSus1.h"
#include "../include/estrategiaModoSus2.h"
#include "../include/estrategiaModoSus3.h"
#include "../include/dtNotificacion.h"
#include "../include/asignatura.h"
#include "../include/dtAsignatura.h"

#include <iostream>

ControladorUsuario::ControladorUsuario(){
};

bool ControladorUsuario::getUserEsEst(){  return userEsEst;};
void ControladorUsuario::setUserEsEst(bool es){  this->userEsEst = es;};

string ControladorUsuario::getNombreUser(){  return nombreUser;};
void ControladorUsuario::setNombreUser(string nombre){  this->nombreUser = nombre;};

string ControladorUsuario::getPasswordUser(){  return contraseniaUser;};
void ControladorUsuario::setPasswordUser(string pass){  this->contraseniaUser = pass;};

string ControladorUsuario::getEmailUser(){  return emailUser;};
void ControladorUsuario::setEmailUser(string email){  this->emailUser = email;};

string ControladorUsuario::getUrlUser(){  return urlUser;};
void ControladorUsuario::setUrlUser(string url){  this->urlUser = url;};

string ControladorUsuario::getInstitutoDoc(){  return institutoDoc;};
void ControladorUsuario::setInstitutoDoc(string ins){  this->institutoDoc = ins;};

string ControladorUsuario::getCedulaEst(){  return cedulaEst;};
void ControladorUsuario::setCedulaEst(string ci){  this->cedulaEst = ci;};

string ControladorUsuario::getNombreUserActual(){  return nombreUserActual;};
void ControladorUsuario::setNombreUserActual(string nombre){  this->nombreUserActual = nombre;};

string ControladorUsuario::getEmailUserActual(){  return emailUserActual;};
void ControladorUsuario::setEmailUserActual(string email){  this->emailUserActual = email;};

int ControladorUsuario::getNuevoModoSus(){  return nuevoModoSus;};
void ControladorUsuario::setNuevoModoSus(int modo){  this->nuevoModoSus = modo;};

int ControladorUsuario::getAsignaturaAIns(){ return asignaturaAIns;};
void ControladorUsuario::setAsignaturaAIns(int a){ this->asignaturaAIns = a;};

void ControladorUsuario::setColEst(map<string,Estudiante*>* c){ this->coleccionGlobalEstudiantes = c;};
void ControladorUsuario::setColDoc(map<string,Docente*>* c){ this->coleccionGlobalDocentes = c;};
void ControladorUsuario::setColAsig(map<int,Asignatura*>* c){ this->coleccionGlobalAsignaturas = c;};

void ControladorUsuario::iniciarSesion(string email, string pass){
  //member(); buscar si las credenciales existen en la coleccion
  this->setEmailUserActual(email);
};

void ControladorUsuario::agregarEstudiante(string n, string c, string e, string u, string ci){
  setNombreUser(n);
  setPasswordUser(c);
  setEmailUser(e);
  setUrlUser(u);
  setCedulaEst(ci);

  setUserEsEst(true);
};

void ControladorUsuario::agregarDocente(string n, string c, string e, string u, string i){
  setNombreUser(n);
  setPasswordUser(c);
  setEmailUser(e);
  setUrlUser(u);
  setInstitutoDoc(i);

  setUserEsEst(false);
};

void ControladorUsuario::confirmarAlta(){
  if (userEsEst){
    Estudiante *nuevo = new Estudiante();
    nuevo->setNombre(getNombreUser());
    nuevo->setEmail(getEmailUser());
    nuevo->setPassword(getPasswordUser());
    nuevo->setImagen(getUrlUser());
    nuevo->setCI(getCedulaEst());
    this->coleccionGlobalEstudiantes->insert(pair<string,Estudiante*>(nuevo->getEmail(),nuevo));
    //coleccionGlobalEstudiantes[nuevo->getEmail()]=nuevo;

  }
  else{
    Docente *nuevo = new Docente();
    nuevo->setNombre(getNombreUser());
    nuevo->setEmail(getEmailUser());
    nuevo->setPassword(getPasswordUser());
    nuevo->setImagen(getUrlUser());
    nuevo->setInstituto(getInstitutoDoc());
    this->coleccionGlobalDocentes->insert(pair<string,Docente*>(nuevo->getEmail(),nuevo));
    //coleccionGlobalDocentes[nuevo->getEmail()]=nuevo;
  }
};

void ControladorUsuario::cancelarAlta(){
  //vacio
};

set<dtAsignatura> ControladorUsuario::consultarAsigNoIns(){
  auto itEst = this->coleccionGlobalEstudiantes->find(emailUserActual);//busco a mi usuario actual
  set<dtAsignatura> nuevo;
  //agrego TODAS las asignaturas a un set nuevo de dt
  for(auto itAsig = this->coleccionGlobalAsignaturas->begin(); itAsig!=this->coleccionGlobalAsignaturas->end();++itAsig){
    dtAsignatura* agregar = new dtAsignatura();
    agregar->setCodigo(itAsig->first);
    agregar->setNombre(itAsig->second->getNombre());
    agregar->setMonitoreo(itAsig->second->getMonitoreo());
    agregar->setPractico(itAsig->second->getPractico());
    agregar->setTeorico(itAsig->second->getTeorico());
    nuevo.insert(*agregar);
  }
  //para cada asig que ya estoy inscripto, la remuevo del set
  for(auto itAsig = itEst->second->getAsignaturas()->begin(); itAsig!=itEst->second->getAsignaturas()->end(); ++itAsig){
    auto it = nuevo.begin();
    for(it = nuevo.begin(); it!=nuevo.end(); ++it){
      if(it->getCodigo() == itAsig->first)
        break;
    }
    if(it!=nuevo.end()){
      nuevo.erase(it);
    }
  }
  return nuevo;
};

void ControladorUsuario::inscribir(int codigo){
  this->setAsignaturaAIns(codigo);
};

void ControladorUsuario::confirmarInscripcion(){
  auto itEst = this->coleccionGlobalEstudiantes->find(emailUserActual);//busco a mi usuario actual
  auto itAsig = this->coleccionGlobalAsignaturas->find(asignaturaAIns);//busco la asignatura
  itEst->second->inscribir(itAsig->second);
  itAsig->second->agregarInscripto(itEst->second);
};

void ControladorUsuario::cancelarInscripcion(){

};

set<dtNotificacion> ControladorUsuario::consultarNotifs(){

};

void ControladorUsuario::cambiarModoSus(int modo){
  if((modo == 1) | (modo == 2) | (modo == 3))
    setNuevoModoSus(modo);
  //else
    //mandar warning?
};

void ControladorUsuario::confirmarCambio(){/*
  usuario* user = find(getEmailUser(),ColeccionGlobalUsuarios);//CORREGIR, notacion inventada
  switch (modo){
    case 1:
      estrategiaModoSus1 *strat = new estrategiaModoSus1();
      user->setAplica(strat);
    break;
    case 2:
      estrategiaModoSus2 *strat = new estrategiaModoSus2();
      user->setAplica(strat);
    break;
    case 3:
      estrategiaModoSus3 *strat = new estrategiaModoSus3();
      user->setAplica(strat);
    break;
  }*/
};

void ControladorUsuario::cancelarCambio(){
  //vacio
};

void ControladorUsuario::desuscribirse(){/*
  usuario* user = find(getEmailUser(),ColeccionGlobalUsuarios);//CORREGIR, notacion inventada
  handlerMensajes.eliminarObs(user);*/
};

ControladorUsuario::~ControladorUsuario(){
  //??estrategiaModoSus1
};
