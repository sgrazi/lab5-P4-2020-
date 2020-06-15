#include "../include/estrategiaModoSus3.h"
#include "../include/usuario.h"
#include "../include/dtMensaje.h"

EstrategiaModoSus3();

bool aplicaNotificacion(dtMensaje d){
  int id = d.getEnRespuestaA();
  bool res = false;
  if(id!=-1){//si es mensaje es una respuesta
    bool encontre = false;
    auto it = user->getMensajes()->begin();
    while (it!=user->getMensajes()->end() && !encontre){ //busco si fue una respuesta a algo del usuario
      if((*it)->getId() == id){
          res = true;
          encontre = true;
      }
    }
  }
  return res;
};

~EstrategiaModoSus3();
