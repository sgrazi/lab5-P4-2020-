#include "../include/usrCla.h"
#include "../include/dtFecha.h"
#include "../include/estudiante.h"
#include "../include/visualizacion.h"

const dtFecha fechaNula(0,0,0,0,0,0);

UsrCla::UsrCla(){};

void UsrCla::setEstudiante(Estudiante* e){ this->est = e;};
Estudiante* UsrCla::getEst(){ return est;};

void UsrCla::setClase(Clase* c){ this->clase = c;};
Clase* UsrCla::getClase(){ return clase;};

//void setVisualizacion(Visualizacion*);
//Visualizacion* UsrCla::getVis();

//int UsrCla::getCodigoClase(){};
//string UsrCla::getEmailUser(){};

void UsrCla::marcarFin(dtFecha fecha){
  if(vis->getFechaFinVis() == fechaNula)
    vis->setFechaFinVis(fecha);
  vis->setEnVivo(true);
};
//void UsrCla::iniciarVis(){};
//UsrCla::~UsrCla(){};
