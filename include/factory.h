#ifndef FACTORY_H
#define FACTORY_H

class Factory{
  public:
    Factory();

    Asignatura getIAsignatura();
    Clase getIClase();
    Usuario getIUsuario();

    ~Factory();
};
#endif
