#ifndef DOCENTE_H
#define DOCENTE_H
#include <string>

class Docente : public Usuario{
  private:
    string instituto;
    set(Rol) roles;
    set(Clase) clasesCreadas;
    set(Clase) participa;
  public://faltan funciones de manejo de relaciones
    Docente();
    string getInstituto();
    void setInstituto(string);

    bool esDocenteDe(string);
    rol nuevoRol(Asignatura);
    set(DtAsignatura) getInfo();
    void agregarClaseNueva(Clase);
    set(DtClase) clasesATerminar();
    void desvincularDoc(rol);

    ~Docente();
};
#endif
