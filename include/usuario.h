#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include "dtNotificacion.h"
//#include "../headers/estrategiaNotifs.h"
using namespace std;

class EstrategiaNotifs;

class Usuario{
  private:
    string nombre;
    string email;
    string password;
    string imagen;
    set<dtNotificacion> notificaciones;
    EstrategiaNotifs* aplica;
  public:
    Usuario();
    void setNombre(string);
    void setEmail(string);
    void setPassword(string);
    void setImagen(string);
    void setNotificaciones(); //crea el conjunto de notifiaciones vacio
    void setAplica(EstrategiaNotifs*);
    string getNombre();
    string getEmail();
    string getPassword();
    string getImagen();
    set<dtNotificacion> getNotificaciones();
    EstrategiaNotifs* getAplica();

    void notificar(dtNotificacion);

    ~Usuario();
};
#endif
