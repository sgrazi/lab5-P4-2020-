#include <stdio.h>
#include <iostream>

using namespace std;

class DtFecha {
private:
int anio;
int mes;
int dia;
int hora;
int minuto;
int segundo;

public:
dtFecha();
void setanio(int);
void setmes(int);
void setdia(int);
void sethora(int);
void setminuto(int);
void setsegundo(int);
DtFecha getFecha();
~DtFecha();

};
