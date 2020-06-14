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
    dtFecha(int,int,int,int,int,int);
    void setAnio(int);
    void setMes(int);
    void setDia(int);
    void setHora(int);
    void setMinuto(int);
    void setSegundo(int);
    dtFecha getFecha();
    ~dtFecha();
    int getAnio() const ;
    int getMes() const ;
    int getDia() const ;
    int getHora() const ;
    int getMinuto() const ;
    int getSegundo() const ;
    bool operator==(const dtFecha& fecha) const;
};
#endif
