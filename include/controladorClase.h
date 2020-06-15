#ifndef CONTROLADOR_CLASE_H
#define CONTROLADOR_CLASE_H
#include "tipoClase.h"
#include "dtInfoClase.h"
#include "dtFecha.h"
#include "dtAsignatura.h"
#include "dtEstudiante.h"
#include "dtClase.h"
#include "dtMensaje.h"
#include <string>
#include <set>
#include <map>

using namespace std;

class Asignatura;
class Estudiante;
class Docente;
class Clase;

class ControladorClase{
	private:
		string passwordUserActual;
		string emailUserActual;
		dtInfoClase* infoParaCreacionClase;
		int claseAFinalizar;
		map<int,Asignatura*>* coleccionGlobalAsignaturas;
		map<string,Estudiante*>* coleccionGlobalEstudiantes;
		map<string,Docente*>* coleccionGlobalDocentes;
		map<int,Clase*>* coleccionGlobalClases;
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
		//COLECCIONES
		void setColEst(map<string,Estudiante*>*);
		void setColDoc(map<string,Docente*>*);
		void setColAsig(map<int,Asignatura*>*);
		void setColCla(map<int,Clase*>*);

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
		set<dtClase> consultarClasesEnVivoDeAsig(string codigoAsig);
		void finalizarClase(int);
		void confirmarFin();
		void cancelarFin();

		//ENVIO DE MENSAJE
		/*set<DtClase> consultarClasesParticipando();
		set<DtMensaje> consultarMensajes(int);
		void enviarMensaje(string);
		void enviarRespuesta(string,string);
		void confirmarEnvio();
		void cancelarEnvio();*/

		//ASISTENCIA A CLASE EN VIVO
		set<dtAsignatura> consultarAsigIns();
		set<dtClase> AsistirClaseVivo(int);
		set<dtClase> consultarClasesDiferido(int);
		dtClase AsistirClaseDiferido(int);
		set<dtMensaje> confirmarAsistenciaDiferido();
		void confirmarAsistenciaVivo();
		void cancelarAsistencia();


		set<dtInfoClase> desplegarInfoClases(string);
		void confirmarEnvio();

		~ControladorClase();
};
#endif
