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
  int getCodigoAsig() const ;
  int getCodigoClase() const ;
  int getIdMensaje() const ;
  string getContenidoMensaje() const ;

  ~dtNotificacion();

  bool operator<(const dtNotificacion &right) const {return true;};
};
#endif
