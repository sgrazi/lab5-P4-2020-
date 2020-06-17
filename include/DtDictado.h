class DtDictado{
  private:
    int codAsig;
    int tiempoDictado;
  //string nombreAsig;
  public:
    DtDictado();
    DtDictado(int,int);

    int getCodigoAsig() const ;
    int getTiempoDictado() const ;
    bool operator<(const DtDictado &right) const ;
    ~DtDictado();
};
