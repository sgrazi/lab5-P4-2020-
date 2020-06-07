#ifndef MENSAJE_H
#define MENSAJE_H

class Mensaje{
  private:
    string id;
    string contenido;
    DtFecha fecha;
    Mensaje *enRespuestaA;
    HandlerMensajes *handler;
    Clase *clase;
  public:
    Mensaje();
    void setId(string);
    void setContenido(string);
    void setFecha(DtFecha);
    void setEnRespuestaA(Mensaje);
    string getId();
    string getContenido();
    DtFecha getFecha();
    Mensaje* getEnRespuestaA();

    ~Mensaje();
}
#endif
