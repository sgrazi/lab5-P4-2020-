#ifndef ROL_H
#define ROL_H
#include <string>
#include "docente.h"
#include "asignatura.h"
#include "dtClase.h"

using namespace std;

class Rol{
  private:
    tipoClase Dicta;
    Docente *doc;
    Asignatura *asig;
  public:
    Rol();
    Rol(Docente* d, Asignatura* a);
    void setDoc(Docente*);
    void setAsig(Asignatura*);
    Docente* getDoc();
    Asignatura* getAsig();
    //int getCodigoAsig();
    ~Rol();
};
#endif
