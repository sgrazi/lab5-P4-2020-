#ifndef MONITOREO_H
#define MONITOREO_H
#include"../headers/clase.h"
class Estudiante;

class Monitoreo : public Clase{
  private:
    Estudiante[15] habilitados;
  public://faltan funciones de manejo de relaciones
    Monitoreo();
    ~Monitoreo();
};
#endif
