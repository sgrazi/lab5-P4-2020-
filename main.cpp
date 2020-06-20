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
      bool ed,sn,no_pronto;
      no_pronto = true;
      ed = 0;
      sn = 0;
      while(no_pronto){
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
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
          }
        }
      }
    };
    void altaDeAsignatura(){
      string nombreAsig,e8;
      char e6,e7;
      int codigoAsig;
      bool teorico,practico,monitoreo;
      bool sn = false;
      bool no_pronto=true;
      while(no_pronto){
        cout << "\n\t¿Cuál es el nombre de la asignatura?: ";
        cin >> nombreAsig;
        while (std::cout << "\n\t¿Cuál es el código de la asignatura?: " && !(std::cin >> codigoAsig)) {
          std::cin.clear(); //clear bad input flag
          std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
          std::cout << "\tPor favor ingrese un numero.\n";
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
      int codigoAsig, tipo;
      char entrada;
      string emailDoc;
      bool tipoCorrecto = false;
      bool sn = false;
      bool admite = true;
      bool no_pronto = true;
      while(no_pronto){
        set<dtAsignatura> asignaturas = fabrica->getIAsignatura()->consultarAsignaturas();
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
          cout << "\n\tIngrese que tipo de docente es: \n\t1)Teorico\n\t2)Practico\n\t3)Monitoreo\n\tOpcion:";
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
          cout << "\n\t¿Desea confirmar la asignación? (S/N) \n\tOpcion: ";
      }
    };
    void eliminarAsignatura(){
    int cod;
    char d;
    bool no_termina=true;
    while(no_termina){
      fabrica->getIAsignatura()->consultarAsignaturas();
      cout << "\n\t¿Qué asignatura desea eliminar? (ingrese código):";
      cin >> cod;
      fabrica->getIAsignatura()->eliminarAsignatura(cod);
      cout << "\n\t¿Desea confirmacion la eliminación (1) o no (0))?:";
      cin >> d;
      switch(d){
        case '1':
          no_termina=false;
          fabrica->getIAsignatura()->confirmarElim();
        break;
        case '0':
          no_termina=false;
          fabrica->getIAsignatura()->cancelarElim();
        break;
        default:
          cout << "\n\tOpcion no válida.";
        break;
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
      cout <<"\n\tAsignaturas disponibles para inscripción:";
      set<dtAsignatura> noInscripto = fabrica->getIUsuario()->consultarAsigNoIns();
      for(auto it = noInscripto.begin();it != noInscripto.end();it++){
        cout << "\n\tNombre: " << it->getNombre()<< " Codigo: " << it->getCodigo();
      }
      int codigoAsig;
      while (std::cout << "\n\tIngrese el codigo de la asignatura a la que desea inscribirse: " && !(std::cin >> codigoAsig)) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input
        std::cout << "\tPor favor ingrese un numero.\n";
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
    };
    void asistirAClaseEnVivo(){
      bool sn = false;
      bool no_pronto = true;
      while(no_pronto){
        char entrada;
        cout <<"\n\tAsignaturas de estudiante:";
        set<dtAsignatura> asigIns = fabrica->getIClase()->consultarAsigIns();
        for(auto it = asigIns.begin();it != asigIns.end();it++){
          cout << "\n\tNombre: " << it->getNombre()<< " Codigo: " << it->getCodigo();
        }
        int codigoAsig;
        cout << "\n\tIngrese el codigo de la asignatura de la que desea ver clases: ";
        cin >> codigoAsig;//QUE PASA SI ME TIRAN UN VALOR NO VALIDO
        cout <<"\n\tClases de asignatura:";
    		set<dtClase> setClasesAsig = fabrica->getIClase()->consultarClasesVivo(codigoAsig);
        for(auto it = setClasesAsig.begin();it != setClasesAsig.end();it++){
          cout << "\n\tNombre: " << it->getNombre()<< " Codigo: " << it->getCodigo();
        }
        int codigoCla;
        cout << "\n\tIngrese el codigo de la clase que desea ver: ";
        cin >> codigoCla;//QUE PASA SI ME TIRAN UN VALOR NO VALIDO
    		dtClase claseAsistida = fabrica->getIClase()->asistirClaseVivo(codigoCla);
        while(!sn){
          cout << "\n\t¿Desea ver la clase "<<claseAsistida.getNombre()<< "?";
          cin >> entrada;
          switch (entrada) {
            case 'S':
              sn = true;
              fabrica->getIClase()->confirmarAsistenciaVivo();
            break;
            case 'N':
              sn = true;
              fabrica->getIClase()->cancelarAsistencia();
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
          }
        }
      }
    };
    void finalizarAsistenciaAClaseEnVivo(){
      bool sn = false;
      char entrada;
      bool no_pronto = true;
      while(no_pronto){
        cout <<"\n\tClases asistiendo:";
    		set<dtClase*> setClasesAsig = fabrica->getIClase()->consultarClasesParticipandoVivo();
        for(auto it = setClasesAsig.begin();it != setClasesAsig.end();it++){
          cout << "\n\tNombre: " << (*it)->getNombre()<< " Codigo: " << (*it)->getCodigo();
        }
        int codigoCla;
        cout << "\n\tIngrese el codigo de la clase que desea dejar de ver: ";
        cin >> codigoCla;//QUE PASA SI ME TIRAN UN VALOR NO VALIDO
    		fabrica->getIClase()->finalizarAsistencia(codigoCla);
        while(!sn){
          cout << "\n\t¿Desea dejar de ver la clase ingresada?";
          cin >> entrada;
          switch (entrada) {
            case 'S':
              sn = true;
              fabrica->getIClase()->confirmarSalida();
            break;
            case 'N':
              sn = true;
              fabrica->getIClase()->cancelarSalida();
            break;
            default:
              cout << "\n\tOpcion no válida.";
            break;
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
      string nombre,cedula;
      int asig;
      char decision,hab;
      set<dtAsignatura> opciones = fabrica->getIClase()->consultarAsignaturasDocente();
      for(auto it=opciones.begin();it!=opciones.end();++it){
        cout << "\n\tNombre: " << it->getNombre()<< "\n\tCodigo: " << it->getCodigo();
      }
      cout << "\n\t¿En cual asignatura desea inciar una clase? (ingrese código):";
      cin >> asig;
      tipoClase tipo = fabrica->getIClase()->rolDocente(asig);
      cout << "\n\t¿Que nombre tiene la clase?";
      cin >> nombre;
      fabrica->getIClase()->iniciarClase(asig,nombre,tipo,dtFecha(1,1,1,1,1,1)); //METER RELOJ
      if(tipo==monitoreo){
        bool seguir = true;
        while(seguir){
          map<string,dtEstudiante*> habilitados = fabrica->getIClase()->consultarInscriptos();
          for(auto ith=habilitados.begin();ith!=habilitados.end();++ith){
            cout << "\n\tCI: " << ith->first;
          }
          cout << "\n\tIngrese cedula de quien quiera agregar a habilitados:";
          cin >> cedula;
          fabrica->getIClase()->agregarHabilitado(cedula);
          cout << "\n\t¿Desea seguir agregando habilitados? (S/N)";
          cin >> hab;
          if(hab=='N')
            seguir=false;
          else if(hab!='S')
            cout << "\n\tOpcion no valida";
          }
      }
      dtInfoClase info = fabrica->getIClase()->desplegarInfoClase();
      cout << "\n\tNombre de clase: " << info.getNombre() << "\n\tCodigo de clase: " << info.getCodigo() << "\n\tIniciada por: "  << info.getIniciadaPor();
      bool parar=false;
      while(!parar){
        cout << "\n\t¿Desea confirmar (S/N)?";
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
    };
    void finalizarClase(){
    int clase;
    char decision;
    set<dtClase> clasesVivo = fabrica->getIClase()->consultarClasesEnVivo();
    for(auto it=clasesVivo.begin();it!=clasesVivo.end();++it){
      cout << "\n\tNombre: " << it->getNombre() << "\n\tCodigo: " << it->getCodigo();
    }
    cout << "\n\t¿Cual clase desea finalizar? (ingrese código):";
    cin >> clase;
    fabrica->getIClase()->finalizarClase(clase);
    bool parar=false;
    while(!parar){
      cout << "\n\t¿Desea confirmar finalizacion? (S/N)";
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
    int cod;
    set<dtAsignatura> inscripto = fabrica->getIClase()->consultarAsignaturasDocente();
    for(auto it=inscripto.begin();it!=inscripto.end();++it){
      cout << "\n\tNombre: " << it->getNombre() << "\n\tCodigo: " << it->getCodigo();
    }
    cout << "\n\t¿De que asignatura desea calcular el tiempo de asistencia promedio a las clases? (ingrese codigo):";
    cin >> cod;
    set<DtTiempoDeClase> tiempos = fabrica->getIClase()->consultarTiempoClaseDocente(cod);
    for(auto itt=tiempos.begin();itt!=tiempos.end();++itt){
      cout << "\n\tNombre: " << itt->getNombre() << "\n\tCodigo: " << itt->getCodClase() << "\n\tTiempo promedio: " << itt->getTiempo();
    }
    };
    //ambos
    void enviarMensaje();
    void suscribirANotificaciones();
    void consultarNotificaciones();
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
        cout << "\n\t\tNombre: "<<it->second->getNombre()<< " Codigo: " <<it->second->getCodigo();
      }
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
        cout << "\t5) Asignar docente a asignatura" << endl;
        cout << "\t6) Eliminar asignatura del sistema" << endl;
        cout << "\t7) Ver tiempo de dictado de cada asignatura" << endl;
        cout << "\t8) Atras" << endl << endl;
        cout << "\n \tOpcion: ";
        cin >> tecla;
        switch (tecla){//agregar las operaciones
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
