#ifndef CONTROLADOR_ASIGNATURA_H
#define CONTROLADOR_ASIGNATURA_H

#include <iostream>

#include "asignatura.h"
#include "dtAsignatura.h"
#include "dtDocente.h"
#include "tipoClase.h"

#include <string>
#include <set>
#include <map>

using namespace std;


class ControladorAsignatura{
	private:
		string emailDocente;
		int codigoAsig;
		tipoClase rolDoc;
		int asigAEliminar;
		map<int,Asignatura*>* coleccionGlobalAsignaturas;
		map<string,Docente*>* coleccionGlobalDocentes;
	public:
		ControladorAsignatura();
		void setEmailDocente(string);
		void setCodigoAsig(int);
		void setRolDoc(tipoClase);
		void setAsigAEliminar(int);
		string getEmailDocente();
		int getCodigoAsig();
		tipoClase getRolDoc();
		int getAsigAEliminar();

		void setColAsig(map<int,Asignatura*>*);
		void setColDoc(map<string,Docente*>*);

		void agregarAsignatura(string,int,bool,bool,bool);
		void confirmarAlta();
		void cancelarAlta();
		set<dtAsignatura> consultarAsignaturas();
		map<string,dtDocente> consultarDocentesLibres(int); //list porque no esta definido como ordenar a los docentes en un map
		void asignarDocente(string,int,tipoClase);
		void confirmarAsignacion();
		void cancelarAsignacion();
		void eliminarAsignatura(string);
		void confirmarElim();
		void cancelarElim();

		~ControladorAsignatura();
};
#endif
