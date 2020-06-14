#ifndef CLASE_H
#define CLASE_H

#include "iControladorUsuario.h"
#include "docente.h"
#include "usrCla.h"
#include "mensaje.h"
#include <string>
#include <set>

using namespace std;

class Mensaje;
class Asignatura;
class Estudiante;

using namespace std;
class Clase{
  private:
    string nombre;
    int codigo;
    string url;
    dtFecha fechaInicio;
    dtFecha fechaFin;
    Docente* creador;
    set<UsrCla> estParticipantes;
    set<Docente> docParticipantes;
    set<Mensaje> mensajes;
    Asignatura *asig;
    tipoClase tipo;

  public://faltan funciones de manejo de relaciones
    Clase();
    virtual void abstracta() = 0;
    void setNombre(string);
    void setCodigo(int);
    void setUrl(string);
    void setFechaInicio(dtFecha);
    void setFechaFin(dtFecha);
    void setCreador(Docente*);
    void setAsig(Asignatura*);
    void setTipo(tipoClase);
    tipoClase getTipo();
    string getNombre();
    int getCodigo();
    string getUrl();
    dtFecha getFechaInicio();
    dtFecha getFechaFin();
    
    int getCodigoAsig();

    void visualizar(Estudiante*);

    ~Clase();
    //bool operator<(const Clase &right); //si colecciones se implementan con set esto es necesario
};
#endif
