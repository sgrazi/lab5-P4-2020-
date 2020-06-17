#include "../include/DtDictado.h"

DtDictado::DtDictado(){};
DtDictado::DtDictado(int a,int b):codAsig(a),TiempoDictado(b){};
bool DtDictado::operator<(const DtDictado &right) const{
    return codAsig < right.codAsig;
};
DtDictado::~DtDictado(){};
