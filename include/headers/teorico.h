#ifndef TEORICO_H
#define TEORICO_H

class Teorico : public Clase{
  private:
    int asistentes;
  public:
    Teorico();
    void setAsistentes(int);
    int getAsistentes();

    int calcularAsistentes();

    ~Teorico();
};
#endif
