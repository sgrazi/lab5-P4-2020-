#ifndef ESTCLA_H
#define ESTCLA_H

#include "../headers/visualizacion.h"
#include "../headers/estudiante.h"
#include "../headers/clase.h"

class Clase;
class Estudiante;

class UsrCla{
  private:
    Visualizacion *vis;
    Estudiante *est;
    Clase *clase;
  public:
    UsrCla();
    void setVisualizacion(Visualizacion*);
    void setEstudiante(Estudiante*);
    void setClase(Clase*);
    Visualizacion* getVis();
    Estudiante* getEst();
    Clase* getClase();

    int getCodigoClase();
    string getEmailUser();
    void marcar(DtFecha);
    void iniciarVis();
    ~UsrCla();
};

#endif
