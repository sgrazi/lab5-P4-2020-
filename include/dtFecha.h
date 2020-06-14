#ifndef DT_FECHA_H
#define DT_FECHA_H

#include <stdio.h>
#include <iostream>

using namespace std;

class dtFecha {
  private:
    int anio;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;

  public:
    dtFecha();
    void setAnio(int);
    void setMes(int);
    void setDia(int);
    void setHora(int);
    void setMinuto(int);
    void setSegundo(int);
    dtFecha getFecha();
    ~dtFecha();
};
#endif
