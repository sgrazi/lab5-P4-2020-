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
		string codigoAsig;
		tipoClase rolDoc;
		int asigAEliminar;
	public:
		ControladorAsignatura();
		void setEmailDocente(string);
		void setCodigoAsig(string);
		void setRolDoc(tipoClase);
		void setAsigAEliminar(int);
		string getEmailDocente();
		string getCodigoAsig();
		tipoClase getRolDoc();
		int getAsigAEliminar();

		set<dtAsignatura> consultarAsignaturas();
		set<dtDocente> consultarDocentesLibres(string);
		void asignarDocente(string,string,tipoClase);
		void confirmarAsignacion();
		void cancelarAsignacion();
		void eliminarAsignatura(string);
		void confirmarElim();
		void cancelarElim();

		~ControladorAsignatura();
};
#endif
