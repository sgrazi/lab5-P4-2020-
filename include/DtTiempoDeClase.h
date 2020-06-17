#include <string>
using namespace std;

class DtTiempoDeClase{
private:
  string nombre;
  int tiempo;
  int codClase;
public:
  DtTiempoDeClase();
  DtTiempoDeClase(string n,int t,int c);
  void setNombre(string nombre);
  void setTiempo(int tiempo);
  void setCodClase(int cod);
  string getNombre();
  int getTiempo();
  int getCodClase();
  bool operator<(const DtTiempoDeClase &right) const ;
  ~DtTiempoDeClase(){};
};
