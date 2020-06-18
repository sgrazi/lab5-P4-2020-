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
    void setUsrCla(UsrCla*);
    bool getEnVivo();
    dtFecha getFechaInicioVis();
    dtFecha getFechaFinVis();
    UsrCla* getUsrCla();

    dtFecha generarFecha();
    //bool operator<(const Visualizacion &right){return true;}; //si colecciones se implementan con set esto es necesario

    ~Visualizacion();
    bool operator<(const Visualizacion &right){return true;};
};
#endif
