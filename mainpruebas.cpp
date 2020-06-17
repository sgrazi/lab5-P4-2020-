#include <iostream>
#include <map>

#include "include/asignatura.h"
#include "include/clase.h"
#include "include/controladorAsignatura.h"
#include "include/controladorClase.h"
#include "include/controladorUsuario.h"
#include "include/docente.h"
#include "include/usrCla.h"
//#include "include/headers/estrategiaModoSus1.h"
//#include "include/headers/estrategiaModoSus2.h"
//#include "include/headers/estrategiaModoSus3.h"
//#include "include/headers/estrategiaNotifs.h"
#include "include/estudiante.h"
//#include "include/headers/factory.h"
#include "include/handlerMensajes.h"
#include "include/iControladorAsignatura.h"
#include "include/iControladorClase.h"
#include "include/iControladorUsuario.h"
//#include "include/headers/mensaje.h"
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
//#include "include/dts/dtMensaje.h"
//#include "include/dts/dtMonitoreo.h"
//#include "include/dts/dtNotificacion.h"
//#include "include/dts/dtPractico.h"
//#include "include/dts/dtRol.h"
//#include "include/dts/dtTeorico.h"
#include "include/dtUsuario.h"
//#include "include/dts/dtVisualizacion.h"
//#include "include/DtDictado.h"

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

  ControladorUsuario* Cu = new ControladorUsuario();
  ControladorAsignatura* Ca = new ControladorAsignatura();
  ControladorClase* Cc = new ControladorClase();

  //los controladores tienen punteros a las colecciones en atributos
  //de esta manera las colecciones se declaran en el main y son unicas para todo controlador que necesite usarlas
  Cu->setColUser(colUsuarios);
  Cu->setColEst(colEstudiantes);
  Cu->setColDoc(colDocentes);
  Cu->setColAsig(colAsignaturas);
  Cu->setHandler(h);
  Ca->setColDoc(colDocentes);
  Ca->setColAsig(colAsignaturas);
  Cc->setColEst(colEstudiantes);
  Cc->setColDoc(colDocentes);
  Cc->setColAsig(colAsignaturas);
  Cc->setColCla(colClases);
  Cc->setColMens(colMensajes);
  Cc->setHandler(h);
  h->setColMens(colMensajes);
  h->setColCla(colClases);

  //ALTA DE USUARIO
  Cu->agregarEstudiante("nombre","pass","email","url","1.234.567-8");
  Cu->confirmarAlta();

  Cu->agregarDocente("aaaaaa","123","email2","a","s");
  Cu->confirmarAlta();

  //ALTA DE ASIG
  Ca->agregarAsignatura("calculo",1,1,0,0);
  Ca->confirmarAlta();
  Ca->agregarAsignatura("calculo2",2,1,0,0);
  Ca->confirmarAlta();
  /*
  auto as = coleccionGlobalAsignaturas.find(1);

  cout << "Asignatura " << as->first <<
     " = " << as->second->getNombre() << endl;*/

  //ASIGNACION DE DOC A ASIG
/*
  set<dtAsignatura> as = Ca->consultarAsignaturas();

  for(auto ite = as.begin(); ite!=as.end() ; ite++){
      cout << "Nombre asignatura: " << ite->getNombre() << "\n";
  }; //consultarAsignaturas() funciona bien, nombra todas las asigs

  map<string,dtDocente> ds = Ca->consultarDocentesLibres(1);

  for(auto ite2 = ds.begin(); ite2!=ds.end() ; ite2++){
      cout << "Email docente libre de la asig calculo: "<< ite2->first << "\n";
  }; //consultarDocentesLibres() funca
*/
  //asigno el docente
  Ca->asignarDocente("email2",1,teorico);
  Ca->confirmarAsignacion();
  //me fijo si aparece en docentes libres
  map<string,dtDocente> ds = Ca->consultarDocentesLibres(1);

  for(auto ite2 = ds.begin(); ite2!=ds.end() ; ite2++){
      cout << "Email docente libre de la asig calculo: "<< ite2->first << "\n";
  };

  //INSCRIPCION A ASIGNATURA

  Cu->iniciarSesion("email","pass");
  /*set<dtAsignatura> set = Cu->consultarAsigNoIns();
  for(auto it = set.begin(); it!=set.end(); it++)
    cout << it->getNombre();
  cout << "\n";*/
  Cu->inscribir(1);
  Cu->confirmarInscripcion();/*
  set = Cu->consultarAsigNoIns();
  for(auto it = set.begin(); it!=set.end(); it++)
    cout << it->getNombre();*/

  //INICIO DE CLASE
  Cc->iniciarSesion("email2","123");

  set<dtAsignatura> setA = Cc->consultarAsignaturasDocente();
  /*for(auto it = setA.begin(); it!=setA.end(); it++){
    cout << "Asignatura es " << it->getNombre() << "\n";
  }*/

  tipoClase t = Cc->rolDocente(1);
  /*if(t==teorico)
    cout << "Rol es teorico\n";
  */
  dtFecha* fecha = new dtFecha();
  fecha->setAnio(2020);
  fecha->setMes(6);
  fecha->setDia(1);
  fecha->setHora(0);
  fecha->setMinuto(0);
  fecha->setSegundo(0);

  Cc->iniciarClase(1,"Clase 1",teorico,*fecha);

  Cc->confirmarInicio();

  /*auto clasesa = coleccionGlobalAsignaturas.find(1)->second->getClases();
  cout << "clase en asignatura: " << clasesa->begin()->second->getNombre() << "\n";

  auto clasesd = coleccionGlobalAsignaturas.find(1)->second->getClases();
  cout << "clase en docente: " <<clasesd->begin()->second->getNombre() << "\n";*/

  //FINALIZACION DE CLASE
/*
  set<dtClase> sinFin = Cc->consultarClasesEnVivo();

  for(auto iterador = sinFin.begin(); iterador!=sinFin.end(); iterador++){
    cout << "Codigo de clase sin terminar: " << iterador->getCodigo() << "\n";
  }

  Cc->finalizarClase(0);

  Cc->confirmarFin();

  sinFin = Cc->consultarClasesEnVivo();

  if(sinFin.begin()==sinFin.end()){
    cout << "No quedan clases sin terminar\n";
  }
*/
    //ASISTENCIA A CLASE EN VIVO

  Cc->iniciarSesion("email","pass");

  set<dtAsignatura> asigIns = Cc->consultarAsigIns();
  /*for(auto it = asigIns.begin(); it!=asigIns.end(); ++it){
    cout << it->getCodigo() <<"\n";
  }*/

  set<dtClase> clasesA = Cc->consultarClasesVivo(1);
  /*for(auto it = clasesA.begin(); it!=clasesA.end(); ++it){
    cout << it->getNombre() << "  "<< it->getCodigo() <<"\n";
  }*/

  dtClase clase1 = Cc->asistirClaseVivo(0);

  Cc->confirmarAsistenciaVivo();

  /*Estudiante* est = coleccionGlobalEstudiantes.find("email")->second;
  set<UsrCla*> lista = est->getClasesParticipa();
  for(auto it = lista.begin(); it!=lista.end(); ++it){
    cout << (*it)->getClase()->getNombre() <<"\n";
  }*/

  void cancelarAsistencia();

  //ENVIO DE MENSAJE

  set<dtClase> clasesP = Cc->consultarClasesParticipando();
  /*for(auto it = clasesP.begin(); it!=clasesP.end(); ++it){
    cout << "nombre: "<<it->getNombre() << "  codigo: "<< it->getCodigo() <<"\n";
  }*/
  set<dtMensaje> mens = Cc->consultarMensajes(0);
  //cout << "antes: "<< mens.size() <<"\n";

  Cc->enviarMensaje("este es un mensaje ");

  Cc->confirmarEnvio();

  auto itMens = coleccionGlobalMensajes.begin();
  cout << itMens->second->getContenido() << '\n';

  Cc->enviarRespuesta(0,"esta es una respuesta");

  Cc->confirmarEnvio();
  itMens++;
  cout << itMens->second->getContenido() << '\n';
  //Cc->cancelarEnvio();


  //FINALIZACION DE ASISTENCIA A CLASE EN VIVO

/*set<dtClase*> setDeClasesEnVivo = Cc->consultarClasesParticipandoVivo();
  for(auto it = setDeClasesEnVivo.begin(); it!=setDeClasesEnVivo.end(); ++it){
    cout << "nombre: "<<(*it)->getNombre() << "  codigo: "<< (*it)->getCodigo() <<"\n";
  }
  Cc->finalizarAsistencia(0);
  Cc->confirmarSalida();

  setDeClasesEnVivo = Cc->consultarClasesParticipandoVivo();
  for(auto it = setDeClasesEnVivo.begin(); it!=setDeClasesEnVivo.end(); ++it){
    cout << "nombre: "<<(*it)->getNombre() << "  codigo: "<< (*it)->getCodigo() <<"\n";
  }
*/
  //cancelarSalida();

  //TIEMPO DICTADO DE CLASES

  //set<DtDictado> dictado = Ca->tiempoDictado();

  //TIEMPO DE ASISTENCIA A CLASE

  //ELIMINACION DE ASIGNATURA

  //SUSCRIBIRSE A NOTIFICACIONES (solo el tercer modo, respuesta a un mensaje del usuario)
  Cu->cambiarModoSus(3);
  //Cu->cancelarCambio();
  Cu->confirmarCambio();

  //CONSULTA DE NOTIFICACIONES



  return 0;
}
