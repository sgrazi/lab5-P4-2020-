all: mainpruebas

HDIR = include
CPPDIR  = src
ODIR = obj

CLASES = dtFecha controladorUsuario usuario docente estudiante dtUsuario dtDocente dtEstudiante dtAsignatura controladorAsignatura asignatura rol dtInfoClase controladorClase mensaje clase teorico practico monitoreo usrCla dtClase visualizacion dtMensaje dtNotificacion handlerMensajes DtDictado estrategiaNotifs estrategiaModoSus3 DtTiempoDeClase

# cadena de archivos, con directorio y extensión
HS   = $(CLASES:%=$(HDIR)/%.h)
CPPS = $(CLASES:%=$(CPPDIR)/%.cpp)
OS   = $(CLASES:%=$(ODIR)/%.o)

PRINCIPAL = mainpruebas
EJECUTABLE = mainpruebas

# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall

$(ODIR)/$(PRINCIPAL).o:$(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .cpp
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
$(ODIR)/%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(ODIR)/$(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@


clean:
	rm obj/dtFecha.o
	rm obj/controladorUsuario.o
	rm obj/usuario.o
	rm obj/docente.o
	rm obj/estudiante.o
	rm obj/dtUsuario.o
	rm obj/dtDocente.o
	rm obj/dtEstudiante.o
	rm obj/dtAsignatura.o
	rm obj/controladorAsignatura.o
	rm obj/asignatura.o
	rm obj/rol.o
	rm obj/controladorClase.o
	rm obj/mainpruebas.o
	rm obj/clase.o
	rm obj/teorico.o
	rm obj/practico.o
	rm obj/monitoreo.o
	rm obj/mensaje.o
	rm obj/usrCla.o
	rm obj/dtClase.o
	rm obj/visualizacion.o
	rm obj/dtMensaje.o
	rm obj/DtDictado.o
	rm obj/DtTiempoDeClase.o
	rm obj/estrategiaNotifs.o
	rm obj/estrategiaModoSus3.o
