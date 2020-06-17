#ifndef ESTCLA_H
#define ESTCLA_H
#include <string>
#include <set>
#include "dtFecha.h"
//#include "visualizacion.h"
//#include "estudiante.h"
//#include "clase.h"

using namespace std;

class Clase;
class Estudiante;
class Visualizacion;

class UsrCla{
  private:
    set<Visualizacion*> vis;
    Estudiante *est;
    Clase *clase;
  public:
    UsrCla();
    void setVisualizacion(Visualizacion*); //hacer coleccion de visualizacion
    void setEstudiante(Estudiante*);
    void setClase(Clase*);
    Estudiante* getEst();
    Clase* getClase();

    set<Visualizacion*> getVis();
    void marcarFin(dtFecha);
    //void iniciarVis();
    ~UsrCla();
    bool operator<(const UsrCla &right){return true;}; //si colecciones se implementan con set esto es necesario

};

#endif
