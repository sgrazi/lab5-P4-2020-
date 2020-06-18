#ifndef FACTORY_H
#define FACTORY_H

#include "iControladorClase.h"
#include "iControladorUsuario.h"
#include "iControladorAsignatura.h"

class Factory{
  public:
    static Factory* getInstancia();
    IControladorAsignatura* getIAsignatura();
    IControladorClase* getIClase();
    IControladorUsuario* getIUsuario();
    ~Factory();
  private:
    static Factory* instancia;
    Factory();
};
#endif
