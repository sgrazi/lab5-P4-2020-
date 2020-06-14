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
    string creador;
    int codigoAsig; //Clase original tenia una asociacion a la asignatura, aca lo reemplaza el identificador de la asignatura
    tipoClase tipo;

  public:
    dtClase();
    void setNombre(string);
    void setCodigo(int);
    void setUrl(string);
    void setFechaInicio(dtFecha);
    void setFechaFin(dtFecha);
    void setTipo(tipoClase);
    tipoClase getTipo() const ;
    string getNombre() const ;
    int getCodigo() const;
    string getUrl() const ;
    dtFecha getFechaInicio() const ;
    dtFecha getFechaFin() const ;

    void setCreador(string);
    string getCreador() const ;
    void setAsig(int);
    int getAsig() const ;

    ~dtClase();
    bool operator<(const dtClase &right)const; //si colecciones se implementan con set esto es necesario
};
#endif
