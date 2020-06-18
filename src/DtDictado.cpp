#include "../include/DtDictado.h"

DtDictado::DtDictado(){};
DtDictado::DtDictado(int a,int b):codAsig(a),tiempoDictado(b){};

int DtDictado::getCodigoAsig() const { return codAsig;};
int DtDictado::getTiempoDictado() const { return tiempoDictado;};

bool DtDictado::operator<(const DtDictado &right) const{
    return codAsig < right.codAsig;
};
void DtDictado::setCodAsig(int cod){
  this->codAsig=cod;
};
void DtDictado::setTiempoDictado(int tiempo){
  this->TiempoDictado=tiempo;
};
int DtDictado::getCodAsig() const{
  return codAsig;
};
int DtDictado::getTiempoDictado() const{
  return TiempoDictado;
};
DtDictado::~DtDictado(){};
