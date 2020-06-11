#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include <map>
#include <set>
#include <string>
#include <iostream>
#include "dtEstudiante.h"
#include "rol.h"

using namespace std;
class Rol;

class Asignatura{
  private:
    int codigo;
    string nombre;
    bool teorico;
    bool monitoreo;
    bool practico;
    //set<dtEstudiante>* inscriptos;
    map<string,Rol> docentes; //string es el email del doc
    //map<int,Clase> clases;
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

    void agregarRol(Rol);
    //void agregarClaseNueva(dtClase);
    //set<dtEstudiante> getInscriptos();
    //set<dtClase> getClases();
    ~Asignatura();
    //bool operator<(const Asignatura &right); //si colecciones se implementan con set esto es necesario
};

#endif
