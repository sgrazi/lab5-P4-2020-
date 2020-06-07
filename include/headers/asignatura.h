#ifndef ASIGNATURA_H
#define ASIGNATURA_H

class Asignatura{
  private:
    int codigo;
    string nombre;
    bool teorico;
    bool monitoreo;
    bool practico;
    set(DtEstudiantes) inscriptos;
    map<string,Rol> docentes; //string es el email del doc
  public://faltan funciones de manejo de relaciones
    Asignatura();
    void setCodigo(int);
    void setNombre(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    int getCodigo();
    string getNombre();
    bool getTeorico();
    bool getPractico();
    bool getMonitoreo();
    ~Asignatura();
    //bool operator<(const Asignatura &right); //si colecciones se implementan con set esto es necesario
};

#endif
