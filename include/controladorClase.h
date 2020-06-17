#ifndef CONTROLADOR_CLASE_H
#define CONTROLADOR_CLASE_H
#include "tipoClase.h"
#include "dtInfoClase.h"
#include "dtFecha.h"
#include "dtAsignatura.h"
#include "dtEstudiante.h"
#include "dtClase.h"
#include "dtMensaje.h"
#include "handlerMensajes.h"
#include <string>
#include <set>
#include <map>

using namespace std;

class Asignatura;
class Estudiante;
class Docente;
class Clase;
class Mensaje;

class ControladorClase{
	private:
		string passwordUserActual;
		string emailUserActual;
		dtInfoClase* infoParaCreacionClase;
		int claseAFinalizar;
		string contenidoMensaje;
		int idAResponder;
		int codigoClase;
		HandlerMensajes* handler;
		map<int,Asignatura*>* coleccionGlobalAsignaturas;
		map<string,Estudiante*>* coleccionGlobalEstudiantes;
		map<string,Docente*>* coleccionGlobalDocentes;
		map<int,Clase*>* coleccionGlobalClases;
		map<int,Mensaje*>* coleccionGlobalMensajes;
	public:
		ControladorClase();
		void setPasswordUserActual(string);
		void setEmailUserActual(string);
		//void setInfoParaCreacionClase(dtInfoClase*);
		void setClaseAFinalizar(int);
		string getPasswordUserActual();
		string getEmailUserActual();
		//dtInfoClase* getInfoParaCreacionClase();
		int getClaseAFinalizar();
		void setContenidoMensaje(string);
		string getContenidoMensaje();
		void setIdAResponder(int);
		int getIdAResponder();
		void setCodigoClase(int);
		int getCodigoClase();
		//COLECCIONES
		void setColEst(map<string,Estudiante*>*);
		void setColDoc(map<string,Docente*>*);
		void setColAsig(map<int,Asignatura*>*);
		void setColCla(map<int,Clase*>*);
		void setColMens(map<int,Mensaje*>*);

		void setHandler(HandlerMensajes*);

		//INICIO DE CLASE
		void iniciarSesion(string,string);
		set<dtAsignatura> consultarAsignaturasDocente();
		tipoClase rolDocente(int);
		void iniciarClase(int,string,tipoClase,dtFecha);
		map<string,dtEstudiante*> consultarInscriptos();
		void agregarHabilitado(string);
		dtInfoClase desplegarInfoClase();
		void confirmarInicio();
		void cancelarInicio();

		dtFecha generarFecha();

		//FINALIZAR CLASE
		set<dtClase> consultarClasesEnVivo();
		set<dtClase> consultarClasesEnVivoDeAsig(int codigoAsig);
		void finalizarClase(int);
		void confirmarFin();
		void cancelarFin();

		//ENVIO DE MENSAJE
		set<dtClase> consultarClasesParticipando();
		set<dtMensaje> consultarMensajes(int);
		void enviarMensaje(string);
		void enviarRespuesta(int,string);
		void confirmarEnvio();
		void cancelarEnvio();

		//ASISTENCIA A CLASE EN VIVO
		set<dtAsignatura> consultarAsigIns();
		set<dtClase> consultarClasesVivo(int a);
		dtClase asistirClaseVivo(int);
		//set<dtClase> consultarClasesDiferido(int);
		//dtClase AsistirClaseDiferido(int);
		set<dtMensaje> confirmarAsistenciaDiferido();
		void confirmarAsistenciaVivo();
		void cancelarAsistencia();


		set<dtInfoClase> desplegarInfoClases(string);
		//FINALIZACION A CLASE EN VIVO
		set<dtClase*>  consultarClasesParticipandoVivo();
		void finalizarAsistencia(int codigoClase);
		void confirmarSalida();
		void cancelarSalida();

		~ControladorClase();
};
#endif
