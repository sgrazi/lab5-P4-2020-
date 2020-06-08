#ifndef CLASE_H
#define CLASE_H
#include <string>

class Clase{
  private:
    string nombre;
    int codigo;
    string url;
    DtFecha fechaInicio;
    DtFecha fechaFin;
    Docente creador;
    set(EstCla) estParticipantes;
    set(Docente) docParticipantes;
    set(Mensaje) mensajes;
    Asignatura *asig;
    tipoClase tipo;

  public://faltan funciones de manejo de relaciones
    Clase() = 0;
    void setNombre(string);
    void setCodigo(int);
    void setUrl(string);
    void setFechaInicio(DtFecha);
    void setFechaFin(DtFecha);
    tipoClase getTipo();
    string getNombre();
    int getCodigo();
    string getUrl();
    DtFecha getFechaInicio();
    DtFecha getFechaFin();

    virtual void visualizar(Estudiante);

    ~Clase(){};
    //bool operator<(const Clase &right); //si colecciones se implementan con set esto es necesario
};
#endif
