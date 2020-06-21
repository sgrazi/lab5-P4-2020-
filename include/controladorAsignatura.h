#ifndef CONTROLADOR_ASIGNATURA_H
#define CONTROLADOR_ASIGNATURA_H

#include <iostream>

#include "asignatura.h"
#include "iControladorAsignatura.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class ControladorAsignatura:public IControladorAsignatura{
	private:
		string emailDocente;
		string nombreAsig;
		string codigoAsig;
		bool aceptaTeo;
		bool aceptaPra;
		bool aceptaMon;
		tipoClase rolDoc;
		string asigAEliminar;
		map<string,Asignatura*>* coleccionGlobalAsignaturas;
		map<string,Docente*>* coleccionGlobalDocentes;
		map<string,Clase*>* coleccionGlobalClases;
		static ControladorAsignatura* instancia;
		ControladorAsignatura();
	public:
		static ControladorAsignatura* getInstancia();
		void setEmailDocente(string);
		void setNombreAsig(string);
		void setCodigoAsig(string);
		void setAceptaTeo(bool);
		void setAceptaPra(bool);
		void setAceptaMon(bool);
		void setRolDoc(tipoClase);
		void setAsigAEliminar(string);
		string getEmailDocente();
		string getNombreAsig();
		string getCodigoAsig();
		bool getAceptaTeo();
		bool getAceptaPra();
		bool getAceptaMon();
		tipoClase getRolDoc();
		string getAsigAEliminar();

		//colecciones
		void setColAsig(map<string,Asignatura*>*);
		void setColDoc(map<string,Docente*>*);
		void setColCla(map<string,Clase*>*);
		//ALTA DE ASIG
		void agregarAsignatura(string,string,bool,bool,bool);
		void confirmarAlta();
		void cancelarAlta();
		//ASIGNACION DE DOC A ASIG
		set<dtAsignatura> consultarAsignaturas();
		map<string,dtDocente> consultarDocentesLibres(string); //list porque no esta definido como ordenar a los docentes en un map
		bool asignarDocente(string,string,tipoClase);
		void confirmarAsignacion();
		void cancelarAsignacion();

		//ELIM DE ASIG
		void eliminarAsignatura(string);
		void confirmarElim();
		void cancelarElim();

		//TIEMPO DICTADO CLASES
		set<DtDictado> tiempoDictado();

		~ControladorAsignatura();
};
#endif
