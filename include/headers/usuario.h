#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>

using namespace std;

class Usuario{
  private:
    string nombre;
    string email;
    string password;
    string imagen;
    set<DtNotifiacion> notificaciones;
    // int modoSus //Necesario?
    EstrategiaNotifs aplica;
  public:
    Usuario();
    void setNombre(string);
    void setEmail(string);
    void setPassword(string);
    void setImagen(string);
    void setNotificaciones(); //crea el conjunto de notifiaciones vacio
    void setAplica(EstrategiaNotifs);
    string getNombre();
    string getEmail();
    string getPassword();
    string getImagen();
    set<DtNotifiacion> getNotificaciones();
    EstrategiaNotifs getAplica();

    void notificar(DtNotifiacion)

    ~Usuario();
};
#endif
