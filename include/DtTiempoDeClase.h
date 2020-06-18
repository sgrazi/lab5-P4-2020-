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
  string getNombre() const ;
  int getTiempo() const ;
  int getCodClase() const ;
  bool operator<(const DtTiempoDeClase &right) const ;
  ~DtTiempoDeClase(){};
};
