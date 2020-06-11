#ifndef ESTRATEGIA_MODO_SUS_3_H
#define ESTRATEGIA_MODO_SUS_3_H
#include "estrategiaNotifs.h"

class EstrategiaModoSus3 : public EstrategiaNotifs{
  public:
    EstrategiaModoSus3();

    bool aplicaNotificacion();

    ~EstrategiaModoSus3();
};
#endif
