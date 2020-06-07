all: main
HDIR    = include
CPPDIR  = src

CLASES = dtfecha dtbarco dtpuerto dtbarcopasajeros dtbarcopesquero barco barcopasajeros barcopesquero dtarribo arribo puerto

PUNTOH   = $(CLASES:%=$(HDIR)/%.h)
PUNTOCPP = $(CLASES:%=$(CPPDIR)/%.cpp)
OS   = $(CLASES:%=%.o)

PRINCIPAL=main
EJECUTABLE=main

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

clean:
	rm arribo.o
	rm barco.o
	rm barcopasajeros.o
	rm barcopesquero.o
	rm dtarribo.o
	rm dtbarco.o
	rm dtbarcopasajeros.o
	rm dtbarcopesquero.o
	rm dtfecha.o
	rm dtpuerto.o
	rm puerto.o
	rm main.o
	rm main



