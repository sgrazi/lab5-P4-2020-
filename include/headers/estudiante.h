#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
#include <set>

#include"../headers/asignatura.h"
#include"../headers/estcla.h"
#include"../headers/monitoreo.h"

class Estudiante : public Usuario{
  private:
    string ci;
    set(Asignatura) asignaturas;
    set(EstCla) clasesParticipa;
    set(Monitoreo) monHabilitados;
  public://faltan funciones de manejo de relaciones
    Estudiante();
    void setCI(string);
    string getCI();

    void desinscribir(string);

    ~Estudiante();
};
#endif
