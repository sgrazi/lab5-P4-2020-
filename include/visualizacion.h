#ifndef VISUALIZACION_H
#define VISUALIZACION_H
//#include "usrcla.h" //dependencia circular
#include "dtFecha.h"

class UsrCla;

class Visualizacion{
  private:
    bool enVivo;
    DtFecha fechaInicioVis;
    DtFecha fechaFinVis;
    UsrCla* usrcla;
  public://faltan funciones de manejo de relaciones
    Visualizacion();
    void setEnVivo(bool);
    void setFechaInicioVis(DtFecha);
    void setFechaFinVis(DtFecha);
    bool getEnVivo();
    DtFecha getFechaInicioVis();
    DtFecha getFechaFinVis();

    DtFecha generarFecha();

    ~Visualizacion();
};
#endif
