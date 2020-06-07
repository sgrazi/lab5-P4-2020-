#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

class Estudiante : public Usuario{
  private:
    string ci;
    set(Asignatura) asignaturas;
    set(EstCla) clasesParticipa;
    set(Monitoreo) monHabilitados;
  public://faltan funciones de manejo de relaciones
    Estudiante();
    void setCI(string);
    string getCI();

    void desinscribir(string);

    ~Estudiante();
}
#endif
