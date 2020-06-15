#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include <list>
#include "dtNotificacion.h"

using namespace std;

class UsrCla;
class EstrategiaNotifs;

class Usuario{
  private:
    string nombre;
    string email;
    string password;
    string imagen;
    set<dtNotificacion> notificaciones;
    EstrategiaNotifs* aplica;
    list<UsrCla*> clasesParticipa;
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

    void asistir(UsrCla*);
    list<UsrCla*> getClasesParticipa();

    void notificar(dtNotificacion);

    ~Usuario();
};
#endif
