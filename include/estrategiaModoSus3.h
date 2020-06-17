#ifndef ESTRATEGIA_MODO_SUS_3_H
#define ESTRATEGIA_MODO_SUS_3_H
#include "estrategiaNotifs.h"

class dtMensaje;

class EstrategiaModoSus3 : public EstrategiaNotifs{
  public:
    EstrategiaModoSus3(){};

    bool aplicaNotificacion(dtMensaje);

    ~EstrategiaModoSus3(){};
};
#endif
