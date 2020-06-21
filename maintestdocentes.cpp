#include <iostream>
#include <map>

#include "include/asignatura.h"
#include "include/clase.h"
#include "include/controladorAsignatura.h"
#include "include/controladorClase.h"
#include "include/controladorUsuario.h"
#include "include/docente.h"
#include "include/usrCla.h"
#include "include/estudiante.h"
#include "include/handlerMensajes.h"
#include "include/iControladorAsignatura.h"
#include "include/iControladorClase.h"
#include "include/iControladorUsuario.h"
#include "include/monitoreo.h"
#include "include/practico.h"
#include "include/rol.h"
#include "include/teorico.h"
#include "include/usuario.h"
#include "include/visualizacion.h"
#include "include/dtAsignatura.h"
#include "include/dtClase.h"
#include "include/dtDocente.h"
#include "include/dtEstudiante.h"
#include "include/dtFecha.h"
#include "include/dtUsuario.h"


using namespace std;


map<string,Usuario*> coleccionGlobalUsuarios;
map<string,Estudiante*> coleccionGlobalEstudiantes;
map<string,Docente*> coleccionGlobalDocentes;
map<int,Asignatura*> coleccionGlobalAsignaturas;
map<int,Clase*> coleccionGlobalClases;
map<int,Mensaje*> coleccionGlobalMensajes;
int main(){

  map<string,Usuario*>* colUsuarios = &coleccionGlobalUsuarios;
  map<string,Estudiante*>* colEstudiantes = &coleccionGlobalEstudiantes;
  map<string,Docente*>* colDocentes = &coleccionGlobalDocentes;
  map<int,Asignatura*>* colAsignaturas = &coleccionGlobalAsignaturas;
  map<int,Clase*>* colClases = &coleccionGlobalClases;
  map<int,Mensaje*>* colMensajes = &coleccionGlobalMensajes;


  HandlerMensajes* h = new HandlerMensajes();

  ControladorUsuario* Cu = ControladorUsuario::getInstancia();
  ControladorAsignatura* Ca = ControladorAsignatura::getInstancia();
  ControladorClase* Cc = ControladorClase::getInstancia();

 
  Cu->setColUser(colUsuarios);
  Cu->setColEst(colEstudiantes);
  Cu->setColDoc(colDocentes);
  Cu->setColAsig(colAsignaturas);
  Cu->setHandler(h);
  Ca->setColDoc(colDocentes);
  Ca->setColAsig(colAsignaturas);
  Ca->setColCla(colClases);
  Cc->setColEst(colEstudiantes);
  Cc->setColDoc(colDocentes);
  Cc->setColAsig(colAsignaturas);
  Cc->setColCla(colClases);
  Cc->setColMens(colMensajes);
  Cc->setHandler(h);
  h->setColMens(colMensajes);
  h->setColCla(colClases);

  
 //ALTA DE ESTUDIANTE
  Cu->agregarEstudiante("Roberto Parra","1234","roberto@mail.com","url","12345678");//E1 roberto@mail.com Roberto Parra 12345678
  Cu->confirmarAlta();
  
  Cu->agregarEstudiante("Ana Rodriguez","1234","ana@mail.com","url","23456789");   // E2 ana@mail.com Ana Rodriguez 23456789
  Cu->confirmarAlta();
  
  Cu->agregarEstudiante("Ramon Valdez","1234","ramon@mail.com","url","34567890"); //  E3 ramon@mail.com Ramon Valdez 34567890
  Cu->confirmarAlta();
  
  //ALTA DE DOCENTE
  Cu->agregarDocente("Juan Perez","123","juan@mail.com","url","INCO");    // D1  juan@mail.com Juan Perez   INCO 
  Cu->confirmarAlta();
  Cu->agregarDocente("Maria Pires","123","maria@mail.com","url","INCO");   //D2  maria@mail.com Maria Pires INCO
  Cu->confirmarAlta();
  Cu->agregarDocente("Jorge Chacho","123","jorge@mail.com","url","INCO");  //D3 jorge@mail.com Jorge Chacho INCO
  Cu->confirmarAlta();
  Cu->confirmarAlta();

  //ALTA DE ASIG
  Ca->agregarAsignatura("Programacion 1","P1",1,1,1);//A1 P1 Programacion 1 Teórico, Práctico, Monitoreo
  Ca->confirmarAlta();
  Ca->agregarAsignatura("Programacion 2","P2",1,1,1);//A2 P2 Programacion 2 Teórico, Práctico, Monitoreo
  Ca->confirmarAlta();
  Ca->agregarAsignatura("Programacion 3","P3",1,1,0);//A3 P3 Programacion 3 Teórico, Práctico
  Ca->confirmarAlta();
 

  //asigno el docente
  Ca->asignarDocente("juan@mail.com","P1",teorico); //D1 A1 Teórico
  Ca->confirmarAsignacion();
  Ca->asignarDocente("maria@mail","P1",practico); //D2 A1 Práctico
  Ca->confirmarAsignacion();
  Ca->asignarDocente("jorge@mail.com","P1",monitoreo); //D3 A1 Monitoreo
  Ca->confirmarAsignacion();



  //INSCRIPCION A ASIGNATURA
  Cc->iniciarSesion("roberto@mail.com","1234");// E1 A1
  Cu->inscribir("P1");
  Cu->confirmarInscripcion();
  
  Cc->iniciarSesion("ana@mail.com","1234");// E2 A1,A2
  Cu->inscribir("P1");
  Cu->confirmarInscripcion();
  Cu->inscribir("P2");
  Cu->confirmarInscripcion();
  
  Cc->iniciarSesion("ramon@mail.com","1234");// E3 A1
  Cu->inscribir("P1");
  Cu->confirmarInscripcion();




  //INICIO DE CLASE
  Cc->iniciarSesion("emailD","123");
  Cc->iniciarSesion("emailD","123");

  
  dtFecha* fecha = new dtFecha();
  fecha->setAnio(2020);
  fecha->setMes(5);
  fecha->setDia(1);
  fecha->setHora(9);
  fecha->setMinuto(0);
  fecha->setSegundo(0);

  Cc->iniciarClase("P1","Intro Teórico",teorico,*fecha);//C1 A1 Intro Teórico 01/05/20 - 9am 01/05/20 - 10am D1
  Cc->confirmarInicio();
  
  dtFecha* fecha = new dtFecha();
  fecha->setAnio(2020);
  fecha->setMes(5);
  fecha->setDia(3);
  fecha->setHora(9);
  fecha->setMinuto(0);
  fecha->setSegundo(0);

  Cc->iniciarClase("P1","Tema 1",teorico,*fecha);//C2 A1 Tema 1 Teórico 03/05/20 - 9am 03/05/20 - 10am D1
  Cc->confirmarInicio();
  
 dtFecha* fecha = new dtFecha();
  fecha->setAnio(2020);
  fecha->setMes(5);
  fecha->setDia(8);
  fecha->setHora(9);
  fecha->setMinuto(0);
  fecha->setSegundo(0);

  Cc->iniciarClase("P1","Tema 2",teorico,*fecha);//C3 A1 Tema 2 Teórico 08/05/20 - 9am 08/05/20 - 10am D1
  Cc->confirmarInicio();

  dtFecha* fecha = new dtFecha();
  fecha->setAnio(2020);
  fecha->setMes(5);
  fecha->setDia(2);
  fecha->setHora(16);
  fecha->setMinuto(0);
  fecha->setSegundo(0);

  Cc->iniciarClase("P1","Pra 1",practico,*fecha);//C4 A1 Pra 1 Práctico 02/05/20 - 4pm 02/05/20 - 5pm D2
  Cc->confirmarInicio();
  
  dtFecha* fecha = new dtFecha();
  fecha->setAnio(2020);
  fecha->setMes(5);
  fecha->setDia(3);
  fecha->setHora(16);
  fecha->setMinuto(0);
  fecha->setSegundo(0);

  Cc->iniciarClase("P1","Pra 2",practico,*fecha);//C5 A1 Pra 2 Práctico 03/05/20 - 4pm 03/05/20 - 5pm D2
  Cc->confirmarInicio();
  
  
  dtFecha* fecha = new dtFecha();
  fecha->setAnio(2020);
  fecha->setMes(5);
  fecha->setDia(4);
  fecha->setHora(17);
  fecha->setMinuto(0);
  fecha->setSegundo(0);

  Cc->iniciarClase("P1","06/01/20",monitoreo,*fecha);//C6 A1 06/01/20 Monitoreo 04/05/20 - 4pm 04/05/20 - 5pm D3
  Cc->confirmarInicio();
  



  //ASISTENCIA A CLASE EN VIVO
    Cu->iniciarSesion("roberto@mail.com","1234");//E1 C1 01/05/20 - 09:01am 01/05/20 - 09:21am
    dtClase clase1 = Cc->asistirClaseVivo("Intro Teórico"); 
    Cc->confirmarAsistenciaVivo();   
    Cc->iniciarSesion("ana@mail.com","1234");//E2 C1 01/05/20 - 09:02am 01/05/20 - 09:32am
    dtClase clase1 = Cc->asistirClaseVivo("Intro Teórico");
    Cc->confirmarAsistenciaVivo();
    Cc->iniciarSesion("ramon@mail.com","1234");//E3 C1 01/05/20 - 09:03am 01/05/20 - 09:43am
    dtClase clase1 = Cc->asistirClaseVivo("Intro Teórico");
    Cc->confirmarAsistenciaVivo();
    Cc->iniciarSesion("ramon@mail.com","1234");//E3 C6 04/05/20 – 4:00pm 04/05/20 – 5:00pm
    dtClase clase1 = Cc->asistirClaseVivo("06/01/20"); 
    Cc->confirmarAsistenciaVivo();
    Cc->confirmarAsistenciaVivo();










Cc->enviarMensaje("Bienvenidos!");//M1 D1 C1 01/05/20 - 09:01am Bienvenidos! -
Cc->enviarMensaje("Confirmen materiales por favor.");//M2 D1 C1 01/05/20 - 09:02 am Confirmen materiales por favor. -
Cc->enviarMensaje("Comparto pantalla");//M3 D3 C6 04/05/20 - 04:01pm Comparto pantalla. -
Cc->enviarRespuesta(1,"Listo para aprender");//M4 E1 C1 01/05/20 - 09:05am Listo para aprender M1
Cc->enviarRespuesta(4,"Me alegro");//M5 D1 C1 01/05/20 - 09:06am Me alegro M4
Cc->enviarRespuesta(2,"Todo listo");//M6 E2 C1 01/05/20 - 09:06am Todo listo M2
Cc->enviarRespuesta(3,"Ya la vemos");//M7 E3 C6 04/05/20 - 04:05pm Ya la vemos M3





      Cc->finalizarClase(0);

      Cc->confirmarFin();

  





  return 0;
}
>
