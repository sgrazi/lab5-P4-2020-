#ifndef VISUALIZACION_H
#define VISUALIZACION_H
//#include "usrcla.h" //dependencia circular
#include "dtFecha.h"

class UsrCla;

class Visualizacion{
  private:
    bool enVivo;
    dtFecha fechaInicioVis;
    dtFecha fechaFinVis;
    UsrCla* usrcla;
  public://faltan funciones de manejo de relaciones
    Visualizacion();
    void setEnVivo(bool);
    void setFechaInicioVis(dtFecha);
    void setFechaFinVis(dtFecha);
    bool getEnVivo();
    dtFecha getFechaInicioVis();
    dtFecha getFechaFinVis();

    dtFecha generarFecha();

    ~Visualizacion();
};
#endif
