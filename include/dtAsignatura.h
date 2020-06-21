#ifndef DT_ASIGNATURA_H
#define DT_ASIGNATURA_H

#include <string>

using namespace std;

class dtAsignatura{
  private:
    string codigo;
    string nombre;
    bool teorico;
    bool monitoreo;
    bool practico;
  public:
    dtAsignatura();
    void setCodigo(string);
    void setNombre(string);
    void setTeorico(bool);
    void setPractico(bool);
    void setMonitoreo(bool);
    string getCodigo() const;
    string getNombre() const;
    bool getTeorico() const;
    bool getPractico() const;
    bool getMonitoreo() const;
    ~dtAsignatura();
    bool operator<(const dtAsignatura &right)const; //si colecciones se implementan con set esto es necesario
};

#endif
