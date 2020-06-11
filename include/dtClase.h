#ifndef DT_CLASE_H
#define DT_CLASE_H
#include "dtFecha.h"
#include "tipoClase.h"
#include <string>

using namespace std;

class Docente;

class dtClase{
  private:
    string nombre;
    int codigo;
    string url;
    dtFecha fechaInicio;
    dtFecha fechaFin;
    Docente* creador;
    string codigoAsig; //Clase original tenia una asociacion a la asignatura, aca lo reemplaza el identificador de la asignatura
    tipoClase tipo;

  public:
    dtClase();
    void setNombre(string);
    void setCodigo(int);
    void setUrl(string);
    void setFechaInicio(dtFecha);
    void setFechaFin(dtFecha);
    tipoClase getTipo();
    string getNombre();
    int getCodigo();
    string getUrl();
    dtFecha getFechaInicio();
    dtFecha getFechaFin();

    ~dtClase();
    //bool operator<(const Clase &right); //si colecciones se implementan con set esto es necesario
};
#endif
