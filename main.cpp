#include <iostream>


using namespace std;

//___CLASE SISTEMA___

#include <iostream>

class Sistema{
  private:
    static Sistema* instance;
      Sistema();
  public:
    static Sistema* getInstance();
    //operaciones del sistema, puse lo que me parecia, no creo este super correcto todo
    void iniciarSesion();
    void altaDeUsuario();
    void altaDeAsignatura();
    void asignarDocenteAAsignatura();
    void inscribirAAsignatura();
    void iniciarClase();
    void finalizarClase();
    void enviarMensaje();
    void asistirAClaseEnVivo();
    void finalizarAsistenciaAClaseEnVivo();
    void tiempoDeDictado();
    void tiempoDeAsistencia();
    void eliminarAsignatura();
    void suscribirANotificaciones();
    void consultarNotificaciones();
};

Sistema* Sistema::instance = 0;

Sistema* Sistema::getInstance(){
    if (instance == 0)    {
        instance = new Sistema();
    }
    return instance;
}

Sistema::Sistema(){}

//___FIN CLASE SISTEMA___

int main(){
  Sistema* s = Sistema::getInstance();

  cout << "Bienvenido. ";
  bool salir = false;
  char tecla;
  while (!salir){
    cout << "\n";
    cout << "Seleccione una opcion para probar los casos de uso" << endl;
    cout << "\t1) Administrador" << endl;
    cout << "\t2) Docente" << endl;
    cout << "\t3) Estudiante" << endl;
    cout << "\t4) Cargar datos de prueba" << endl;
    cout << "\t5) Salir" << endl << endl;
    cout << "\n \tOpcion: ";

    cin >> tecla;
    switch(tecla){
      /*case '1':
      break;*/
      default:
        salir=true;
      break;
    }
  }
  return 0;
}
