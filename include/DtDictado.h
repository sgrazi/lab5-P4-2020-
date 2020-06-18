class DtDictado{
  private:
    int codAsig;
    int TiempoDictado;
  //string nombreAsig;
  public:
    DtDictado();
    DtDictado(int,int);
    void setCodAsig(int cod);
    void setTiempoDictado(int tiempo);
    int getCodAsig() const;
    int getTiempoDictado() const;
    bool operator<(const DtDictado &right) const ;
    ~DtDictado();
};
