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
    //map<tipoClase,Rol> roles;
    //set<UsrCla> clasesParticipa;
    //map<int,Clase> clasesCreadas;
    //map<int,Clase> participa;
  public://faltan funciones de manejo de relaciones
    Docente();
    string getInstituto();
    void setInstituto(string);

    bool esDocenteDe(string);
    Rol nuevoRol(Asignatura);
    set<dtAsignatura> getInfo();
    void agregarClaseNueva(Clase*);
    set<dtClase> clasesATerminar();
    void desvincularDoc(Rol);

    ~Docente();
};
#endif
