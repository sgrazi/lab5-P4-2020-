#ifndef DT_MENSAJE_H
#define DT_MENSAJE_H
#include "dtFecha.h"
#include <string>

using namespace std;

class dtMensaje{
  private:
    int id;
    string contenido;
    dtFecha fecha;
    int enRespuestaA; //Mensaje original tenia un puntero a otro mensaje, aca es el identificador del otro mensaje
    int clase; //Mensaje original tenia un puntero a su clase, aca es el identificador de la clase
  public:
    dtMensaje();
    void setId(int);
    void setContenido(string);
    void setFecha(dtFecha);
    void setEnRespuestaA(int);
    void setClase(int);
    int getId() const ;
    string getContenido() const ;
    dtFecha getFecha() const ;
    int getEnRespuestaA() const ;
    int getClase() const ;

    ~dtMensaje();
    bool operator<(const dtMensaje &right); //si colecciones se implementan con set esto es necesario
};
#endif
