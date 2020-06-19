#include <iostream>
#include <string>

#include "include/factory.h"

using namespace std;

//___CLASE SISTEMA___

class Sistema{
  private:
    static Sistema* instancia;
    Sistema();
    static Factory* fabrica;
  public:
    static Sistema* getInstancia();

    //operaciones del sistema, puse lo que me parecia, no creo este super correcto todo

    //Administrador
    void modificarReloj();
    void consultarReloj();
    void altaDeUsuario(){
      int entrada;
      string n,c,e,u,var;
      bool ed,sn;
      ed = false;
      sn = 0;
      while(!ed){
        cout << "\n\t¿Desea agregar un estudiante (1) o un docente (0)? \n\tOpcion: ";
        cin >> entrada;
        switch (entrada){
          case '1':
            ed = true;
            cout << "\n\tIngrese el nombre: ";
            cin >> n;
            cout << "\n\tIngrese el email: ";
            cin >> e;
            cout << "\n\tIngrese la contraseña: ";
            cin >> c;
            cout << "\n\tIngrese la url de la imagen: ";
            cin >> u;
            cout << "\n\tIngrese la cédula: ";
            cin >> var;
            fabrica->getIUsuario()->agregarEstudiante(n, c, e, u, var);
            while(!sn){
              cout << "\n\t¿Desea confirmar (1) el alta del estudiante? \n\tOpcion: ";
              cin >> entrada;
              switch (entrada) {
                case '1':
                  sn = true;
                  fabrica->getIUsuario()->confirmarAlta();
                break;
                case '0':
                  sn = true;
                  fabrica->getIUsuario()->cancelarAlta();
                break;
                default:
                  cout << "\n\tOpcion no válida.";
                break;
              }
            }
          break;
          case '2':
            ed = true;
            cout << "\n\tIngrese el nombre: ";
            cin >> n;
            cout << "\n\tIngrese el email: ";
            cin >> e;
            cout << "\n\tIngrese la contraseña: ";
            cin >> c;
            cout << "\n\tIngrese la url de la imagen: ";
            cin >> u;
            cout << "\n\tIngrese el instituto: ";
            cin >> var;
            fabrica->getIUsuario()->agregarDocente(n, c, e, u, var);
            while(!sn){
              cout << "\n\t¿Desea confirmar (1) el alta del docente? (S/N) \n\tOpcion: ";
              cin >> entrada;
              switch (entrada) {
                case '1':
                  sn = true;
                  fabrica->getIUsuario()->confirmarAlta();
                break;
                case '0':
                  sn = true;
                  fabrica->getIUsuario()->cancelarAlta();
                break;
                default:
                  cout << "\n\tOpcion no válida.";
                break;
              }
            }
          break;
          default:
            ed = true;
            cout << "el programa entendio: "<<entrada;
            cout << "\n\tOpcion no válida.";
          break;
        }
      }
    };
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

Factory* Sistema::fabrica = 0;
Sistema* Sistema::instancia = 0;

Sistema* Sistema::getInstancia(){
    if (instancia == 0)    {
        instancia = new Sistema();
        fabrica = fabrica->getInstancia();
    }
    return instancia;
}

Sistema::Sistema(){}

//___FIN CLASE SISTEMA___

int main(){
  Sistema* s = Sistema::getInstancia();

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
          case '3':
            s->altaDeUsuario();
          break;
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
