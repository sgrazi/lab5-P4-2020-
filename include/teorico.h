#ifndef TEORICO_H
#define TEORICO_H
#include "clase.h"

class Teorico : public Clase{
  private:
    int asistentes;
  public:
    Teorico();

    void setNombre(string);
    void setAsistentes(int);
    int getAsistentes();

    ~Teorico();
};
#endif
