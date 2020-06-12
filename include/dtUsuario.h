#ifndef DT_USUARIO_H
#define DT_USUARIO_H
#include <string>
#include <iostream>

using namespace std;


class dtUsuario{ //abstracta
  private:
    string nombre;
    string email;
    string password;
    string imagen;
    //set<DtNotifiacion> notificaciones; va?
    int modoSus; //antes estaba su componente de strategy, ahora un int que indica cual modo de strategy tiene
  public:
    dtUsuario(){};
    void setNombre(string);
    void setEmail(string);
    void setPassword(string);
    void setImagen(string);
    //void setNotificaciones(); //crea el conjunto de notifiaciones vacio
    void setModoSus(int);
    string getNombre() const ;
    string getEmail() const ;
    string getPassword() const ;
    string getImagen() const ;
    //set(DtNotifiacion) getNotificaciones();
    int getModoSus() const ;

    ~dtUsuario(){};
};
#endif
