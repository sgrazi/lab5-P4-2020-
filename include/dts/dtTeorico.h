#ifndef DT_TEORICO_H
#define DT_TEORICO_H

class dtTeorico : public dtClase{
  private:
    int asistentes;
  public:
    dtTeorico();
    void setAsistentes(int);
    int getAsistentes();

    ~dtTeorico();
};
#endif
