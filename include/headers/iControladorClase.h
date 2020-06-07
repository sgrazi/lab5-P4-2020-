#ifndef I_CONTROLADOR_CLASE_H
#define I_CONTROLADOR_CLASE_H

class IControladorClase{
	public:
		virtual void iniciarSesion(string,string) = 0;
		virtual set(DtAsignatura) consultarAsignaturasDocente() = 0;
		virtual DtInfoClase infoDocente(string) = 0;
		virtual void iniciarClase(string,string,DtFecha) = 0;
		virtual string generarCodigo() = 0;
		virtual string generarUrl(clase) = 0;
		virtual DtFecha generarFecha() = 0;
		virtual set(DtEstudiantes) consultarInscriptos() = 0;
		virtual void agregarHabilitado(string) = 0;
		virtual DtInfoClase desplegarInfoClase() = 0;
		virtual void confirmarInicio() = 0;
		virtual void cancelarInicio() = 0;
		virtual set(DtClase) consultarClasesEnVivo() = 0;
		virtual DtClase finalizarClase(string) = 0;
		virtual void confirmarFin() = 0;
		virtual void cancelarFin() = 0;
		virtual set(DtAsignatura) consultarAsigIns() = 0;
		virtual set(DtClase) consultarClasesDiferido(string) = 0;
		virtual DtClase AsistirClaseDiferido(string) = 0;
		virtual set(DtMensaje) confirmarAsistencia() = 0;
		virtual void cancelarAsistencia() = 0;
		virtual set(DtInfoClase) desplegarInfoClases(string) = 0;
		virtual void confirmarEnvio() = 0;

		virtual ~IControladorClase(){};
}
#endif
