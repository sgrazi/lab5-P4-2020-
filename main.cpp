#include <iostream>
#include <string>
#include <limits>

#include "include/factory.h"
#include "include/asignatura.h"
#include "include/clase.h"
#include "include/docente.h"
#include "include/estudiante.h"
#include "include/usuario.h"
#include "include/tipoClase.h"

const dtFecha fechaNula(0,0,0,0,0,0);

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
    static map<string,Asignatura*>* colAsignaturas;
    static map<string,Clase*>* colClases;
    static map<int,Mensaje*>* colMensajes;
    static Reloj* reloj;
  public:
    static Sistema* getInstancia();

    void cargarDatos(){//SE REALIZAN LAS OPERACIONES EN ORDEN CRONOLOGICO

      fabrica->getIUsuario()->agregarEstudiante("Roberto Parra","1234","roberto@mail.com","url","12345678");//E1 roberto@mail.com Roberto Parra 12345678
      fabrica->getIUsuario()->confirmarAlta();
      fabrica->getIUsuario()->agregarEstudiante("Ana Rodriguez","1234","ana@mail.com","url","23456789");   // E2 ana@mail.com Ana Rodriguez 23456789
      fabrica->getIUsuario()->confirmarAlta();
      fabrica->getIUsuario()->agregarEstudiante("Ramon Valdez","1234","ramon@mail.com","url","34567890"); //  E3 ramon@mail.com Ramon Valdez 34567890
      fabrica->getIUsuario()->confirmarAlta();

      fabrica->getIUsuario()->agregarDocente("Juan Perez","123","juan@mail.com","url","INCO");    // D1  juan@mail.com Juan Perez   INCO
      fabrica->getIUsuario()->confirmarAlta();
      fabrica->getIUsuario()->agregarDocente("Maria Pires","123","maria@mail.com","url","INCO");   //D2  maria@mail.com Maria Pires INCO
      fabrica->getIUsuario()->confirmarAlta();
      fabrica->getIUsuario()->agregarDocente("Jorge Chacho","123","jorge@mail.com","url","INCO");  //D3 jorge@mail.com Jorge Chacho INCO
      fabrica->getIUsuario()->confirmarAlta();

      //ASUMO SE DESEA QUE LOS USUARIOS RECIBAN NOTIFICACIONES, LOS SUSCRIBO ACA
      iniciarSesionE("roberto@mail.com");
      fabrica->getIUsuario()->cambiarModoSus(3);
      fabrica->getIUsuario()->confirmarCambio();
      iniciarSesionE("ana@mail.com");
      fabrica->getIUsuario()->cambiarModoSus(3);
      fabrica->getIUsuario()->confirmarCambio();
      iniciarSesionE("ramon@mail.com");
      fabrica->getIUsuario()->cambiarModoSus(3);
      fabrica->getIUsuario()->confirmarCambio();
      iniciarSesionD("juan@mail.com");
      fabrica->getIUsuario()->cambiarModoSus(3);
      fabrica->getIUsuario()->confirmarCambio();
      iniciarSesionD("maria@mail.com");
      fabrica->getIUsuario()->cambiarModoSus(3);
      fabrica->getIUsuario()->confirmarCambio();
      iniciarSesionD("jorge@mail.com");
      fabrica->getIUsuario()->cambiarModoSus(3);
      fabrica->getIUsuario()->confirmarCambio();

      fabrica->getIAsignatura()->agregarAsignatura("Programacion 1","P1",1,1,1);//A1 P1 Programacion 1 Te�rico, Pr�ctico, Monitoreo
      fabrica->getIAsignatura()->confirmarAlta();
      fabrica->getIAsignatura()->agregarAsignatura("Programacion 2","P2",1,1,1);//A2 P2 Programacion 2 Te�rico, Pr�ctico, Monitoreo
      fabrica->getIAsignatura()->confirmarAlta();
      fabrica->getIAsignatura()->agregarAsignatura("Programacion 3","P3",1,1,0);//A3 P3 Programacion 3 Te�rico, Pr�ctico
      fabrica->getIAsignatura()->confirmarAlta();

      bool admite;
      admite = fabrica->getIAsignatura()->asignarDocente("maria@mail.com","P1",practico); //D2 A1 Pr�ctico
      fabrica->getIAsignatura()->confirmarAsignacion();
      admite = fabrica->getIAsignatura()->asignarDocente("juan@mail.com","P1",teorico); //D1 A1 Te�rico
      fabrica->getIAsignatura()->confirmarAsignacion();
      admite = fabrica->getIAsignatura()->asignarDocente("jorge@mail.com","P1",monitoreo); //D3 A1 Monitoreo
      fabrica->getIAsignatura()->confirmarAsignacion();

      iniciarSesionE("roberto@mail.com");// E1 A1
      fabrica->getIUsuario()->inscribir("P1");
      fabrica->getIUsuario()->confirmarInscripcion();
      iniciarSesionE("ana@mail.com");// E2 A1,A2
      fabrica->getIUsuario()->inscribir("P1");
      fabrica->getIUsuario()->confirmarInscripcion();
      fabrica->getIUsuario()->inscribir("P2");
      fabrica->getIUsuario()->confirmarInscripcion();
      iniciarSesionE("ramon@mail.com");// E3 A1
      fabrica->getIUsuario()->inscribir("P1");
      fabrica->getIUsuario()->confirmarInscripcion();

      iniciarSesionD("juan@mail.com");
      dtFecha* fecha = new dtFecha();
      fecha->setAnio(2020);
      fecha->setMes(5);
      fecha->setDia(1);
      fecha->setHora(9);
      fecha->setMinuto(0);
      fecha->setSegundo(0);

      fabrica->getIClase()->iniciarClase("P1","Intro Teórico",teorico,*fecha);//C1 A1 Intro Te�rico 01/05/20 - 9am 01/05/20 - 10am D1
      fabrica->getIClase()->confirmarInicio();
      delete fecha;

      fecha = new dtFecha();
      fecha->setAnio(2020);
      fecha->setMes(5);
      fecha->setDia(3);
      fecha->setHora(9);
      fecha->setMinuto(0);
      fecha->setSegundo(0);

      fabrica->getIClase()->iniciarClase("P1","Tema 1",teorico,*fecha);//C2 A1 Tema 1 Te�rico 03/05/20 - 9am 03/05/20 - 10am D1
      fabrica->getIClase()->confirmarInicio();
      delete fecha;

      fecha = new dtFecha();
      fecha->setAnio(2020);
      fecha->setMes(5);
      fecha->setDia(8);
      fecha->setHora(9);
      fecha->setMinuto(0);
      fecha->setSegundo(0);

      fabrica->getIClase()->iniciarClase("P1","Tema 2",teorico,*fecha);//C3 A1 Tema 2 Te�rico 08/05/20 - 9am 08/05/20 - 10am D1
      fabrica->getIClase()->confirmarInicio();
      delete fecha;

      iniciarSesionD("maria@mail.com");
      fecha = new dtFecha();
      fecha->setAnio(2020);
      fecha->setMes(5);
      fecha->setDia(2);
      fecha->setHora(16);
      fecha->setMinuto(0);
      fecha->setSegundo(0);

      fabrica->getIClase()->iniciarClase("P1","Pra 1",practico,*fecha);//C4 A1 Pra 1 Pr�ctico 02/05/20 - 4pm 02/05/20 - 5pm D2
      fabrica->getIClase()->confirmarInicio();
      delete fecha;

      fecha = new dtFecha();
      fecha->setAnio(2020);
      fecha->setMes(5);
      fecha->setDia(3);
      fecha->setHora(16);
      fecha->setMinuto(0);
      fecha->setSegundo(0);

      fabrica->getIClase()->iniciarClase("P1","Pra 2",practico,*fecha);//C5 A1 Pra 2 Pr�ctico 03/05/20 - 4pm 03/05/20 - 5pm D2
      fabrica->getIClase()->confirmarInicio();
      delete fecha;

      iniciarSesionD("jorge@mail.com");
      fecha = new dtFecha();
      fecha->setAnio(2020);
      fecha->setMes(5);
      fecha->setDia(4);
      fecha->setHora(16);
      fecha->setMinuto(0);
      fecha->setSegundo(0);

      fabrica->getIClase()->iniciarClase("P1","06/01/20",monitoreo,*fecha);//C6 A1 06/01/20 Monitoreo 04/05/20 - 4pm 04/05/20 - 5pm D3
      fabrica->getIClase()->agregarHabilitado("ana@mail.com");
      fabrica->getIClase()->agregarHabilitado("ramon@mail.com");

      fabrica->getIClase()->confirmarInicio();
      delete fecha;

      //01/05/20 - 09:01am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(1);

      iniciarSesionE("roberto@mail.com");//E1 C1 01/05/20 - 09:01am 01/05/20 - 09:21am
      dtClase clase1 = fabrica->getIClase()->asistirClaseVivo("0");
      fabrica->getIClase()->confirmarAsistenciaVivo();

      //01/05/20 - 09:01am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(1);

      iniciarSesionD("juan@mail.com");//D1 C1 01/05/20 - 09:01am Bienvenidos!
      fabrica->getIClase()->consultarMensajes("0");
      fabrica->getIClase()->enviarMensaje("Bienvenidos!");
      fabrica->getIClase()->confirmarEnvio();

      //01/05/20 - 09:02am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(2);

      iniciarSesionD("juan@mail.com");//D1 C1 01/05/20 - 09:01am Bienvenidos!
      fabrica->getIClase()->consultarMensajes("0");
      fabrica->getIClase()->enviarMensaje("Confirmen materiales por favor.");//01/05/20 - 09:02 am Confirmen materiales por favor.
      fabrica->getIClase()->confirmarEnvio();

      //01/05/20 - 09:02am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(2);

      iniciarSesionE("ana@mail.com");//E2 C1 01/05/20 - 09:02am 01/05/20 - 09:32am
      clase1 = fabrica->getIClase()->asistirClaseVivo("0");
      fabrica->getIClase()->confirmarAsistenciaVivo();

      //01/05/20 - 09:03am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(3);

      iniciarSesionE("ramon@mail.com");//E3 C1 01/05/20 - 09:03am 01/05/20 - 09:43am
      clase1 = fabrica->getIClase()->asistirClaseVivo("0");
      fabrica->getIClase()->confirmarAsistenciaVivo();

      //01/05/20 - 09:05am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(5);

      iniciarSesionE("roberto@mail.com");//01/05/20 - 09:05am Listo para aprender
      fabrica->getIClase()->consultarMensajes("0");
      fabrica->getIClase()->enviarRespuesta(0,"Listo para aprender");// 0 es Bienvenidos
      fabrica->getIClase()->confirmarEnvio();

      //01/05/20 - 09:05am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(6);

      iniciarSesionD("juan@mail.com");//01/05/20 - 09:06am Me alegro
      fabrica->getIClase()->consultarMensajes("0");
      fabrica->getIClase()->enviarRespuesta(2,"Me alegro");
      fabrica->getIClase()->confirmarEnvio();

      //01/05/20 - 09:06am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(6);

      iniciarSesionE("ana@mail.com");//01/05/20 - 09:06am Todo listo
      fabrica->getIClase()->consultarMensajes("0");
      fabrica->getIClase()->enviarRespuesta(1,"Todo listo"); //1 es confirmen materiales
      fabrica->getIClase()->confirmarEnvio();

      //01/05/20 - 09:21am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(21);

      iniciarSesionE("roberto@mail.com");//04/05/20 – 5:00pm
      fabrica->getIClase()->finalizarAsistencia("0");
      fabrica->getIClase()->confirmarSalida();

      //01/05/20 - 09:32am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(32);

      iniciarSesionE("ana@mail.com");//04/05/20 – 5:00pm
      fabrica->getIClase()->finalizarAsistencia("0");
      fabrica->getIClase()->confirmarSalida();

      //01/05/20 - 09:43am
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(9);
      reloj->setMinSistema(43);

      iniciarSesionE("ramon@mail.com");//04/05/20 – 5:00pm
      fabrica->getIClase()->finalizarAsistencia("0");
      fabrica->getIClase()->confirmarSalida();

      //01/05/20 - 10am fin c1
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(1);
      reloj->setHoraSistema(10);
      reloj->setMinSistema(0);

      iniciarSesionD("juan@mail.com");
      fabrica->getIClase()->finalizarClase("0");
      fabrica->getIClase()->confirmarFin();

      //02/05/20 - 5pm fin c4
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(2);
      reloj->setHoraSistema(17);
      reloj->setMinSistema(0);

      iniciarSesionD("maria@mail.com");
      fabrica->getIClase()->finalizarClase("3");
      fabrica->getIClase()->confirmarFin();

      //03/05/20 - 10am fin c2
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(3);
      reloj->setHoraSistema(10);
      reloj->setMinSistema(0);

      iniciarSesionD("juan@mail.com");
      fabrica->getIClase()->finalizarClase("1");
      fabrica->getIClase()->confirmarFin();

      //03/05/20 - 5pm fin c5
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(3);
      reloj->setHoraSistema(17);
      reloj->setMinSistema(0);

      iniciarSesionD("maria@mail.com");
      fabrica->getIClase()->finalizarClase("4");
      fabrica->getIClase()->confirmarFin();

      //04/05/20 - 4:00pm
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(4);
      reloj->setHoraSistema(16);
      reloj->setMinSistema(0);
//4
      iniciarSesionE("ramon@mail.com");//E3 C6 04/05/20 � 4:00pm 04/05/20 � 5:00pm
      clase1 = fabrica->getIClase()->asistirClaseVivo("5");
      fabrica->getIClase()->confirmarAsistenciaVivo();
      //fabrica->getIClase()->confirmarAsistenciaVivo();

      //04/05/20 - 04:01pm
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(4);
      reloj->setHoraSistema(4);
      reloj->setMinSistema(1);

      iniciarSesionD("jorge@mail.com");//04/05/20 - 04:01pm Comparto pantalla.
      fabrica->getIClase()->consultarMensajes("5");
      fabrica->getIClase()->enviarMensaje("Comparto pantalla.");
      fabrica->getIClase()->confirmarEnvio();

      //04/05/20 - 04:05pm
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(4);
      reloj->setHoraSistema(16);
      reloj->setMinSistema(5);

      iniciarSesionE("ramon@mail.com");//04/05/20 - 04:05pm Ya la vemos
      fabrica->getIClase()->consultarMensajes("5");
      fabrica->getIClase()->enviarRespuesta(5,"Ya la vemos");
      fabrica->getIClase()->confirmarEnvio();


      //04/05/20 - 5pm fin c6
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(4);
      reloj->setHoraSistema(17);
      reloj->setMinSistema(0);

      iniciarSesionD("jorge@mail.com");
      fabrica->getIClase()->finalizarClase("5");
      fabrica->getIClase()->confirmarFin();

      //04/05/20 – 5:00pm LA REALIZA EL FIN DE LA CLASE ^^^^^^^^^^
      //reloj->setAnioSistema(2020);
      //reloj->setMesSistema(5);
      //reloj->setDiaSistema(4);
      //reloj->setHoraSistema(17);
      //reloj->setMinSistema(0);

      //iniciarSesionE("ramon@mail.com");//04/05/20 – 5:00pm
      //fabrica->getIClase()->finalizarAsistencia("5");
      //fabrica->getIClase()->confirmarSalida();


      //08/05/20 - 10am fin c3
      reloj->setAnioSistema(2020);
      reloj->setMesSistema(5);
      reloj->setDiaSistema(8);
      reloj->setHoraSistema(10);
      reloj->setMinSistema(0);

      iniciarSesionD("juan@mail.com");
      fabrica->getIClase()->finalizarClase("2");
      fabrica->getIClase()->confirmarFin();
///SEPARA
reloj->setAnioSistema(2020);
reloj->setMesSistema(5);
reloj->setDiaSistema(8);
reloj->setHoraSistema(11);
reloj->setMinSistema(0);

      fecha = new dtFecha();
      fecha->setAnio(2020);
      fecha->setMes(5);
      fecha->setDia(8);
      fecha->setHora(11);
      fecha->setMinuto(0);
      fecha->setSegundo(0);

      iniciarSesionD("juan@mail.com");
      fabrica->getIClase()->iniciarClase("P1","PRUEBA1",teorico,*fecha);//C3 A1 Tema 2 Te�rico 08/05/20 - 9am 08/05/20 - 10am D1
      fabrica->getIClase()->confirmarInicio();

      fabrica->getIClase()->iniciarClase("P1","PRUEBA2",teorico,*fecha);//C3 A1 Tema 2 Te�rico 08/05/20 - 9am 08/05/20 - 10am D1
      fabrica->getIClase()->confirmarInicio();
      delete fecha;

      iniciarSesionE("roberto@mail.com");//E3 C1 01/05/20 - 09:03am 01/05/20 - 09:43am
      clase1 = fabrica->getIClase()->asistirClaseVivo("6");
      fabrica->getIClase()->confirmarAsistenciaVivo();

      iniciarSesionE("roberto@mail.com");//E3 C1 01/05/20 - 09:03am 01/05/20 - 09:43am
      clase1 = fabrica->getIClase()->asistirClaseVivo("7");
      fabrica->getIClase()->confirmarAsistenciaVivo();

      iniciarSesionD("juan@mail.com");
      fabrica->getIClase()->finalizarClase("7");
      fabrica->getIClase()->confirmarFin();

    }
    //Administrador
    void modificarReloj(){
      int anio,mes,dia,hora,min;
      cout << "\n\t¿Qué año desea ingresar?";
      cin >> anio;
      reloj->setAnioSistema(anio);
      cout << "\n\t¿Qué mes desea ingresar?";
      cin >> mes;
      reloj->setMesSistema(mes);
      cout << "\n\t¿Qué dia desea ingresar?";
      cin >> dia;
      reloj->setDiaSistema(dia);
      cout << "\n\t¿Qué hora desea ingresar?";
      cin >> hora;
      reloj->setHoraSistema(hora);
      cout << "\n\t¿Qué minuto desea ingresar?";
      cin >> min;
      reloj->setMinSistema(min);
    };
    void consultarReloj(){
      cout << "\n\tEstamos en el año " << reloj->getAnioSistema();
      cout << "\n\tEstamos en el mes " << reloj->getMesSistema();
      cout << "\n\tEstamos en el dia " << reloj->getDiaSistema();
      cout << "\n\tEstamos en la hora " << reloj->getHoraSistema();
      cout << "\n\tEstamos en el minuto " << reloj->getMinSistema();
    };
    void altaDeUsuario(){
      char entrada;
      string n,c,e,u,var;
      bool ed,sn,no_pronto;
      no_pronto = true;
      ed = 0;
      sn = 0;
      int cant;
      while(no_pronto){
        while(!ed){
          cout << "\n\t¿Desea agregar un estudiante (E) o un docente (D)? \n\tOpcion: ";
          cin >> entrada;
          switch (entrada){
            case 'E':
              ed = true;
              cout << "\n\tIngrese el nombre: ";
              getline(cin >> ws, n);
              cout << "\n\tIngrese el email: ";
              cin >> e;
              cout << "\n\tIngrese la contraseña: ";
              cin >> c;
              cout << "\n\tIngrese la url de la imagen: ";
              cin >> u;
              cout << "\n\tIngrese la cédula: ";
              cin >> var;
              fabrica->getIUsuario()->agregarEstudiante(n, c, e, u, var);
              cant = colEstudiantes->count(e);
              if(cant==0){
                bool cedula = fabrica->getIUsuario()->existeCedula(var);
                if(!cedula){
                  while(!sn){
                    cout << "\n\t¿Desea confirmar el alta del estudiante? (S/N)\n\tOpcion: ";
                    cin >> entrada;
                    switch (entrada) {
                      case 'S':
                        sn = true;
                        no_pronto = false;
                        fabrica->getIUsuario()->confirmarAlta();
                      break;
                      case 'N':
                        sn = true;
                        no_pronto = false;
                        fabrica->getIUsuario()->cancelarAlta();
                      break;
                      default:
                        cout << "\n\tOpcion no válida.";
                      break;
                    }
                  }
                }
                else{
                  ed = 0;
                  cout << "\n\tYa existe un estudiante con la cedula indicada.";
                }
              }
              else{
                ed = 0;
                cout << "\n\tYa existe un estudiante con el email indicado.";
              }
            break;
            case 'D':
              ed = true;
              cout << "\n\tIngrese el nombre: ";
              getline(cin >> ws, n);
              cout << "\n\tIngrese el email: ";
              cin >> e;
              cout << "\n\tIngrese la contraseña: ";
              cin >> c;
              cout << "\n\tIngrese la url de la imagen: ";
              cin >> u;
              cout << "\n\tIngrese el instituto: ";
              cin >> var;
              fabrica->getIUsuario()->agregarDocente(n, c, e, u, var);
              cant = colDocentes->count(e);
              if(cant==0){
                while(!sn){
                  cout << "\n\t¿Desea confirmar el alta del docente? (S/N) \n\tOpcion: ";
                  cin >> entrada;
                  switch (entrada) {
                    case 'S':
                      sn = true;
                      no_pronto = false;
                      fabrica->getIUsuario()->confirmarAlta();
                    break;
                    case 'N':
                      sn = true;
                      no_pronto = false;
                      fabrica->getIUsuario()->cancelarAlta();
                    break;
                    default:
                      cout << "\n\tOpcion no válida.";
                    break;
                  }
                }
              }
              else{
                cout << "\n\tYa existe un docente con el email indicado.";
              }
            break;
            default:
              ed = 0;
              cout << "\n\tOpcion no válida.";
            break;
          }
        }
      }
    };
    void altaDeAsignatura(){
      string nombreAsig,e8;
      char e6,e7;
      string codigoAsig;
      bool teorico,practico,monitoreo;
      bool sn = false;
      bool no_pronto=true;
      while(no_pronto){
        cout << "\n\t¿Cuál es el nombre de la asignatura?: ";
        getline(cin >> ws, nombreAsig);
        while (std::cout << "\n\t¿Cuál es el código de la asignatura?: " && !(std::cin >> codigoAsig)) {
          std::cin.clear(); //clear bad input flag
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
          std::cout << "\tCodigo no valido.\n";
        }
        while(!sn){
          cout << "\n\t¿La asignatura tiene teóricos (1) o no (0)?: ";
          cin >> e7;
          switch(e7){
            case '1':
              sn = true;
              teorico=true;
            break;
            case '0':
              sn = true;
              teorico=false;
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
          }
        }
        sn=false;
        while(!sn){
          cout << "\n\t¿La asignatura tiene prácticos (1) o no (0)?: ";
          cin >> e7;
          switch(e7){
            case '1':
              sn = true;
              practico=true;
            break;
            case '0':
              sn = true;
              practico=false;
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
            }
        }
        sn=false;
        while(!sn){
          cout << "\n\t¿La asignatura tiene monitoreos (1) o no(0)?: ";
          cin >> e7;
          switch(e7){
            case '1':
              sn = true;
              monitoreo=true;
            break;
            case '0':
              sn = true;
              monitoreo=false;
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
          }
        }
        fabrica->getIAsignatura()->agregarAsignatura(nombreAsig,codigoAsig,teorico,practico,monitoreo);
        sn=false;
        while(!sn){
          cout << "\n\t¿Desea confirmar (1) o no(0)?";
          cin >> e6;
          switch(e6){
            case '1':
              sn=true;
              no_pronto=false;
              fabrica->getIAsignatura()->confirmarAlta();
            break;
            case '0':
              sn=true;
              no_pronto=false;
              fabrica->getIAsignatura()->cancelarAlta();
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
          }
        }
      }
    };
    void asignarDocenteAAsignatura(){
      int tipo;
      char entrada;
      string emailDoc,codigoAsig;
      bool tipoCorrecto = false;
      bool sn = false;
      bool admite = true;
      bool no_pronto = true;
      while(no_pronto){
        set<dtAsignatura> asignaturas = fabrica->getIAsignatura()->consultarAsignaturas();
        if(asignaturas.begin()==asignaturas.end()){
          cout << "\n\tNo existen asignaturas en el sistema.\n";
          no_pronto = 0;
        }
        else{
          cout << "\n\tAsignaturas en el sistema:";
          for(auto it = asignaturas.begin();it != asignaturas.end();it++){
            cout << "\n\tNombre: " << it->getNombre()<< " Codigo: " << it->getCodigo();
          }
          bool aux=true;
          while(aux){
            while (std::cout << "\n\tIngrese el codigo de una asignatura: " && !(std::cin >> codigoAsig)) {
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              std::cout << "\tPor favor ingrese un numero.\n";
            }
            if(!colAsignaturas->count(codigoAsig)){
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              cout << "\tEl codigo no es valido. Por favor intente de nuevo.\n";
            }
            else//todo bien, era un numero y un codigo valido
              aux=false;
          }
          map<string,dtDocente> docLibres = fabrica->getIAsignatura()->consultarDocentesLibres(codigoAsig);
          if(docLibres.begin()==docLibres.end()){
            cout << "\n\tNo existen docentes en el sistema.\n";
            no_pronto = 0;
          }
          else{
            cout << "\n\tLos docentes libres para asignar a la asignatura son: ";
            for(auto it = docLibres.begin();it != docLibres.end();it++){
              cout << "\n\tNombre: " << it->second.getNombre()<< " Email: " << it->first;
            }
            while(cout << "\n\tIngrese el email del docente a asignar: " && cin >> emailDoc && !colDocentes->count(emailDoc)){
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              std::cout << "\tNo existe un docente con ese email. Por favor intente denuevo.\n";
            }
            while(!tipoCorrecto){
              cout << "\n\tIngrese que tipo de docente es: \n\t1)Teorico\n\t2)Practico\n\t3)Monitoreo\n\tOpcion: ";
              cin >> tipo;
              switch (tipo) {
                case 1:
                  tipoCorrecto = 1;
                  admite = fabrica->getIAsignatura()->asignarDocente(emailDoc,codigoAsig,teorico);
                break;
                case 2:
                  tipoCorrecto = 1;
                  admite = fabrica->getIAsignatura()->asignarDocente(emailDoc,codigoAsig,practico);
                break;
                case 3:
                  tipoCorrecto = 1;
                  admite = fabrica->getIAsignatura()->asignarDocente(emailDoc,codigoAsig,monitoreo);
                break;
                default:
                  cout << "\nOpcion no valida.\n";
                break;
              }
            }
            while(admite && !sn){
              cout << "\n\t¿Desea confirmar la asignación? (S/N) \n\tOpcion: ";
              cin >> entrada;
              switch (entrada) {
                case 'S':
                  sn = true;
                  no_pronto=false;
                  fabrica->getIAsignatura()->confirmarAsignacion();
                break;
                case 'N':
                  sn = true;
                  no_pronto=false;
                  fabrica->getIAsignatura()->cancelarAsignacion();
                break;
                default:
                  cout << "\n\tOpcion no válida.";
                break;
              }
            }
            if(!admite)
              cout << "\n\tError, la asignatura no admite el rol indicado.\n";
          }
        }
      }
    };
    void eliminarAsignatura(){
      string cod;
      bool no_termina=true;
      while(no_termina){
        set<dtAsignatura> nuevo = fabrica->getIAsignatura()->consultarAsignaturas();
        if(nuevo.begin()==nuevo.end()){
          cout << "\n\tNo existen asignaturas en el sistema.\n";
          no_termina = false;
        }
        else{
          for(auto it = nuevo.begin();it != nuevo.end();it++){
            cout << "\n\tNombre: " << it->getNombre()<< " Codigo: " << it->getCodigo();
          }
          bool aux=true;
          while(aux){
            while (std::cout << "\n\t¿Qué asignatura desea eliminar? (ingrese código): " && !(std::cin >> cod)) {
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              std::cout << "\tPor favor ingrese un numero.\n";
            }
            if(!colAsignaturas->count(cod)){
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              cout << "\tEl codigo no es valido. Por favor intente de nuevo.\n";
            }
            else//todo bien, era un numero y un codigo valido
              aux=false;
          }
          fabrica->getIAsignatura()->eliminarAsignatura(cod);
          bool sn = false;
          char entrada;
          while(!sn){
            cout << "\n\t¿Desea confirmacion la eliminación (1) o no (0)?: ";
            cin >> entrada;
            switch (entrada) {
              case '1':
                sn = true;
                no_termina=false;
                fabrica->getIAsignatura()->confirmarElim();
              break;
              case '0':
                sn = true;
                no_termina=false;
                fabrica->getIAsignatura()->cancelarElim();
              break;
              default:
                cout << "\n\tOpcion no válida.";
              break;
            }
          }
        }
      }
    };
    void tiempoDeDictado(){
      set<DtDictado> tiempos = fabrica->getIAsignatura()->tiempoDictado();
      for(auto it=tiempos.begin();it!=tiempos.end();++it){
        cout << it->getCodAsig() << it->getTiempoDictado();
      }
    };
    //estudiante
    bool iniciarSesionE(string email){
      bool res = colEstudiantes->count(email);
      if(res){
        fabrica->getIClase()->iniciarSesion(email,"pass");
        fabrica->getIUsuario()->iniciarSesion(email,"pass");
      }
      return res;
    };
    void inscribirAAsignatura(){
      bool sn = false;
      char entrada;
      set<dtAsignatura> noInscripto = fabrica->getIUsuario()->consultarAsigNoIns();
      if(noInscripto.begin()==noInscripto.end()){
        cout << "\n\tNo existen asignaturas sin inscribirse.\n";
      }
      else{
        cout <<"\n\tAsignaturas disponibles para inscripción:";
        for(auto it = noInscripto.begin();it != noInscripto.end();it++){
          cout << "\n\tNombre: " << it->getNombre()<< " Codigo: " << it->getCodigo();
        }
        string codigoAsig;

        bool aux=true;
        while(aux){
          while (std::cout << "\n\tIngrese el codigo de la asignatura a la que desea inscribirse: " && !(std::cin >> codigoAsig)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            std::cout << "\tPor favor ingrese un numero.\n";
          }
          if(!colAsignaturas->count(codigoAsig)){
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "\tEl codigo no es valido. Por favor intente de nuevo.\n";
          }
          else//todo bien, era un numero y un codigo valido
            aux=false;
        }
    		fabrica->getIUsuario()->inscribir(codigoAsig);
        while(!sn){
          cout << "\n\t¿Desea confirmar la inscripción? (S/N)\n\tOpcion: ";
          cin >> entrada;
          switch (entrada) {
            case 'S':
              sn = true;
              fabrica->getIUsuario()->confirmarInscripcion();
            break;
            case 'N':
              sn = true;
              fabrica->getIUsuario()->cancelarInscripcion();
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
          }
        }
      }
    };
    void asistirAClaseEnVivo(){
      bool sn = false;
      bool no_pronto = true;
      while(no_pronto){
        char entrada;
        set<dtAsignatura> asigIns = fabrica->getIClase()->consultarAsigIns();
        if(asigIns.begin()==asigIns.end()){
          cout << "\n\tEl estudiante no esta inscripto a ninguna asignatura.\n";
          no_pronto = 0;
        }
        else{
          cout <<"\n\tAsignaturas de estudiante:";
          for(auto it = asigIns.begin();it != asigIns.end();it++){
            cout << "\n\tNombre: " << it->getNombre()<< " Codigo: " << it->getCodigo();
          }
          string codigoAsig;
          bool aux = true;

          while(aux){
            while (std::cout << "\n\tIngrese el codigo de la asignatura de la que desea ver clases: " && !(std::cin >> codigoAsig)) {
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              std::cout << "\tPor favor ingrese un numero.\n";
            }
            if(!colAsignaturas->count(codigoAsig)){
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              cout << "\tEl codigo no es valido. Por favor intente de nuevo.\n";
            }
            else{//todo bien, era un numero y un codigo valido
              aux=false;
            }
          }

      		set<dtClase> setClasesAsig = fabrica->getIClase()->consultarClasesVivo(codigoAsig);

          if(setClasesAsig.begin()==setClasesAsig.end()){
            cout << "\n\tNo hay clases para asistir.\n";
            no_pronto = 0;
          }
          else{
            cout <<"\n\tClases de asignatura:";
            for(auto it = setClasesAsig.begin();it != setClasesAsig.end();it++){
              cout << "\n\tNombre: " << it->getNombre()<< " Codigo: " << it->getCodigo();
            }
            string codigoCla;
            aux = true;
            while(aux){
              while (std::cout << "\n\tIngrese el codigo de la clase que desea ver: " && !(std::cin >> codigoCla)) {
                std::cin.clear(); //clear bad input flag
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                std::cout << "\tPor favor ingrese un numero.\n";
              }
              if(!colClases->count(codigoCla)){
                std::cin.clear(); //clear bad input flag
                std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
                cout << "\tEl codigo no es valido. Por favor intente de nuevo.\n";
              }
              else//todo bien, era un numero, un codigo valido y no la esta viendo ya
                aux=false;
            }
        		dtClase claseAsistida = fabrica->getIClase()->asistirClaseVivo(codigoCla);
            while(!sn){
              cout << "\n\t¿Desea ver la clase "<<claseAsistida.getNombre()<< "? (S/N): ";
              cin >> entrada;
              switch (entrada) {
                case 'S':
                  sn = true;
                  no_pronto = false;
                  fabrica->getIClase()->confirmarAsistenciaVivo();
                break;
                case 'N':
                  sn = true;
                  no_pronto = false;
                  fabrica->getIClase()->cancelarAsistencia();
                break;
                default:
                  cout << "\n\tOpcion no válida.";
                break;
              }
            }
            no_pronto = 0;
          }
        }
      }
    };
    void finalizarAsistenciaAClaseEnVivo(){
      bool sn = false;
      bool no_pronto = true;
      while(no_pronto){
        char entrada;
        set<dtClase*> setClasesAsig = fabrica->getIClase()->consultarClasesParticipandoVivo();
        if(setClasesAsig.begin()==setClasesAsig.end()){
          cout << "\n\tEl estudiante no esta participando en ninguna clase.\n";
          no_pronto = 0;
        }
        else{
          for(auto it = setClasesAsig.begin();it != setClasesAsig.end();it++){
            cout << "\n\tNombre: " << (*it)->getNombre()<< " Codigo: " << (*it)->getCodigo();
          }
          string codigoCla;
          bool aux = true;
          while(aux){
            while (std::cout << "\n\tIngrese el codigo de la clase que desea dejar de ver: " && !(std::cin >> codigoCla)) {
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              std::cout << "\tPor favor ingrese un numero.\n";
            }
            bool encontre = false;
            for(auto it = setClasesAsig.begin(); it!=setClasesAsig.end();it++){
              if((*it)->getCodigo()==codigoCla){
                encontre = true;
                break;
              }
            }
            if(!encontre){
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              cout << "\tEl codigo no es valido. Por favor intente de nuevo.\n";
            }
            else//todo bien, era un numero y un codigo valido
              aux=false;
          }
          fabrica->getIClase()->finalizarAsistencia(codigoCla);
          while(!sn){
            cout << "\n\t¿Desea dejar de ver la clase ingresada? (S/N): ";
            cin >> entrada;
            switch (entrada) {
              case 'S':
                sn = true;
                no_pronto = false;
                fabrica->getIClase()->confirmarSalida();
              break;
              case 'N':
                sn = true;
                no_pronto = false;
                fabrica->getIClase()->cancelarSalida();
              break;
              default:
                cout << "\n\tOpcion no válida.";
              break;
            }
          }
        }
      }
    };
    //docente
    bool iniciarSesionD(string email){
      bool res = colDocentes->count(email);
      if(res){
        fabrica->getIClase()->iniciarSesion(email,"pass");
        fabrica->getIUsuario()->iniciarSesion(email,"pass");
      }
      return res;
    };
    void iniciarClase(){
      string nombre,email;
      string asig;
      char decision,hab;
      cout <<"\n\tAsignaturas en las que el docente participa:";
      set<dtAsignatura> opciones = fabrica->getIClase()->consultarAsignaturasDocente();
      if(opciones.begin()==opciones.end()){
          cout <<"\n\tEl docente no esta asignado a ninguna asignatura.\n";
      }
      else{
        for(auto it=opciones.begin();it!=opciones.end();++it){
          cout << "\n\tNombre: " << it->getNombre()<< "\tCodigo: " << it->getCodigo();
        }

        bool aux=true;
        while(aux){
          while (std::cout << "\n\tIngrese el codigo de la asignatura en la que desea iniciar una clase: " && !(std::cin >> asig)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            std::cout << "\tPor favor ingrese un numero.\n";
          }
          if(!colAsignaturas->count(asig)){
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "\tEl codigo no es valido. Por favor intente de nuevo.\n";
          }
          else//todo bien, era un numero y un codigo valido
            aux=false;
        }

        tipoClase tipo = fabrica->getIClase()->rolDocente(asig);
        cout << "\n\t¿Que nombre tiene la clase? ";
        getline(cin >> ws, nombre);
        int anio,mes,dia,hora,minutos;
        while (std::cout << "\n\tIngrese la fecha para iniciar la clase:\n\t\tAño: " && !(std::cin >> anio)) {
          std::cin.clear(); //clear bad input flag
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
          std::cout << "\tPor favor ingrese un numero.\n";
        }
        while (std::cout << "\n\t\tMes: " && !(std::cin >> mes)) {
          std::cin.clear(); //clear bad input flag
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
          std::cout << "\tPor favor ingrese un numero.\n";
        }
        while (std::cout << "\n\t\tDia: " && !(std::cin >> dia)) {
          std::cin.clear(); //clear bad input flag
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
          std::cout << "\tPor favor ingrese un numero.\n";
        }
        while (std::cout << "\n\t\tHora: " && !(std::cin >> hora)) {
          std::cin.clear(); //clear bad input flag
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
          std::cout << "\tPor favor ingrese un numero.\n";
        }
        while (std::cout << "\n\t\tMinutos: " && !(std::cin >> minutos)) {
          std::cin.clear(); //clear bad input flag
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
          std::cout << "\tPor favor ingrese un numero.\n";
        }
        fabrica->getIClase()->iniciarClase(asig,nombre,tipo,dtFecha(anio,mes,dia,hora,minutos,0));
        if(tipo==monitoreo){
          bool seguir = true;
          map<string,dtEstudiante*> habilitados = fabrica->getIClase()->consultarInscriptos();
          if(habilitados.empty())//si no hay inscriptos
            seguir = false;
          while(seguir){
            for(auto ith=habilitados.begin();ith!=habilitados.end();++ith){
              cout << "\n\tEmail: " << ith->first <<"\tCI: "<<ith->second->getCI();
            }
            while(cout << "\n\tIngrese email de quien quiera agregar a habilitados: " && cin >> email && !habilitados.count(email)){
              std::cin.clear(); //clear bad input flag
              std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
              std::cout << "\tNo existe un estudiante con ese email. Por favor intente denuevo.\n";
            }
            fabrica->getIClase()->agregarHabilitado(email);
            habilitados.erase(email);
            if(habilitados.empty()){
              seguir = false;
              cout << "\n\tNo quedan estudiantes para agregar.";
            }
            else{
              cout << "\n\t¿Desea seguir agregando habilitados? (S/N)";
              cin >> hab;
              if(hab=='N')
                seguir=false;
              else if(hab!='S')
                cout << "\n\tOpcion no valida";
              }
            }

        }
        dtInfoClase info = fabrica->getIClase()->desplegarInfoClase();
        cout << "\n\tNombre de clase: " << info.getNombre() << "\n\tDe la asignatura: " << info.getCodigo() << "\n\tIniciada por: "  << info.getIniciadaPor() << "\n\tFecha: " << info.getFechaInicio().getAnio() << "/"<< info.getFechaInicio().getMes() << "/"<< info.getFechaInicio().getDia() << " " << info.getFechaInicio().getHora() << ":"<< info.getFechaInicio().getMinuto();
        cout << "\n\tLista de habilitados:";
        array<string, 15> arr = info.getHabilitados();
        for(int i=0; i<info.getCantHabilitados(); i++){
          cout << "\n\t\t" << arr[i];
        }
        bool parar=false;
        while(!parar){
          cout << "\n\t¿Desea confirmar (S/N)? ";
          cin >> decision;
          switch(decision){
            case 'S':
              parar=true;
              fabrica->getIClase()->confirmarInicio();
            break;
            case 'N':
              parar=true;
              fabrica->getIClase()->cancelarInicio();
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
          }
        }
      }
    };
    void finalizarClase(){
    string clase;
    char decision;
    set<dtClase> clasesVivo = fabrica->getIClase()->consultarClasesEnVivo();
    for(auto it=clasesVivo.begin();it!=clasesVivo.end();++it){
      cout << "\n\tNombre: " << it->getNombre() << "\tCodigo: " << it->getCodigo();
    }
    cout << "\n\t¿Cual clase desea finalizar? (ingrese código):";
    cin >> clase;
    fabrica->getIClase()->finalizarClase(clase);
    bool parar=false;
    while(!parar){
      cout << "\n\t¿Desea confirmar finalizacion? (S/N): ";
      cin >> decision;
      switch(decision){
        case 'S':
          parar=true;
          fabrica->getIClase()->confirmarFin();
        break;
        case 'N':
          parar=true;
          fabrica->getIClase()->cancelarFin();
        break;
        default:
          cout << "\n\tOpcion no válida.";
        break;
      }
    }
    };
    void tiempoDeAsistencia(){
      string cod;
      set<dtAsignatura> inscripto = fabrica->getIClase()->consultarAsignaturasDocente();
      if(inscripto.begin()==inscripto.end()){
        cout << "\n\tEl docente no esta asignado a ninguna asignatura.\n";
      }
      else{
        for(auto it=inscripto.begin();it!=inscripto.end();++it){
          cout << "\n\tNombre: " << it->getNombre() << "\tCodigo: " << it->getCodigo();
        }

        bool aux=true;
        while(aux){
          while (std::cout << "\n\t¿De que asignatura desea calcular el tiempo de asistencia promedio a las clases?: " && !(std::cin >> cod)) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            std::cout << "\tPor favor ingrese un numero.\n";
          }
          if(!colAsignaturas->count(cod)){
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
            cout << "\tEl codigo no es valido. Por favor intente de nuevo.\n";
          }
          else//todo bien, era un numero y un codigo valido
            aux=false;
        }
        set<DtTiempoDeClase> tiempos = fabrica->getIClase()->consultarTiempoClaseDocente(cod);
        for(auto itt=tiempos.begin();itt!=tiempos.end();++itt){
          cout << "\n\tNombre: " << itt->getNombre() << "\tCodigo: " << itt->getCodClase() << "\n\tTiempo promedio en segundos: " << itt->getTiempo();
        }
      }
    };
    //ambos
    void enviarMensaje(){
      string clase;
      char decision;
      set<dtClase> clasesP = fabrica->getIClase()->consultarClasesParticipando();
      for(auto itc = clasesP.begin(); itc!=clasesP.end();itc++){
        cout << "\n\tNombre: "<<itc->getNombre()<< " Codigo: " <<itc->getCodigo();
      }

      bool aux=true;
      while(aux){
        while (std::cout << "\n\t¿A cual clase desea enviar un mensaje? (ingrese codigo): " && !(std::cin >> clase)) {
          std::cin.clear(); //clear bad input flag
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
          std::cout << "\tPor favor ingrese un numero.\n";
        }
        if(!colClases->count(clase)){
          std::cin.clear(); //clear bad input flag
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
          cout << "\tEl codigo no es valido. Por favor intente de nuevo.\n";
        }
        else//todo bien, era un numero y un codigo valido
          aux=false;
      }
      bool primerMensaje = false;
      set<dtMensaje> msjs = fabrica->getIClase()->consultarMensajes(clase);
      if(msjs.size()==0){
        cout << "\n\tAun no hay mensajes en esta clase, el suyo sera el primero.";
        primerMensaje = 1;
      }
      cout << "\n\tMensajes en la clase: ";
      for(auto itm = msjs.begin(); itm!=msjs.end();itm++){
        cout << "\n\tId: "<<itm->getId()<< " Contenido: " <<itm->getContenido();
      }
      bool parar=false;
      string mensaje;
      int aResponder;
      while(!parar){
        if(primerMensaje){
          parar=true;
          cout << "\n\tEscriba su mensaje: ";
          getline(cin >> ws, mensaje);
          fabrica->getIClase()->enviarMensaje(mensaje);
        }
        else{
          cout << "\n\t¿Su mensaje es en respuesta a otro? (S/N): ";
          cin >> decision;
          switch(decision){
            case 'S':
              parar=true;
              /*msjs = fabrica->getIClase()->consultarMensajes(clase);
              for(auto itm2 = msjs.begin(); itm2!=msjs.end();itm2++){
                cout << "\n\t\tId: "<<itm2->getId()<< " Contenido: " <<itm2->getContenido();
              }*/
              cout << "\n\t¿A que mensaje responde? (ingrese la id): ";
              cin >> aResponder;
              cout << "\n\tEscriba su mensaje: ";
              getline(cin >> ws, mensaje);
              fabrica->getIClase()->enviarRespuesta(aResponder,mensaje);
            break;
            case 'N':
              parar=true;
              cout << "\n\tEscriba su mensaje: ";
              getline(cin >> ws, mensaje);
              fabrica->getIClase()->enviarMensaje(mensaje);
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
          }
        }
      }
      parar=false;
      while(!parar){
        cout << "\n\tDesea confirmar el envio? (S/N): ";
        cin >> decision;
        switch(decision){
          case 'S':
            parar=true;
            fabrica->getIClase()->confirmarEnvio();
          break;
          case 'N':
            parar=true;
            fabrica->getIClase()->cancelarEnvio();
          break;
          default:
            cout << "\n\tOpcion no válida.";
          break;
        }
      }
    };
    void suscribirANotificaciones(){
  		fabrica->getIUsuario()->cambiarModoSus(3);
      bool parar=false;
      char decision;
      while(!parar){
        cout << "\n\t¿Desea suscribirse a notificaciones (modo 3)? (S/N): ";
        cin >> decision;
        switch(decision){
          case 'S':
            parar=true;
            fabrica->getIUsuario()->confirmarCambio();
          break;
          case 'N':
            parar=true;
            fabrica->getIUsuario()->cancelarCambio();
          break;
          default:
            cout << "\n\tOpcion no válida.";
          break;
        }
      }
    };
    void consultarNotificaciones(){
      set<dtNotificacion*> notifs = fabrica->getIUsuario()->consultarNotifs();
      if(notifs.begin()==notifs.end()){
        cout << "\n\tNo tiene notificaciones.";
      }
      else{
        for(auto it=notifs.begin();it!=notifs.end();++it){
          cout << "\n\tEn la clase Codigo " << (*it)->getCodigoClase() << " de la asignatura Codigo " << (*it)->getCodigoAsig() << " recibiste la respuesta: \""<< (*it)->getContenidoMensaje() << "\"";
        }
      }
    };
    //display
    void getDatosUsuarios(){
      cout << "\n\tEstudiantes en el sistema:";
      for(auto it = colEstudiantes->begin(); it!=colEstudiantes->end();it++){
        cout << "\n\t\tNombre: "<<it->second->getNombre()<< " Email: " <<it->second->getEmail();
      }
      cout << "\n\tDocentes en el sistema:";
      for(auto it = colDocentes->begin(); it!=colDocentes->end();it++){
        cout << "\n\t\tNombre: "<<it->second->getNombre()<< " Email: " <<it->second->getEmail();
      }
    };
    void getDatosAsignaturas(){
      cout << "\n\tAsignaturas en el sistema: ";
      for(auto it = colAsignaturas->begin(); it!=colAsignaturas->end();it++){
        cout << "\n\t\tNombre: "<<it->second->getNombre()<< " Codigo: " <<it->second->getCodigo();
      }
    };
    void getDatosClases(){
      cout << "\n\tClases en el sistema: ";
      for(auto it = colClases->begin(); it!=colClases->end();it++){
        cout << "\n\t\tNombre: \""<<it->second->getNombre()<< "\" Codigo: " <<it->second->getCodigo() << " Creada por: "<<it->second->getEmailCreador()<< " Finalizada: ";
        if(it->second->getFechaFin()==fechaNula)
          cout << "No";
        else
          cout << "Si";
      }
    };
    void getDatosMensajes(){
      cout << "\n\tMensajes en el sistema:";
      for(auto it = colMensajes->begin(); it!=colMensajes->end();it++){
        cout << "\n\t\tId: "<<it->second->getId() << " En clase: "<<it->second->getClase()->getCodigo();
        if(it->second->getEnRespuestaA()){
          cout << " En respuesta a: " <<it->second->getEnRespuestaA()->getId();
        }
        cout << "\n\t\t\""<<it->second->getContenido()<<"\"";
      }
    }
};

Factory* Sistema::fabrica = 0;
Sistema* Sistema::instancia = 0;
HandlerMensajes* Sistema::handler = 0;
map<string,Usuario*>* Sistema::colUsuarios = 0;
map<string,Estudiante*>* Sistema::colEstudiantes = 0;
map<string,Docente*>* Sistema::colDocentes = 0;
map<string,Asignatura*>* Sistema::colAsignaturas = 0;
map<string,Clase*>* Sistema::colClases = 0;
map<int,Mensaje*>* Sistema::colMensajes = 0;
Reloj* Sistema::reloj = NULL;

Sistema* Sistema::getInstancia(){
    if (instancia == 0)    {
        instancia = new Sistema();
        //creo la factory
        fabrica = fabrica->getInstancia();
        //creo el handler
        handler = new HandlerMensajes();
        //creo el reloj
        reloj = reloj->getInstancia();
        //creo las colecciones
        colUsuarios = new map<string,Usuario*>;
        colEstudiantes = new map<string,Estudiante*>;
        colDocentes = new map<string,Docente*>;
        colAsignaturas = new map<string,Asignatura*>;
        colClases = new map<string,Clase*>;
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
        fabrica->getIAsignatura()->setColMens(colMensajes);
        fabrica->getIClase()->setColEst(colEstudiantes);
        fabrica->getIClase()->setColDoc(colDocentes);
        fabrica->getIClase()->setColAsig(colAsignaturas);
        fabrica->getIClase()->setColCla(colClases);
        fabrica->getIClase()->setColMens(colMensajes);
        fabrica->getIClase()->setHandler(handler);
        handler->setColMens(colMensajes);
        handler->setColCla(colClases);
        //inicializo el reloj del controlador clase
        fabrica->getIClase()->setReloj(reloj->getInstancia());
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

  //caso de prueba

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
        cout << "\t5) Asignar docente a asignatura" << endl;
        cout << "\t6) Eliminar asignatura del sistema" << endl;
        cout << "\t7) Ver tiempo de dictado de cada asignatura" << endl;
        cout << "\t8) Atras" << endl << endl;
        cout << "\n \tOpcion: ";
        cin >> tecla;
        switch (tecla){//agregar las operaciones
          case '1':
            s->consultarReloj();
          break;
          case '2':
            s->modificarReloj();
          break;
          case '3':
            s->altaDeUsuario();
          break;
          case '4':
            s->altaDeAsignatura();
          break;
          case '5':
            s->asignarDocenteAAsignatura();
          break;
          case '6':
            s->eliminarAsignatura();
          break;
          case '7':
            s->tiempoDeDictado();
          break;
          case '8':
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
          inicioSesion = s->iniciarSesionD(email);//no checkea password, siempre admite si el email existe
          if(inicioSesion){
            inicioSesion = true;
            cout << "\nSeleccione una operación de docente:" << endl;
            cout << "\t1) Iniciar una clase" << endl;
            cout << "\t2) Finalizar una clase" << endl;
            cout << "\t3) Consultar tiempo promedio de asistencia a clases" << endl;
            cout << "\t4) Enviar un mensaje" << endl;
            cout << "\t5) Suscribirse a notificaciones" << endl;
            cout << "\t6) Consultar notificaciones" << endl;
            cout << "\t7) Atras" << endl << endl;
            cout << "\n\tOpcion: ";
            cin >> tecla;
            switch (tecla){//agregar las operaciones
              case '1':
                s->iniciarClase();
              break;
              case '2':
                s->finalizarClase();
              break;
              case '3':
                s->tiempoDeAsistencia();
              break;
              case '4':
                s->enviarMensaje();
              break;
              case '5':
                s->suscribirANotificaciones();
              break;
              case '6':
                s->consultarNotificaciones();
              break;
              case '7':
              break;
              default:
                cout << "\nOpcion no valida.\n";
              break;
            }
          }
          else{
            cout << "Credenciales no validas ¿Quiere intentar de nuevo? (S/N)" << endl;
            cin >> tecla;
            switch (tecla) {
              case 'S':
              break;
              case 'N':
                inicioSesion=true;
              break;
            }
          }
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
          inicioSesion = s->iniciarSesionE(email);//no checkea password, siempre admite si el email existe
          if(inicioSesion){
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
              case '1':
                s->inscribirAAsignatura();
              break;
              case '2':
                s->asistirAClaseEnVivo();
              break;
              case '3':
                s->finalizarAsistenciaAClaseEnVivo();
              break;
              case '4':
                s->enviarMensaje();
              break;
              case '5':
                s->suscribirANotificaciones();
              break;
              case '6':
                s->consultarNotificaciones();
              break;
              case '7':
              break;
              default:
                cout << "\nOpcion no valida.\n";
              break;
            }
          }
          else{
            cout << "Credenciales no validas ¿Quiere intentar de nuevo? (S/N)" << endl;
            cin >> tecla;
            switch (tecla) {
              case 'S':
              break;
              case 'N':
                inicioSesion=true;
              break;
            }
          }
        }
      break;
      case '4':
        s->cargarDatos();
        cout << "\nCasos de pruebas cargados."<<endl;
      break;
      case '5':
        s->getDatosUsuarios();
        s->getDatosAsignaturas();
        s->getDatosClases();
        s->getDatosMensajes();
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
