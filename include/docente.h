#ifndef DOCENTE_H
#define DOCENTE_H
#include <string>
#include <set>
#include <map>
#include "usuario.h"
#include "dtAsignatura.h"
#include "dtClase.h"
#include "clase.h"
#include "reloj.h"

using namespace std;
class Rol;
class Clase;
class Asignatura;

class Docente : public Usuario{
  private:
    string instituto;
    map<string,Rol*>* asignaturas; //string es el codigo de la asignatura
    map<string,Clase*>* clases;

    Reloj* relojSistema;
  public:
    Docente();
    string getInstituto();
    void setInstituto(string);
    map<string,Rol*>* getAsignaturas();//corregir esto en un futuro, no tiene que ser puntero a map sino map solo
    map<string,Clase*>* getClases();

    void borrarClase(string cc);

    bool esDocenteDe(string);
    Rol* nuevoRol(Asignatura*,tipoClase);
    set<dtAsignatura> getInfo();
    void agregarClaseNueva(Clase*);
    set<dtClase> clasesATerminar();
    void desvincularDoc(string);

    ~Docente();
};
#endif
