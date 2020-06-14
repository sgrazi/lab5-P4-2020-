#include "../include/usrCla.h"

UsrCla::UsrCla(){};

void UsrCla::setEstudiante(Estudiante* e){ this->est = e;};
Estudiante* UsrCla::getEst(){ return est;};

void UsrCla::setClase(Clase* c){ this->clase = c;};
Clase* UsrCla::getClase(){ return clase;};

//void setVisualizacion(Visualizacion*);
//Visualizacion* UsrCla::getVis();
/*
int UsrCla::getCodigoClase(){};
string UsrCla::getEmailUser(){};
void UsrCla::marcar(dtFecha){};
void UsrCla::iniciarVis(){};
UsrCla::~UsrCla(){};
*/
