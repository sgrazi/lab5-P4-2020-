#ifndef DT_USUARIO_H
#define DT_USUARIO_H
#include <string>
#include <iostream>

using namespace std;


class dtUsuario{
  private:
    string nombre;
    string email;
    string password;
    string imagen;
    //set<DtNotifiacion> notificaciones; va?
    int modoSus; //antes estaba su componente de strategy, ahora un int que indica cual modo de strategy tiene
  public:
    dtUsuario();
    void setNombre(string);
    void setEmail(string);
    void setPassword(string);
    void setImagen(string);
    //void setNotificaciones(); //crea el conjunto de notifiaciones vacio
    void setModoSus(int);
    string getNombre();
    string getEmail();
    string getPassword();
    string getImagen();
    //set(DtNotifiacion) getNotificaciones();
    int setModoSus();

    ~dtUsuario();
};
#endif
