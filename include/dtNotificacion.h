#ifndef DT_NOTIFICACIONES_H
#define DT_NOTIFICACIONES_H
#include <iostream>
#include <string>
using namespace std;

class dtNotificacion {
private:
  string codigoAsig;
  string codigoClase;
  int idMensaje;
  string contenidoMensaje;
public:
  dtNotificacion();

  void setCodigoAsig(string);
  void setCodigoClase(string);
  void setIdMensaje(int);
  void setContenidoMensaje(string);
  string getCodigoAsig() const ;
  string getCodigoClase() const ;
  int getIdMensaje() const ;
  string getContenidoMensaje() const ;

  ~dtNotificacion();

  bool operator<(const dtNotificacion &right) const {return true;};
};
#endif
