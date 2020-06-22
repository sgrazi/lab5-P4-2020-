#include "../include/estrategiaModoSus3.h"
//#include "../include/usuario.h"
#include "../include/dtMensaje.h"
#include "../include/mensaje.h"
#include <set>

//EstrategiaModoSus3::EstrategiaModoSus3(){};

bool EstrategiaModoSus3::aplicaNotificacion(dtMensaje d){
  int id = d.getEnRespuestaA();
  bool res = false;
  set<int> ids = getUser()->getIdMensajes();
  if(ids.count(id))
    res=true;

  /*
  if(id!=-1){//si es mensaje es una respuesta
    bool encontre = false;
    auto it = getUser()->getMensajes().begin();
    unsigned int i = 0;
    while (i!=getUser()->getMensajes().size() && !encontre){ //busco si fue una respuesta a algo del usuario
      if((*it)->getId() == id){
          res = true;
          encontre = true;
          break;
      }
      ++it;
      i++;
    }
  }*/

  return res;
};

//EstrategiaModoSus3::~EstrategiaModoSus3();
