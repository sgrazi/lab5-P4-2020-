#include "../include/DtTiempoDeClase.h"

DtTiempoDeClase::DtTiempoDeClase(){
  tiempo = 0;
};
DtTiempoDeClase::DtTiempoDeClase(string n,int t,int c):nombre(n),tiempo(t),codClase(c){};
void DtTiempoDeClase::setNombre(string nombre){this->nombre = nombre;};
void DtTiempoDeClase::setTiempo(int tiempo){this->tiempo = tiempo;};
void DtTiempoDeClase::setCodClase(int cod){this->codClase = cod;};
bool DtTiempoDeClase::operator<(const DtTiempoDeClase &right) const{
    return codClase < right.codClase;
};
string DtTiempoDeClase::getNombre() const {return this->nombre;};
int DtTiempoDeClase::getTiempo() const {return this->tiempo;};
int DtTiempoDeClase::getCodClase() const {return this->codClase;};
