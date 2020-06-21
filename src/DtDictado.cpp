#include "../include/DtDictado.h"

DtDictado::DtDictado(){};
DtDictado::DtDictado(string a,int b):codAsig(a),TiempoDictado(b){};

bool DtDictado::operator<(const DtDictado &right) const{
    return codAsig < right.codAsig;
};
void DtDictado::setCodAsig(string cod){
  this->codAsig=cod;
};
void DtDictado::setTiempoDictado(int tiempo){
  this->TiempoDictado=tiempo;
};
string DtDictado::getCodAsig() const{
  return codAsig;
};
int DtDictado::getTiempoDictado() const{
  return TiempoDictado;
};
DtDictado::~DtDictado(){};
