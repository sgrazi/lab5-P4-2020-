#include <string>
using namespace std;

class DtTiempoDeClase{
private:
  string nombre;
  int tiempo;
  string codClase;
public:
  DtTiempoDeClase();
  DtTiempoDeClase(string n,int t,string c);
  void setNombre(string nombre);
  void setTiempo(int tiempo);
  void setCodClase(string cod);
  string getNombre() const ;
  int getTiempo() const ;
  string getCodClase() const ;
  bool operator<(const DtTiempoDeClase &right) const ;
  ~DtTiempoDeClase(){};
};
