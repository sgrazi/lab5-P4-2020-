#include <iostream>
#include <map>

using namespace std;

class Asignatura{
  private:
    int codigo;
    string nombre;
    bool teorico;
    bool monitoreo;
    bool practico;
  public:
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

/*    bool operator< (const Asignatura &right) const{
    return codigo < right.codigo;
  }*/
};

int main(void) {
   Asignatura *asig = new Asignatura();
   asig->setCodigo(123);
   asig->setNombre("Calculo");
   asig->setTeorico(true);
   asig->setPractico(true);
   asig->setMonitoreo(false);
   map<int, Asignatura> m;/* = {
            {asig->getCodigo(), *asig},
            };
*/
   m.insert(pair<int,Asignatura*>(getCodigo(),asig));
   auto it = m.find(asig->getCodigo());

   cout << "Iterator points to " << it->first <<
      " = " << it->second.getCodigo() << endl;

   return 0;
}
//https://www.tutorialspoint.com/cpp_standard_library/cpp_set_find.htm
//https://www.tutorialspoint.com/cpp_standard_library/cpp_set_insert.htm
//https://www.tutorialspoint.com/cpp_standard_library/cpp_set_def_constructor.htm
//https://www.tutorialspoint.com/cpp_standard_library/set.htm
