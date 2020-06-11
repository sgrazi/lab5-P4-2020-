#ifndef DT_DOCENTE_H
#define DT_DOCENTE_H
#include <string>
#include "dtUsuario.h"

class dtDocente : public dtUsuario{
  private:
    string instituto;
  public://faltan funciones de manejo de relaciones
    dtDocente();
    string getInstituto();
    void setInstituto(string);
    ~dtDocente();
};
#endif
