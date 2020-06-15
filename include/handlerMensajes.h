#ifndef HANDLER_MENSAJES_H
#define HANDLER_MENSAJES_H
#include "usuario.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class HandlerMensajes{
  private:
    map<int,Mensaje*>* coleccionGlobalMensajes;
    map<int,Clase*>* coleccionGlobalClases;
    map<string,Usuario*>* observers;
  public:
    HandlerMensajes();

    void setColMens(map<int,Mensaje*>*);
    void setColCla(map<int,Clase*>*);

    void agregarMensaje(int , bool , int , string, dtFecha, int); //cual es el tipo de retorno? en el dcd no estaba, puse void
    void agregarObs(Usuario*);
    void eliminarObs(Usuario*);

    ~HandlerMensajes();
};
#endif
