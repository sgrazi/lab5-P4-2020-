#include "../include/estrategiaModoSus1.h"
#include "../include/usuario.h"
#include "../include/dtMensaje.h"

EstrategiaModoSus1::EstrategiaModoSus1(){};

bool EstrategiaModoSus1::aplicaNotificacion(dtMensaje d){
  int codigoClase = d->getClase();
  //ir a la clase y buscar la asignatura
  user->getClasesParticipa()->get
  //ir al usuario y ver si esta la asignatura (si es est en inscripto, si es doc en roles)
  return
};

EstrategiaModoSus1::~EstrategiaModoSus1(){};
