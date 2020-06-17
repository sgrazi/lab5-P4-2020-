#include "../include/DtTiempoDeClase.h"

DtTiempoDeClase::DtTiempoDeClase(){};
DtTiempoDeClase::DtTiempoDeClase(string n,int t,int c):nombre(n),tiempo(t),codClase(c){};
void DtTiempoDeClase::setNombre(string nombre){this->nombre = nombre;};
void DtTiempoDeClase::setTiempo(int tiempo){this->tiempo = tiempo;};
void DtTiempoDeClase::setCodClase(int cod){this->codClase = cod;};
bool DtTiempoDeClase::operator<(const DtTiempoDeClase &right) const{
    return codClase < right.codClase;
};
string DtTiempoDeClase::getNombre(){return this->nombre;};
int DtTiempoDeClase::getTiempo(){return this->tiempo;};
int DtTiempoDeClase::getCodClase(){return this->codClase;};
