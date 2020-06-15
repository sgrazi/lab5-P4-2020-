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

class Estudiante;

class Clase;

class Asignatura{
  private:
    int codigo;
    string nombre;
    bool teorico;
    bool monitoreo;
    bool practico;
    map<string,Estudiante*>* inscriptos;
    map<string,Rol*>* docentes; //string es el email del doc
    map<int,Clase*>* clases;
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

    map<string,Estudiante*>* getInscriptos();
    map<int,Clase*>* getClases();
    map<string,Rol*>* getDocentes();

    void agregarRol(Rol*);
    void agregarInscripto(Estudiante*);
    void agregarClaseNueva(Clase*);
    //map<string,Estudiante*>* getInscriptos();
    //set<dtClase> getClases();
    //set<dtClase> getClasesDiferido();
    ~Asignatura();
};

#endif
