#ifndef DT_CLASE_H
#define DT_CLASE_H
#include "dtFecha.h"

enum tipoClase {Teorico,Practico,Monitoreo};
class Docente;

class dtClase{
  private:
    string nombre;
    int codigo;
    string url;
    DtFecha fechaInicio;
    DtFecha fechaFin;
    Docente* creador;
    string codigoAsig; //Clase original tenia una asociacion a la asignatura, aca lo reemplaza el identificador de la asignatura
    tipoClase tipo;

  public:
    dtClase();
    void setNombre(string);
    void setCodigo(int);
    void setUrl(string);
    void setFechaInicio(DtFecha);
    void setFechaFin(DtFecha);
    tipoClase getTipo();
    string getNombre();
    int getCodigo();
    string getUrl();
    DtFecha getFechaInicio();
    DtFecha getFechaFin();

    ~dtClase();
    //bool operator<(const Clase &right); //si colecciones se implementan con set esto es necesario
};
#endif
