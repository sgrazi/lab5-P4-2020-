#ifndef HANDLER_MENSAJES_H
#define HANDLER_MENSAJES_H
#include "usuario.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class HandlerMensajes{
  private:
    map<string,Usuario>* observers;
  public:
    HandlerMensajes();

    void agregarMensaje(int , bool , int , string ); //cual es el tipo de retorno? en el dcd no estaba, puse void
    void agregarObs(Usuario);
    void eliminarObs(Usuario);

    ~HandlerMensajes();
};
#endif
