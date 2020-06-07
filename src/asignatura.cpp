#include "../include/headers/asignatura.h"

Asignatura(){};

void setCodigo(int c){ this->codigo = c;};
int getCodigo() const{ return codigo;};

void setNombre(string n){ this->nombre = n;};
string getNombre()const{ return nombre;};

void setTeorico(bool t){  this->teorico = t;};
bool getTeorico() const{ return teorico;};

void setPractico(bool p){ this->practico = p;};
bool getPractico() const{ return practico;};

void setMonitoreo(bool m){ this->monitoreo = m;};
bool getMonitoreo() const{  return monitoreo;};

~Asignatura(){};

/*bool operator< (const Asignatura &right) const{
return codigo < right.codigo;*/ //si colecciones se implementan con set esto es necesario
