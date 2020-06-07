#ifndef ASIGNATURA_H
#define ASIGNATURA_H

class Asignatura{
  private:
    string codigo;
    string nombre;
    bool teorico;
    bool monitoreo;
    bool practico;
  public:
    Asignatura();
    void setCodigo(string);
    void setNombre(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    string getCodigo();
    string getNombre();
    bool getTeorico();
    bool getPractico();
    bool getMonitoreo();
    ~Asignatura();
};

#endif
