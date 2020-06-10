all: mainpruebas

HDIR = include/headers
CPPDIR  = src
CLASES = controladorUsuario usuario docente estudiante rol 

PUNTOH  = $(CLASES:%=$(HDIR)/%.h)

PUNTOCPP = $(CLASES:%=$(CPPDIR)/%.cpp)

OS = $(CLASES:%=%.o)

PRINCIPAL = mainpruebas
EJECUTABLE = mainpruebas
# compilador
CC = g++
# opciones de compilación
CCFLAGS = -Wall

$(PRINCIPAL).o:$(PRINCIPAL).cpp
	$(CC) $(CCFLAGS) -c $< -o $@

# cada .o depende de su .cpp
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
%.o: $(CPPDIR)/%.cpp $(HDIR)/%.h
	$(CC) $(CCFLAGS) -c $< -o $@

# $^ se expande para tranformarse en todas las dependencias
$(EJECUTABLE): $(PRINCIPAL).o $(OS)
	$(CC) $(CCFLAGS) $^ -o $@

#CPPDIR  = src/dts
#HDIR = include/dts
#CLASES = dtDocente dtEstudiante

#PUNTOH  = $(CLASES:%=$(HDIR)/%.h)

#PUNTOCPP = $(CLASES:%=$(CPPDIR)/%.cpp)

#OS = $(CLASES:%=%.o)

# cada .o depende de su .cpp
# $@ se expande para tranformarse en el objetivo
# $< se expande para tranformarse en la primera dependencia
#%.o: $(CPPDIRDTS)/%.cpp $(HDIR)/%.h
#	$(CC) $(CCFLAGS) -c $< -o $@

# $^ se expande para tranformarse en todas las dependencias
#$(EJECUTABLE): $(PRINCIPAL).o $(OS)
#	$(CC) $(CCFLAGS) $^ -o $@

clean:
	rm controladorUsuario.o
	rm docente.o
	rm estudiante.o
	rm iControladorUsuario.o
	rm dtDocente.o
	rm dtEstudiante.o
