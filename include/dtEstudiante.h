#ifndef DT_ESTUDIANTE_H
#define DT_ESTUDIANTE_H
#include <string>
#include <iostream>
#include "dtUsuario.h"
using namespace std;

class dtEstudiante : public dtUsuario {
  private:
    string ci;
  public:
    dtEstudiante();
    void setCI(string);
    string getCI();

    ~dtEstudiante();
};
#endif
