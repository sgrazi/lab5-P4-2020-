#ifndef CONTROLADOR_ASIGNATURA_H
#define CONTROLADOR_ASIGNATURA_H
#include <string>
#include <set>

using namespace std;

class ControladorAsignatura{
	private:
		string emailDocente;
		string codigoAsig;
		tipoClase rolDoc;
		string asigAEliminar;
	public:
		ControladorAsignatura();
		void setEmailDocente(string);
		void setCodigoAsig(string);
		void setRolDoc(tipoClase);
		void setAsigAEliminar(string);
		string getEmailDocente();
		string getCodigoAsig();
		tipoClase getRolDoc();
		string getAsigAEliminar();

		Set<DtAsignatura> consultarAsignaturas();
		Set<DtDocente> consultarDocentesLibres(string);
		void asignarDocente(string,string,tipoClase);
		void confirmarAsignacion();
		void cancelarAsignacion();
		void eliminarAsignatura(string);
		void confirmarElim();
		void cancelarElim();

		~ControladorAsignatura();
};
#endif
