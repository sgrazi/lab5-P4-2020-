#ifndef ESTRATEGIA_MODO_SUS_1_H
#define ESTRATEGIA_MODO_SUS_1_H
#include "estrategiaNotifs.h"

class EstrategiaModoSus1 : public EstrategiaNotifs{
  public:
    EstrategiaModoSus1();

    bool aplicaNotificacion();

    ~EstrategiaModoSus1();
};
#endif
