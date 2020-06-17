class DtDictado{
  private:
    int codAsig;
    int TiempoDictado;
  //string nombreAsig;
  public:
    DtDictado();
    DtDictado(int,int);
    bool operator<(const DtDictado &right) const ;
    ~DtDictado();
};
