#ifndef ESTCLA_H
#define ESTCLA_H

#include "../headers/visualizacion.h"
#include "../headers/estudiante.h"
#include "../headers/clase.h"

class EstCla{
  private:
    Visualizacion *vis;
    Estudiante *est;
    Clase *clase;
  public:
    EstCla();
    void setVisualizacion(Visualizacion*)
    void setEstudiante(Estudiante*)
    void setClase(Clase*)
    Visualizacion* getVis();
    Estudiante* getEst();
    Clase* getClase();

    void marcar(dtFecha);
    void iniciarVis();
    ~EstCla();
};

#endif
