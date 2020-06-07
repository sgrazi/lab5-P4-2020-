#ifndef ROL_H
#define ROL_H

class Rol{
  private:
    Docente *doc;
    Asignatura *asig;
  public:
    Rol();
    Rol(Docente* d, Asignatura* a);
    void setDoc(Docente*);
    void setAsig(Asignatura*);
    Docente* getDoc();
    Asignatura* getAsig();
    string getCodigoAsig()
    ~Rol();
}
#endif
