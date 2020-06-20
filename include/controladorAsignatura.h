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
		int codigoAsig;
		bool aceptaTeo;
		bool aceptaPra;
		bool aceptaMon;
		tipoClase rolDoc;
		int asigAEliminar;
		map<int,Asignatura*>* coleccionGlobalAsignaturas;
		map<string,Docente*>* coleccionGlobalDocentes;
		map<int,Clase*>* coleccionGlobalClases;
		static ControladorAsignatura* instancia;
		ControladorAsignatura();
	public:
		static ControladorAsignatura* getInstancia();
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

		//colecciones
		void setColAsig(map<int,Asignatura*>*);
		void setColDoc(map<string,Docente*>*);
		void setColCla(map<int,Clase*>*);
		//ALTA DE ASIG
		void agregarAsignatura(string,int,bool,bool,bool);
		void confirmarAlta();
		void cancelarAlta();
		//ASIGNACION DE DOC A ASIG
		set<dtAsignatura> consultarAsignaturas();
		map<string,dtDocente> consultarDocentesLibres(int); //list porque no esta definido como ordenar a los docentes en un map
		bool asignarDocente(string,int,tipoClase);
		void confirmarAsignacion();
		void cancelarAsignacion();

		//ELIM DE ASIG
		void eliminarAsignatura(int);
		void confirmarElim();
		void cancelarElim();

		//TIEMPO DICTADO CLASES
		set<DtDictado> tiempoDictado();

		~ControladorAsignatura();
};
#endif
