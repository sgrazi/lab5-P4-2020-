#ifndef DOCENTE_H
#define DOCENTE_H
#include <string>
#include <set>
#include <map>
#include "../headers/usuario.h"
#include"../dts/dtAsignatura.h"
#include"../dts/dtClase.h"
#include "../headers/clase.h"

using namespace std;
class Rol;
class Clase;
class Asignatura;

class Docente : public Usuario{
  private:
    string instituto;
    map<tipoClase,Rol> roles;
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
