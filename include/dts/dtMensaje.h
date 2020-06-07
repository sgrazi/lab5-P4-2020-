#ifndef DT_MENSAJE_H
#define DT_MENSAJE_H

class dtMensaje{
  private:
    int id;
    string contenido;
    DtFecha fecha;
    int enRespuestaA; //Mensaje original tenia un puntero a otro mensaje, aca es el identificador del otro mensaje
    int clase; //Mensaje original tenia un puntero a su clase, aca es el identificador de la clase
  public:
    dtMensaje();
    void setId(int);
    void setContenido(string);
    void setFecha(DtFecha);
    void setEnRespuestaA(int);
    void setClase(int);
    int getId();
    string getContenido();
    DtFecha getFecha();
    int getEnRespuestaA();
    int getClase();

    ~dtMensaje();
    //bool operator<(const Mensaje &right); //si colecciones se implementan con set esto es necesario
}
#endif
