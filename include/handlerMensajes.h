#ifndef HANDLER_MENSAJES_H
#define HANDLER_MENSAJES_H
#include "usuario.h"
#include <iostream>
#include <string>
#include <map>

class Mensaje;
class Clase;
class Usuario;
class dtFecha;

using namespace std;

class HandlerMensajes{
  private:
    map<int,Mensaje*>* coleccionGlobalMensajes;
    map<string,Clase*>* coleccionGlobalClases;
    map<string,Usuario*>* observers;
  public:
    HandlerMensajes();

    void setColMens(map<int,Mensaje*>*);
    void setColCla(map<string,Clase*>*);

    Mensaje* agregarMensaje(int , bool , int , string, dtFecha, string);
    void agregarObs(Usuario*);
    void eliminarObs(Usuario*);

    void listaObservers();//auxiliar para debuggear los observers

    ~HandlerMensajes();
};
#endif
