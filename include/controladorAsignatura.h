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
		string nombreAsig;
		int codigoAsig;
		bool aceptaTeo;
		bool aceptaPra;
		bool aceptaMon;
		tipoClase rolDoc;
		int asigAEliminar;
		map<int,Asignatura*>* coleccionGlobalAsignaturas;
		map<string,Docente*>* coleccionGlobalDocentes;
	public:
		ControladorAsignatura();
		void setEmailDocente(string);
		void setNombreAsig(string);
		void setCodigoAsig(int);
		void setAceptaTeo(bool);
		void setAceptaPra(bool);
		void setAceptaMon(bool);
		void setRolDoc(tipoClase);
		void setAsigAEliminar(int);
		string getEmailDocente();
		string getNombreAsig();
		int getCodigoAsig();
		bool getAceptaTeo();
		bool getAceptaPra();
		bool getAceptaMon();
		tipoClase getRolDoc();
		int getAsigAEliminar();
		void setNombreAsig();

		//colecciones
		void setColAsig(map<int,Asignatura*>*);
		void setColDoc(map<string,Docente*>*);
		//ALTA DE ASIG
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
