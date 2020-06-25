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
class Clase;

using namespace std;

class Estudiante : public Usuario{
  private:
    string ci;
    map<string,Asignatura*>* asignaturas;
    set<Clase*>* asistiendo;
  public://faltan funciones de manejo de relaciones
    Estudiante();
    void setCI(string);
    string getCI();
    map<string,Asignatura*>* getAsignaturas();
    set<dtAsignatura> getAsignaturasInscripto();
    set<Clase*>* getAsistiendo();
    void borrarAsig(string ca);

    void asistirClase(Clase* c);
    void dejarDeAsistir(Clase* c);
    void inscribir(Asignatura*);
    void desinscribir(string);

    ~Estudiante();
};
#endif
