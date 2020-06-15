#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include <string>
#include <map>
#include <list>
#include "usuario.h"
//#include "asignatura.h"
//#include"usrcla.h"
//#include"monitoreo.h"

class Asignatura;
class UsrCla;
class dtAsignatura;

using namespace std;

class Estudiante : public Usuario{
  private:
    string ci;
    map<int,Asignatura*>* asignaturas;
    //map<int,Monitoreo>* monHabilitados;
  public://faltan funciones de manejo de relaciones
    Estudiante();
    void setCI(string);
    string getCI();
    map<int,Asignatura*>* getAsignaturas();
    set<dtAsignatura> getAsignaturasInscripto();

    void inscribir(Asignatura*);
    void desinscribir(int);

    ~Estudiante();
};
#endif
