all: mainpruebas

HDIR = include
CPPDIR  = src
ODIR = obj

CLASES = controladorUsuario usuario docente estudiante dtUsuario dtDocente dtEstudiante dtAsignatura controladorAsignatura asignatura rol

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
	rm obj/controladorUsuario.o
	#rm obj/iControladorUsuario.o
	rm obj/dtDocente.o
	rm obj/dtEstudiante.o
	rm obj/docente.o
	rm obj/estudiante.o
	rm obj/usuario.o
	rm obj/mainpruebas.o
