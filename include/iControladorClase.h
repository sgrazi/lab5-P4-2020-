#ifndef I_CONTROLADOR_CLASE_H
#define I_CONTROLADOR_CLASE_H

#include "dtClase.h"
#include "dtAsignatura.h"
#include "dtInfoClase.h"
#include "dtEstudiante.h"
#include "dtMensaje.h"
#include "dtFecha.h"
#include "DtTiempoDeClase.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class IControladorClase{
	public:
		virtual void iniciarSesion(string,string) = 0;
		virtual set<dtAsignatura> consultarAsignaturasDocente() = 0;
		virtual tipoClase rolDocente(int) = 0;
		virtual void iniciarClase(int,string,tipoClase,dtFecha) = 0;
		virtual map<string,dtEstudiante*> consultarInscriptos() = 0;
		virtual void agregarHabilitado(string) = 0;
		virtual dtInfoClase desplegarInfoClase() = 0;
		virtual void confirmarInicio() = 0;
		virtual void cancelarInicio() = 0;
		virtual dtFecha generarFecha() = 0;
		virtual set<dtClase> consultarClasesEnVivo() = 0;
		virtual set<dtClase> consultarClasesEnVivoDeAsig(int codigoAsig) = 0;
		virtual void finalizarClase(int) = 0;
		virtual void confirmarFin() = 0;
		virtual void cancelarFin() = 0;
		virtual set<dtClase> consultarClasesParticipando() = 0;
		virtual set<dtMensaje> consultarMensajes(int) = 0;
		virtual void enviarMensaje(string) = 0;
		virtual void enviarRespuesta(int,string) = 0;
		virtual void confirmarEnvio() = 0;
		virtual void cancelarEnvio() = 0;
		virtual set<dtAsignatura> consultarAsigIns() = 0;
		virtual set<dtClase> consultarClasesVivo(int a) = 0;
		virtual dtClase asistirClaseVivo(int) = 0;
		virtual void confirmarAsistenciaVivo() = 0;
		virtual void cancelarAsistencia() = 0;
		virtual set<dtClase*>  consultarClasesParticipandoVivo() = 0;
		virtual void finalizarAsistencia(int) = 0;
		virtual void confirmarSalida() = 0;
		virtual void cancelarSalida() = 0;
		virtual set<DtTiempoDeClase> consultarTiempoClaseDocente(int ) = 0;
		~IControladorClase(){};
};
#endif
