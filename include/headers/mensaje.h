#ifndef MENSAJE_H
#define MENSAJE_H

class Mensaje{
  private:
    int id;
    string contenido;
    DtFecha fecha;
    Mensaje *enRespuestaA;
    HandlerMensajes *handler;
    Clase *clase;
  public://faltan funciones de manejo de relaciones
    Mensaje();
    void setId(int);
    void setContenido(string);
    void setFecha(DtFecha);
    void setEnRespuestaA(Mensaje);
    int getId();
    string getContenido();
    DtFecha getFecha();
    Mensaje* getEnRespuestaA();

    ~Mensaje();
    //bool operator<(const Mensaje &right); //si colecciones se implementan con set esto es necesario
}
#endif
