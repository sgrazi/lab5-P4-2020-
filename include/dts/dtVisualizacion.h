#ifndef DT_VISUALIZACION_H
#define DT_VISUALIZACION_H

class dtVisualizacion{
  private:
    bool enVivo;
    DtFecha fechaInicioVis;
    DtFecha fechaFinVis;
  public://faltan funciones de manejo de relaciones
    dtVisualizacion();
    void setEnVivo(bool);
    void setFechaInicioVis(DtFecha);
    void setFechaFinVis(DtFecha);
    bool getEnVivo();
    DtFecha getFechaInicioVis();
    DtFecha getFechaFinVis();

    ~dtVisualizacion();
}
#endif
