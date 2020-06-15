#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include <list>

using namespace std;

class UsrCla;
class EstrategiaNotifs;
class Mensaje;
class dtMensaje;
class dtNotificacion;

class Usuario{
  private:
    string nombre;
    string email;
    string password;
    string imagen;
    set<dtNotificacion*> notificaciones;
    set<Mensaje*> mensajes;
    int modoSus;
    EstrategiaNotifs* aplica;
    list<UsrCla*> clasesParticipa;
  public:
    Usuario();
    void setNombre(string);
    void setEmail(string);
    void setPassword(string);
    void setImagen(string);
    void setModoSus(int);
    void setAplica(EstrategiaNotifs*);
    string getNombre();
    string getEmail();
    string getPassword();
    string getImagen();
    int getModoSus();
    set<dtNotificacion*> getNotificaciones();
    EstrategiaNotifs* getAplica();

    void agregarMensaje(Mensaje*);
    void asistir(UsrCla*);
    list<UsrCla*> getClasesParticipa();

    bool aplicaNotificacion(dtMensaje);
    void notificar(dtMensaje);

    ~Usuario();
};
#endif
