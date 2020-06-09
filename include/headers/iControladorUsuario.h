#ifndef I_CONTROLADOR_USUARIO_H
#define I_CONTROLADOR_USUARIO_H

#include <string>
#include <set>
#include"../dts/dtNotificacion.h"

using namespace std;

class IControladorUsuario{
	public:
		virtual void iniciarSesion(string,string) = 0;
		virtual void agregarEstudiante(string,string,string,string,string) = 0;
		virtual void agregarDocente(string,string,string,string,string) = 0;
		virtual void confirmarAlta() = 0;
		virtual void cancelarAlta() = 0;
		virtual set<DtNotifiacion> consultarNotifs() = 0; //??? set ???
		virtual void cambiarModoSus(int) = 0;
		virtual void cancelarCambio() = 0;
		virtual void confirmarCambio() = 0;
		virtual void desuscribirse() = 0;

		virtual ~IControladorUsuario(){};
};
#endif
