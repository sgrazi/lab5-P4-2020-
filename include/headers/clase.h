#ifndef CLASE_H
#define CLASE_H

class Clase{
  private:
    string nombre;
    string codigo;
    string url;
    DtFecha fechaInicio;
    DtFecha fechaFin;
    Docente creador;
    set(EstCla) estParticipantes;
    set(Docente) docParticipantes;
    set(Mensaje) mensajes;
    Asignatura *asig;
    tipoClase tipo;

  public:
    Clase() = 0;
    void setNombre(string);
    void setCodigo(string);
    void setUrl(string);
    void setFechaInicio(DtFecha);
    void setFechaFin(DtFecha);
    tipoClase getTipo();
    string getNombre();
    string getCodigo();
    string getUrl();
    DtFecha getFechaInicio();
    DtFecha getFechaFin();

    virtual void visualizar(Estudiante);

    ~Clase(){};
}
#endif
