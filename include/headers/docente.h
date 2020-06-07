#ifndef DOCENTE_H
#define DOCENTE_H

class Docente : public Usuario{
  private:
    string: instituto;
    set(Rol) roles;
    set(Clase) clasesCreadas;
    set(Clase) participa;
  public:
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
}
#endif
