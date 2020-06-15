#ifndef ESTRATEGIA_MODO_SUS_2_H
#define ESTRATEGIA_MODO_SUS_2_H
#include "estrategiaNotifs.h"

class dtMensaje;

class EstrategiaModoSus2 : public EstrategiaNotifs{
  public:
    EstrategiaModoSus2();

    bool aplicaNotificacion(dtMensaje);

    ~EstrategiaModoSus2();
};
#endif
