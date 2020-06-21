#ifndef CONTROLADOR_CLASE_H
#define CONTROLADOR_CLASE_H
#include "tipoClase.h"
#include "handlerMensajes.h"
#include "iControladorClase.h"
#include <string>
#include <set>
#include <map>

using namespace std;

class Asignatura;
class Estudiante;
class Docente;
class Clase;
class Mensaje;
class Visualizacion;


class ControladorClase: public IControladorClase{
	private:
		string passwordUserActual;
		string emailUserActual;
		dtInfoClase* infoParaCreacionClase;
		string claseAFinalizar;
		string contenidoMensaje;
		int idAResponder;
		string codigoClase;
		HandlerMensajes* handler;
		map<string,Asignatura*>* coleccionGlobalAsignaturas;
		map<string,Estudiante*>* coleccionGlobalEstudiantes;
		map<string,Docente*>* coleccionGlobalDocentes;
		map<string,Clase*>* coleccionGlobalClases;
		map<int,Mensaje*>* coleccionGlobalMensajes;
		static ControladorClase* instancia;
		ControladorClase();

		Reloj* relojSistema;
	public:
		static ControladorClase* getInstancia();
		void setPasswordUserActual(string);
		void setEmailUserActual(string);
		//void setInfoParaCreacionClase(dtInfoClase*);
		void setClaseAFinalizar(string);
		string getPasswordUserActual();
		string getEmailUserActual();
		//dtInfoClase* getInfoParaCreacionClase();
		string getClaseAFinalizar();
		void setContenidoMensaje(string);
		string getContenidoMensaje();
		void setIdAResponder(int);
		int getIdAResponder();
		void setCodigoClase(string);
		string getCodigoClase();
		//COLECCIONES
		void setColEst(map<string,Estudiante*>*);
		void setColDoc(map<string,Docente*>*);
		void setColAsig(map<string,Asignatura*>*);
		void setColCla(map<string,Clase*>*);
		void setColMens(map<int,Mensaje*>*);
		void setHandler(HandlerMensajes*);

		//INICIO DE CLASE
		void iniciarSesion(string,string);
		set<dtAsignatura> consultarAsignaturasDocente();
		tipoClase rolDocente(string);
		void iniciarClase(string,string,tipoClase,dtFecha);
		map<string,dtEstudiante*> consultarInscriptos();
		void agregarHabilitado(string);
		dtInfoClase desplegarInfoClase();
		void confirmarInicio();
		void cancelarInicio();

		dtFecha generarFecha();

		//FINALIZAR CLASE
		set<dtClase> consultarClasesEnVivo();
		set<dtClase> consultarClasesEnVivoDeAsig(string codigoAsig);
		void finalizarClase(string);
		void confirmarFin();
		void cancelarFin();

		//ENVIO DE MENSAJE
		set<dtClase> consultarClasesParticipando();
		set<dtMensaje> consultarMensajes(string);
		void enviarMensaje(string);
		void enviarRespuesta(int,string);
		void confirmarEnvio();
		void cancelarEnvio();

		//ASISTENCIA A CLASE EN VIVO
		set<dtAsignatura> consultarAsigIns();
		set<dtClase> consultarClasesVivo(string a);
		dtClase asistirClaseVivo(string);
		void confirmarAsistenciaVivo();
		void cancelarAsistencia();

		//FINALIZACION ASISTENCIA A CLASE EN VIVO
		set<dtClase*>  consultarClasesParticipandoVivo();
		void finalizarAsistencia(string codigoClase);
		void confirmarSalida();
		void cancelarSalida();

		//TIEMPO DE ASISTENCIA A CLASE
		set<DtTiempoDeClase> consultarTiempoClaseDocente(string codigo);

		~ControladorClase();
};
#endif
