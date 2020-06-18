class Reloj{
  private:
    int anio;
    int mes;
    int dia;
    int hora;
    int min;
    static Reloj* instancia;
    Reloj();
    //Reloj(int anio,int mes,int dia,int hora,int min);
  public:
    static Reloj* getInstancia();
    void setFechaSistema(int anio,int mes,int dia,int hora,int min);
    void setAnioSistema(int anio);
    void setMesSistema(int mes);
    void setDiaSistema(int dia);
    void setHoraSistema(int hora);
    void setMinSistema(int min);
    void getFechaSisema();
    int getAnioSistema();
    int getMesSistema();
    int getDiaSistema();
    int getHoraSistema();
    int getMinSistema();
    ~Reloj(){};
};
