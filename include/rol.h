#ifndef ROL_H
#define ROL_H
#include <string>
#include "docente.h"
#include "asignatura.h"
#include "dtClase.h"

using namespace std;

class Rol{
  private:
    tipoClase dicta;
    Docente *doc;
    Asignatura *asig;
  public:
    Rol();
    Rol(Docente* d, Asignatura* a);
    void setDicta(tipoClase);
    tipoClase getDicta();
    void setDoc(Docente*);
    void setAsig(Asignatura*);
    Docente* getDoc();
    Asignatura* getAsig();
    int getCodigoAsig();
    ~Rol();
};
#endif
