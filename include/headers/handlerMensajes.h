#ifndef HANDLER_MENSAJES_H
#define HANDLER_MENSAJES_H

class HandlerMensajes{
  private:
    set(Mensaje) colMensajes;
    set(Usuario) observers;
  public:
    HandlerMensajes();

    agregarMensaje(); //cual es el tipo de retorno? en el dcd no estaba, puse void
    void agregarObs(Usuario);
    void eliminarObs(Usuario);

    ~HandlerMensajes();
};
#endif
