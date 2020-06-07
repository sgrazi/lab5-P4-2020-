#ifndef DT_ESTUDIANTE_H
#define DT_ESTUDIANTE_H

class dtEstudiante : public dtUsuario{
  private:
    string ci;
  public:
    Estudiante();
    void setCI(string);
    string getCI();

    ~Estudiante();
}
#endif
