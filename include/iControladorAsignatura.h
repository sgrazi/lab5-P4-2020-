#ifndef I_CONTROLADOR_ASIGNATURA_H
#define I_CONTROLADOR_ASIGNATURA_H
#include "dtDocente.h"
#include "dtAsignatura.h"
#include "tipoClase.h"
#include "DtDictado.h"
#include "docente.h"
#include "asignatura.h"
#include "clase.h"
#include <string>
#include <set>

using namespace std;

class IControladorAsignatura{
	public:

		virtual void setColDoc(map<string,Docente*>*) = 0;
		virtual void setColAsig(map<int,Asignatura*>*) = 0;
		virtual void setColCla(map<int,Clase*>*) = 0;

		virtual void agregarAsignatura(string,int,bool,bool,bool) = 0;
		virtual void confirmarAlta() = 0;
		virtual void cancelarAlta() = 0;
		virtual set<dtAsignatura> consultarAsignaturas() = 0;
		virtual map<string,dtDocente> consultarDocentesLibres(int) = 0;
		virtual void asignarDocente(string,int,tipoClase) = 0;
		virtual void confirmarAsignacion() = 0;
		virtual void cancelarAsignacion() = 0;
		virtual void eliminarAsignatura(int) = 0;
		virtual void confirmarElim() = 0;
		virtual void cancelarElim() = 0;
		virtual set<DtDictado> tiempoDictado() = 0;

		~IControladorAsignatura(){};
};
#endif
