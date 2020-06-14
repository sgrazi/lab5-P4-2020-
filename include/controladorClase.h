#ifndef CONTROLADOR_CLASE_H
#define CONTROLADOR_CLASE_H
#include "dtInfoClase.h"
#include "dtFecha.h"
#include "dtAsignatura.h"
#include "dtEstudiante.h"
#include "dtClase.h"
#include "dtMensaje.h"
#include <string>
#include <set>

using namespace std;

class ControladorClase{
	private:
		string passwordUserActual;
		string emailUserActual;
		DtInfoClase infoParaCreacionClase;
		int claseAFinalizar;
		map<int,Asignatura*>* coleccionGlobalAsignaturas;
		map<string,Estudiante*>* coleccionGlobalEstudiantes;
		map<string,Docente*>* coleccionGlobalDocentes;
	public:
		ControladorClase();
		void setPasswordUserActual(string);
		void setEmailUserActual(string);
		void setInfoParaCreacionClase(DtInfoClase);
		void setClaseAFinalizar(int);
		string getPasswordUserActual();
		string getEmailUserActual();
		DtInfoClase getInfoParaCreacionClase();
		int getClaseAFinalizar();
		//COLECCIONES
		void setColEst(map<string,Estudiante*>*);
		void setColDoc(map<string,Docente*>*);
		void setColAsig(map<int,Asignatura*>*);
		//inicio de clase
		void iniciarSesion(string,string);
		set<DtAsignatura> consultarAsignaturasDocente();
		DtInfoClase infoDocente(string);
		void iniciarClase(string,string,DtFecha);
		set<DtEstudiante> consultarInscriptos();
		void agregarHabilitado(string);
		DtInfoClase desplegarInfoClase();
		void confirmarInicio();
		void cancelarInicio();

		string generarCodigo();
		string generarUrl(clase);
		DtFecha generarFecha();
		set<DtClase> consultarClasesEnVivo();
		DtClase finalizarClase(string);
		void confirmarFin();
		void cancelarFin();
		set<DtAsignatura> consultarAsigIns();
		set<DtClase> consultarClasesDiferido(string);
		DtClase AsistirClaseDiferido(string);
		set<DtMensaje> confirmarAsistencia();
		void cancelarAsistencia();
		set<DtInfoClase> desplegarInfoClases(string);
		void confirmarEnvio();

		~ControladorClase()
};
#endif
