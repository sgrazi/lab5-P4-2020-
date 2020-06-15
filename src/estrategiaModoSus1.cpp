#include "../include/estrategiaModoSus1.h"
#include "../include/usuario.h"
#include "../include/dtMensaje.h"

EstrategiaModoSus1::EstrategiaModoSus1(){};

bool EstrategiaModoSus1::aplicaNotificacion(dtMensaje d){
  /*int codigoAsignatura = d->getAsignatura();
  //ir al usuario y ver si esta la asignatura (si es est en inscripto, si es doc en roles)
  bool res = false;

  //si es estudiante
  auto it = user->getAsignaturas()->begin();
  while(it!=user->getClasesParticipa()->end() && !res){
    if(it->second->getCodigoAsig() == codigoAsignatura)
      res = true;
    ++it;
  }*/

  return false;
};

EstrategiaModoSus1::~EstrategiaModoSus1(){};
