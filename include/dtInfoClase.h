#ifndef DT_INFO_CLASE_H
#define DT_INFO_CLASE_H
#include "dtFecha.h"
#include "tipoClase.h"
#include <string>

using namespace std;

//forward declaration
class dtEstudiante;

class dtInfoClase{
  private:
    string nombre;
    string url;
    dtFecha fechaInicio;
    dtFecha fechaFin;
    tipoClase tipo;
    int codigo; //codigo de la asignatura de la clase
    string iniciadaPor;
    int cantHabilitados;
    string habilitados[15]; //emails de los habilitados
    int asistentes;
  public:
    dtInfoClase(){
      this->cantHabilitados = 0;
    };
    void setCodigo(int);
    void setNombre(string);
    void setUrl(string);
    void setFechaInicio(dtFecha);
    void setFechaFin(dtFecha);
    void setTipo(tipoClase);
    void setIniciadaPor(string);
    void setAsistentes(int);
    int getCodigo();
    string getNombre();
    string getUrl();
    dtFecha getFechaInicio();
    dtFecha getFechaFin();
    tipoClase getTipo();
    string getIniciadaPor();
    int getAsistentes();

    ~dtInfoClase(){};
};

#endif
