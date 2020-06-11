#ifndef DT_MONITOREO_H
#define DT_MONITOREO_H
#include <string>

using namespace std;

class dtMonitoreo : public dtClase{
  private:
    string[15] habilitados;//originalmente tenia punteros a estudiantes, aca son los emails de los est
  public:
    dtMonitoreo();
    ~dtMonitoreo();
};
#endif
