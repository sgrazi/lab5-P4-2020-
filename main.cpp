#include <iostream>
#include <string>

using namespace std;

//___CLASE SISTEMA___

class Sistema{
  private:
    static Sistema* instance;
      Sistema();
  public:
    static Sistema* getInstance();
    //operaciones del sistema, puse lo que me parecia, no creo este super correcto todo
    //Administrador
    void modificarReloj();
    void consultarReloj();
    void altaDeUsuario();
    void altaDeAsignatura();
    void asignarDocenteAAsignatura();
    void eliminarAsignatura();
    void tiempoDeDictado();
    //estudiante
    void inscribirAAsignatura();
    void asistirAClaseEnVivo();
    void finalizarAsistenciaAClaseEnVivo();
    //docente
    void iniciarClase();
    void finalizarClase();
    void tiempoDeAsistencia();
    //ambos
    void iniciarSesion();
    void enviarMensaje();
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
  bool inicioSesion = false;
  string email;
  string pass;

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
      case '1':
        cout << "\n";
        cout << "\nSeleccione una operación de administrador:" << endl;
        cout << "\t1) Consultar reloj del sistema" << endl;
        cout << "\t2) Modificar reloj del sistema" << endl;
        cout << "\t3) Agregar usuario al sistema" << endl;
        cout << "\t4) Agregar asignatura al sistema" << endl;
        cout << "\t5) Eliminar asignatura del sistema" << endl;
        cout << "\t6) Atras" << endl << endl;
        cout << "\n \tOpcion: ";
        cin >> tecla;
        switch (tecla){//agregar las operaciones
          default:
            cout << "\nOpcion no valida.\n";
          break;
        }
      break;
      case '2':
        inicioSesion = false;
        cout << "\n";
        while(!inicioSesion){
          cout << "Por favor inicie sesion." << endl;
          cout << "\tEmail: ";
          cin >> email;
          cout << "\tContraseña: ";
          cin >> pass;
          if(1){//s->iniciarSesion(email,pass)
            inicioSesion = true;
            cout << "\nSeleccione una operación de docente:" << endl;
            cout << "\t1) Iniciar una clase" << endl;
            cout << "\t2) Finalizar una clase" << endl;
            cout << "\t3) Consultar tiempo promedio de asistencia a clases" << endl;
            cout << "\t4) Enviar un mensaje" << endl;
            cout << "\t5) Suscribirse a notificaciones" << endl;
            cout << "\t6) Consultar notificaciones" << endl;
            cout << "\t7) Atras" << endl << endl;
            cout << "\n \tOpcion: ";
            cin >> tecla;
            switch (tecla){//agregar las operaciones
              default:
                cout << "\nOpcion no valida.\n";
              break;
            }
          }
          else
            cout << "Credenciales no validas. Por favor intente de nuevo." << endl;
        }
      break;
      case '3':
        inicioSesion = false;
        cout << "\n";
        while(!inicioSesion){
          cout << "Por favor inicie sesion." << endl;
          cout << "\tEmail: ";
          cin >> email;
          cout << "\tContraseña: ";
          cin >> pass;
          if(1){//s->iniciarSesion(email,pass)
            inicioSesion = true;
            cout << "\nSeleccione una operación de estudiante:" << endl;
            cout << "\t1) Inscribirse a una asignatura" << endl;
            cout << "\t2) Iniciar asistencia a una clase" << endl;
            cout << "\t3) Finalizar asistencia a una clase" << endl;
            cout << "\t4) Enviar un mensaje" << endl;
            cout << "\t5) Suscribirse a notificaciones" << endl;
            cout << "\t6) Consultar notificaciones" << endl;
            cout << "\t7) Atras" << endl << endl;
            cout << "\n \tOpcion: ";
            cin >> tecla;
            switch (tecla){//agregar las operaciones
              default:
                cout << "\nOpcion no valida.\n";
              break;
            }
          }
          else
            cout << "\nCredenciales no validas. Por favor intente de nuevo." << endl;
        }
      break;
      case '4':
        cout << "\nCasos de pruebas cargados.";
      break;
      case '5':
        salir = true;
      break;
      default:
        cout << "\nOpcion no valida.\n";
      break;
    }
  }
  return 0;
}
