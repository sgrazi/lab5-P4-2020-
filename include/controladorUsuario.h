#ifndef CONTROLADOR_USUARIO_H
#define CONTROLADOR_USUARIO_H

#include <iostream>

#include "dtNotificacion.h"
#include "iControladorUsuario.h"
#include "usrCla.h"
#include "estudiante.h"
#include "handlerMensajes.h"
#include "docente.h"


#include <map>
#include <set>
#include <string>

using namespace std;


class ControladorUsuario: public IControladorUsuario{
	private:
		bool userEsEst;
		string nombreUser;
		string contraseniaUser;
		string emailUser;
		string urlUser;
		string institutoDoc;
		string cedulaEst;
		string nombreUserActual;
		string emailUserActual;
		int nuevoModoSus;
		int asignaturaAIns;
		HandlerMensajes* handler;
		map<string,Usuario*>* ColeccionGlobalUsuarios;
		map<string,Estudiante*>* coleccionGlobalEstudiantes;
		map<string,Docente*>* coleccionGlobalDocentes;
		map<int,Asignatura*>* coleccionGlobalAsignaturas;
		static ControladorUsuario* instancia;
		ControladorUsuario();

	public:
		static ControladorUsuario* getInstancia();
		bool getUserEsEst();
		string getNombreUser();
		string getPasswordUser();
		string getEmailUser();
		string getUrlUser();
		string getInstitutoDoc();
		string getCedulaEst();
		string getNombreUserActual();
		string getEmailUserActual();
		int getNuevoModoSus();
		int getAsignaturaAIns();
		void setUserEsEst(bool);
		void setNombreUser(string);
		void setPasswordUser(string);
		void setEmailUser(string);
		void setUrlUser(string);
		void setInstitutoDoc(string);
		void setCedulaEst(string);
		void setNombreUserActual(string);
		void setEmailUserActual(string);
		void setNuevoModoSus(int);
		void setAsignaturaAIns(int);
		//COLECCIONES
		void setColUser(map<string,Usuario*>*);
		void setColEst(map<string,Estudiante*>*);
		void setColDoc(map<string,Docente*>*);
		void setColAsig(map<int,Asignatura*>*);

		void setHandler(HandlerMensajes*);

		void iniciarSesion(string,string);

		//ALTA DE USUARIO
		void agregarEstudiante(string,string,string,string,string);
		void agregarDocente(string,string,string,string,string);
		void confirmarAlta();
		void cancelarAlta();

		//INSCRIPCION A ASIGNATURA
		set<dtAsignatura> consultarAsigNoIns();
		void inscribir(int);
		void confirmarInscripcion();
		void cancelarInscripcion();

		//SUSCRIBIRSE A NOTIFICACIONES
		void cambiarModoSus(int);
		void cancelarCambio();
		void confirmarCambio();

		//CONSULTAR NOTIFICACIONES
		set<dtNotificacion> consultarNotifs();

		void desuscribirse();

		~ControladorUsuario();
};
#endif
