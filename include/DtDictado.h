#include <string>
using namespace std;

class DtDictado{
  private:
    string codAsig;
    int TiempoDictado;
  //string nombreAsig;
  public:
    DtDictado();
    DtDictado(string,int);
    void setCodAsig(string cod);
    void setTiempoDictado(int tiempo);
    string getCodAsig() const;
    int getTiempoDictado() const;
    bool operator<(const DtDictado &right) const ;
    ~DtDictado();
};
