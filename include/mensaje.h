#ifndef MENSAJE_H
#define MENSAJE_H
#include <string>
#include "handlerMensajes.h"
#include "clase.h"
#include "mensaje.h"
#include "dtFecha.h"
using namespace std;

class Mensaje{
  private:
    int id;
    string contenido;
    dtFecha fecha;
    Mensaje *enRespuestaA;
    HandlerMensajes *handler;
    Clase *clase;
  public://faltan funciones de manejo de relaciones
    Mensaje();
    void setId(int);
    void setContenido(string);
    void setFecha(dtFecha);
    void setEnRespuestaA(Mensaje*);
    int getId();
    string getContenido();
    dtFecha getFecha();
    Mensaje* getEnRespuestaA();

    ~Mensaje();
    //bool operator<(const Mensaje &right); //si colecciones se implementan con set esto es necesario
};
#endif
