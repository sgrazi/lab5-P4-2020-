#ifndef ESTRATEGIA_NOTIFS_H
#define ESTRATEGIA_NOTIFS_H
#include"usuario.h"

class dtMensaje;

class EstrategiaNotifs{
  private:
    Usuario* user;
  public:
    void setUser(Usuario*);
    Usuario* getUser();
    virtual bool aplicaNotificacion(dtMensaje) = 0;

    virtual ~EstrategiaNotifs(){};
};
#endif
