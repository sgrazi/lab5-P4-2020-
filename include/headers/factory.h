#ifndef FACTORY_H
#define FACTORY_H

class Factory{
  public:
    Factory();

    Asignatura getAsignatura();
    Clase getClase();
    Usuario getUsuario();

    ~Factory();
};
#endif
