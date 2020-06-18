#ifndef I_CONTROLADOR_USUARIO_H
#define I_CONTROLADOR_USUARIO_H

#include <string>
#include <set>
#include "dtNotificacion.h"

using namespace std;

class IControladorUsuario{
	public:
		IControladorUsuario(){};
		virtual void iniciarSesion(string,string) = 0;
		virtual void agregarEstudiante(string,string,string,string,string) = 0;
		virtual void agregarDocente(string,string,string,string,string) = 0;
		virtual void confirmarAlta() = 0;
		virtual void cancelarAlta() = 0;
		virtual set<dtNotificacion*> consultarNotifs() = 0; 
		virtual void cambiarModoSus(int) = 0;
		virtual void cancelarCambio() = 0;
		virtual void confirmarCambio() = 0;
		virtual void desuscribirse() = 0;

		 ~IControladorUsuario(){};
};
#endif
