#ifndef DOCENTE_H
#define DOCENTE_H
#include <string>
#include <set>
#include <map>
#include "usuario.h"
#include "dtAsignatura.h"
#include "dtClase.h"
#include "clase.h"

using namespace std;
class Rol;
class Clase;
class Asignatura;

class Docente : public Usuario{
  private:
    string instituto;
    map<int,Rol*>* asignaturas; //int es el codigo de la asignatura
    //set<UsrCla> clasesParticipa;
    map<int,Clase*>* clases;
    //map<int,Clase> participa;
  public://faltan funciones de manejo de relaciones
    Docente();
    string getInstituto();
    void setInstituto(string);
    map<int,Rol*>* getAsignaturas();
    map<int,Clase*>* getClases();

    bool esDocenteDe(int);
    Rol* nuevoRol(Asignatura*,tipoClase);
    set<dtAsignatura> getInfo();
    void agregarClaseNueva(Clase*);
    set<dtClase> clasesATerminar();
    void desvincularDoc(Rol);

    ~Docente();
};
#endif
