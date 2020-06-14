#ifndef MONITOREO_H
#define MONITOREO_H
#include "clase.h"

class Estudiante;

class Monitoreo : public Clase{
  private:
    Estudiante* habilitados [15];
  public://faltan funciones de manejo de relaciones
    Monitoreo();
    ~Monitoreo();
    void setNombre(string);
};
#endif
