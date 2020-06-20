#ifndef I_CONTROLADOR_USUARIO_H
#define I_CONTROLADOR_USUARIO_H

#include <string>
#include <set>
#include "dtNotificacion.h"
#include "usuario.h"
#include "estudiante.h"
#include "docente.h"
#include "asignatura.h"
#include "handlerMensajes.h"

using namespace std;

class IControladorUsuario{
	public:
		IControladorUsuario(){};

		virtual void setColUser(map<string,Usuario*>*) = 0;
		virtual void setColEst(map<string,Estudiante*>*) = 0;
		virtual void setColDoc(map<string,Docente*>*) = 0;
		virtual void setColAsig(map<int,Asignatura*>*) = 0;
		virtual void setHandler(HandlerMensajes*) = 0;

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

		virtual set<dtAsignatura> consultarAsigNoIns() = 0;
		virtual void inscribir(int) = 0;
		virtual void confirmarInscripcion() = 0;
		virtual void cancelarInscripcion() = 0;

		 ~IControladorUsuario(){};
};
#endif
