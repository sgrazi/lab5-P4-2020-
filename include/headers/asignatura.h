#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include<map>
#include<set>
#include <string>
#include <iostream>
#include"../dts/dtEstudiante.h"
#include "../headers/rol.h"

using namespace std;
class Rol;

class Asignatura{
  private:
    int codigo;
    string nombre;
    bool teorico;
    bool monitoreo;
    bool practico;
    set<dtEstudiante> inscriptos;
    map<string,Rol> docentes; //string es el email del doc
  public://faltan funciones de manejo de relaciones
    Asignatura();
    void setCodigo(int);
    void setNombre(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    int getCodigo() const;
    string getNombre() const;
    bool getTeorico() const;
    bool getPractico() const;
    bool getMonitoreo() const;
    ~Asignatura();
    //bool operator<(const Asignatura &right); //si colecciones se implementan con set esto es necesario
};

#endif
