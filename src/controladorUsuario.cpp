#include "../include/headers/ControladorUsuario.h"

ControladorUsuario::ControladorUsuario(){

};
bool ControladorUsuario::getUserEsEst(){  return userEsEst;};
void ControladorUsuario::setUserEsEst(bool es){  this->userEsEst = es;};

string ControladorUsuario::getNombreUser(){  return nombreUser;};
void ControladorUsuario::setNombreUser(string nombre){  this->nombreUser = nombre;};

string ControladorUsuario::getContraseniaUser(){  return contraseniaUser;};
void ControladorUsuario::setContraseniaUser(string pass){  this->contraseniaUser = pass;};

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

void ControladorUsuario::iniciarSesion(string email, string pass){
  //member(); buscar si las credenciales existen en la coleccion
  this.setEmailUserActual(email);
};

void ControladorUsuario::agregarEstudiante(string n, string c, string e, string u, string ci){
  setNombreUser(n);
  setContraseniaUser(c);
  setEmailUser(e);
  setUrlUser(u);
  setCedulaEst(ci);

  setUserEsEst(true);
};

void ControladorUsuario::agregarDocente(string n, string c, string e, string u, string i){
  setNombreUser(n);
  setContraseniaUser(c);
  setEmailUser(e);
  setUrlUser(u);
  setInstitutoDoc(i);

  setUserEsEst(false);
};

void ControladorUsuario::confirmarAlta(){
  if userEsEst{
    Estudiante *nuevo = new Estudiante()
    nuevo.setNombre(getNombreUser());
    nuevo.setEmail(getEmailUser());
    nuevo.setContrasenia(getContraseniaUser());
    nuevo.setImagen(getUrlUser());
    nuevo.setCI(getCedulaEst());
    coleccionGlobalEstudiantes.insert(pair<string,Estudiante*>(getEmailUser(),nuevo));

  }
  else{
    Docente *nuevo = new Docente()
    nuevo.setNombre(getNombreUser());
    nuevo.setEmail(getEmailUser());
    nuevo.setContrasenia(getContraseniaUser());
    nuevo.setImagen(getUrlUser());
    nuevo.setInstituto(getInstitutoDoc());
    coleccionGlobalDocentes.insert(pair<string,Docente*>(getEmailUser(),nuevo));
  }
};

void ControladorUsuario::cancelarAlta(){
  //vacio
};

set(DtNotifiaciones) ControladorUsuario::consultarNotifs(){

};

void ControladorUsuario::cambiarModoSus(int modo){
  if(modo == 1 | modo == 2 | modo == 3)
    setNuevoModoSus(modo);
  else
    //mandar warning?
};

void ControladorUsuario::confirmarCambio(){
  usuario* user = find(getEmailUser(),ColeccionGlobalUsuarios);//CORREGIR, notacion inventada
  switch (modo){
    case 1:
      estrategiaModoSus1 *strat = new estrategiaModoSus1();
      user.setAplica(strat);
    break;
    case 2:
      estrategiaModoSus2 *strat = new estrategiaModoSus2();
      user.setAplica(strat);
    break;
    case 3:
      estrategiaModoSus3 *strat = new estrategiaModoSus3();
      user.setAplica(strat);
    break;
  }
};

void ControladorUsuario::cancelarCambio(){
  //vacio
};

void ControladorUsuario::desuscribirse(){
  usuario* user = find(getEmailUser(),ColeccionGlobalUsuarios);//CORREGIR, notacion inventada
  handlerMensajes.eliminarObs(user);
};

ControladorUsuario::~ControladorUsuario(){
  //??
};
