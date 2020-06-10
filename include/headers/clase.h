#ifndef CLASE_H
#define CLASE_H

#include"../headers/iControladorUsuario.h"
#include "../headers/docente.h"
#include "../headers/estcla.h"
#include <string>
#include <set>

class Mensaje;
class Asignatura;
class Estudiante;

using namespace std;
class Clase{
  private:
    string nombre;
    int codigo;
    string url;
    DtFecha fechaInicio;
    DtFecha fechaFin;
    Docente* creador;
    set<EstCla> estParticipantes;
    set<Docente> docParticipantes;
    set<Mensaje> mensajes;
    Asignatura *asig;
    tipoClase tipo;

  public://faltan funciones de manejo de relaciones
    Clase();
    virtual void setNombre(string)=0;
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

    void visualizar(Estudiante*);

    ~Clase();
    //bool operator<(const Clase &right); //si colecciones se implementan con set esto es necesario
};
#endif
