#ifndef DT_ROL_H
#define DT_ROL_H
#include <string>

class dtRol{
  private:
    string doc; //antes tenia puntero a docente, ahora string email del doc
    int asig; //antes tenia puntero a asignatura, ahora int codigo de asig
  public:
    dtRol();
    dtRol(string d, int a);
    void setDoc(string);
    void setAsig(int);
    string getDoc();
    int getAsig();
    ~dtRol();
};
#endif
