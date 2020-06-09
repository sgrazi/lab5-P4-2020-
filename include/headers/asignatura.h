#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include <string>
#include <iostream>
#include"../dts/dtEstudiante.h"
using namespace std;

class Asignatura{
  private:
    int codigo;
    string nombre;
    bool teorico;
    bool monitoreo;
    bool practico;
    set(dtEstudiante) inscriptos;
    map<string,Rol> docentes; //string es el email del doc
  public://faltan funciones de manejo de relaciones
    Asignatura();
    void setCodigo(int);
    void setNombre(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    int getCodigo();
    string getNombre();
    bool getTeorico();
    bool getPractico();
    bool getMonitoreo();
    ~Asignatura();
    //bool operator<(const Asignatura &right); //si colecciones se implementan con set esto es necesario
};

#endif
