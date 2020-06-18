#ifndef I_CONTROLADOR_CLASE_H
#define I_CONTROLADOR_CLASE_H

#include "dtClase.h"
#include "dtAsignatura.h"
#include "dtInfoClase.h"
#include "dtEstudiante.h"
#include "dtMensaje.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class IControladorClase{
	public:
		virtual void iniciarSesion(string,string) = 0;
		virtual set<dtAsignatura> consultarAsignaturasDocente() = 0;
		//virtual dtInfoClase infoDocente(string) = 0;
		virtual void iniciarClase(int,string,tipoClase,dtFecha) = 0;
		virtual dtFecha generarFecha() = 0;
		virtual map<string,dtEstudiante*> consultarInscriptos() = 0;
		virtual void agregarHabilitado(string) = 0;
		virtual dtInfoClase desplegarInfoClase() = 0;
		virtual void confirmarInicio() = 0;
		virtual void cancelarInicio() = 0;
		virtual set<dtClase> consultarClasesEnVivo() = 0;
		virtual void finalizarClase(int) = 0;
		virtual void confirmarFin() = 0;
		virtual void cancelarFin() = 0;
		virtual set<dtAsignatura> consultarAsigIns() = 0;
		//virtual set<dtClase> consultarClasesDiferido(string) = 0;
		//virtual dtClase AsistirClaseDiferido(string) = 0;
		//virtual set<dtMensaje> confirmarAsistencia() = 0;
		virtual void cancelarAsistencia() = 0;
		//virtual set<dtInfoClase> desplegarInfoClases(string) = 0;
		virtual void confirmarEnvio() = 0;

		~IControladorClase(){};
};
#endif
