#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include <list>

using namespace std;

class UsrCla;
class EstrategiaNotifs;
class dtMensaje;
class dtNotificacion;

class Usuario{
  private:
    string nombre;
    string email;
    string password;
    string imagen;
    set<dtNotificacion> notificaciones;
    int modoSus;
    EstrategiaNotifs* aplica;
    list<UsrCla*> clasesParticipa;
  public:
    Usuario();
    void setNombre(string);
    void setEmail(string);
    void setPassword(string);
    void setImagen(string);
    void setNotificaciones(); //crea el conjunto de notifiaciones vacio
    void setModoSus(int);
    void setAplica(EstrategiaNotifs*);
    string getNombre();
    string getEmail();
    string getPassword();
    string getImagen();
    set<dtNotificacion> getNotificaciones();
    int getModoSus();
    EstrategiaNotifs* getAplica();

    void asistir(UsrCla*);
    list<UsrCla*> getClasesParticipa();

    bool aplicaNotificacion(dtMensaje);
    void notificar(dtNotificacion);

    ~Usuario();
};
#endif
