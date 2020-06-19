#include <iostream>
#include <string>

#include "include/factory.h"
#include "include/asignatura.h"
#include "include/clase.h"
#include "include/docente.h"
#include "include/estudiante.h"
#include "include/usuario.h"


using namespace std;

//___CLASE SISTEMA___

class Sistema{
  private:
    Sistema();
    static Sistema* instancia;

    static Factory* fabrica;
    static HandlerMensajes* handler;

    static map<string,Usuario*>* colUsuarios;
    static map<string,Estudiante*>* colEstudiantes;
    static map<string,Docente*>* colDocentes;
    static map<int,Asignatura*>* colAsignaturas;
    static map<int,Clase*>* colClases;
    static map<int,Mensaje*>* colMensajes;
  public:
    static Sistema* getInstancia();

    //operaciones del sistema, puse lo que me parecia, no creo este super correcto todo

    //Administrador
    void modificarReloj();
    void consultarReloj();
    void altaDeUsuario(){
      char entrada;
      string n,c,e,u,var;
      bool ed,sn;
      ed = false;
      sn = 0;
      while(!ed){
        cout << "\n\t¿Desea agregar un estudiante (E) o un docente (D)? \n\tOpcion: ";
        cin >> entrada;
        switch (entrada){
          case 'E':
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
              cout << "\n\t¿Desea confirmar el alta del estudiante? (S/N)\n\tOpcion: ";
              cin >> entrada;
              switch (entrada) {
                case 'S':
                  sn = true;
                  fabrica->getIUsuario()->confirmarAlta();
                break;
                case 'N':
                  sn = true;
                  fabrica->getIUsuario()->cancelarAlta();
                break;
                default:
                  cout << "\n\tOpcion no válida.";
                break;
              }
            }
          break;
          case 'D':
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
                case 'S':
                  sn = true;
                  fabrica->getIUsuario()->confirmarAlta();
                break;
                case 'N':
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
    //display
    void getDatosUsuarios(){
      cout << "\n\tEstudiantes en el sistema:";
      for(auto it = colEstudiantes->begin(); it!=colEstudiantes->end();it++){
        cout << "\n\tNombre: "<<it->second->getNombre()<< " Email: " <<it->second->getEmail();
      }
      cout << "\n\tDocentes en el sistema:";
      for(auto it = colDocentes->begin(); it!=colDocentes->end();it++){
        cout << "\n\tNombre: "<<it->second->getNombre()<< " Email: " <<it->second->getEmail();
      }
    };
    void getDatosAsignaturas(){

    };
    void getDatosClases(){

    };
};

Factory* Sistema::fabrica = 0;
Sistema* Sistema::instancia = 0;
HandlerMensajes* Sistema::handler = 0;
map<string,Usuario*>* Sistema::colUsuarios = 0;
map<string,Estudiante*>* Sistema::colEstudiantes = 0;
map<string,Docente*>* Sistema::colDocentes = 0;
map<int,Asignatura*>* Sistema::colAsignaturas = 0;
map<int,Clase*>* Sistema::colClases = 0;
map<int,Mensaje*>* Sistema::colMensajes = 0;

Sistema* Sistema::getInstancia(){
    if (instancia == 0)    {
        instancia = new Sistema();
        //creo la factory
        fabrica = fabrica->getInstancia();
        //creo el handler
        handler = new HandlerMensajes();
        //creo las colecciones
        colUsuarios = new map<string,Usuario*>;
        colEstudiantes = new map<string,Estudiante*>;
        colDocentes = new map<string,Docente*>;
        colAsignaturas = new map<int,Asignatura*>;
        colClases = new map<int,Clase*>;
        colMensajes = new map<int,Mensaje*>;
        //inicializo las colecciones de los controladores
        fabrica->getIUsuario()->setColUser(colUsuarios);
        fabrica->getIUsuario()->setColEst(colEstudiantes);
        fabrica->getIUsuario()->setColDoc(colDocentes);
        fabrica->getIUsuario()->setColAsig(colAsignaturas);
        fabrica->getIUsuario()->setHandler(handler);
        fabrica->getIAsignatura()->setColDoc(colDocentes);
        fabrica->getIAsignatura()->setColAsig(colAsignaturas);
        fabrica->getIAsignatura()->setColCla(colClases);
        fabrica->getIClase()->setColEst(colEstudiantes);
        fabrica->getIClase()->setColDoc(colDocentes);
        fabrica->getIClase()->setColAsig(colAsignaturas);
        fabrica->getIClase()->setColCla(colClases);
        fabrica->getIClase()->setColMens(colMensajes);
        fabrica->getIClase()->setHandler(handler);
        handler->setColMens(colMensajes);
        handler->setColCla(colClases);
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
    cout << "\t5) Ver datos en el sistema" << endl;
    cout << "\t6) Salir" << endl;
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
        s->getDatosUsuarios();
        s->getDatosAsignaturas();
        s->getDatosClases();
      break;
      case '6':
        salir = true;
      break;
      default:
        cout << "\nOpcion no valida.\n";
      break;
    }
  }

  return 0;
}
