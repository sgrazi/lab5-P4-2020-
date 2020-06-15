#ifndef DT_NOTIFICACIONES_H
#define DT_NOTIFICACIONES_H
#include <iostream>
#include <string>
using namespace std;

class dtNotificacion {
private:
  int codigoAsig;
  int codigoClase;
  int idMensaje;
  string contenidoMensaje;
public:
  dtNotificacion();

  void setCodigoAsig(int);
  void setCodigoClase(int);
  void setIdMensaje(int);
  void setContenidoMensaje(string);
  int getCodigoAsig();
  int getCodigoClase();
  int getIdMensaje();
  string getContenidoMensaje();

  ~dtNotificacion();
};
#endif
