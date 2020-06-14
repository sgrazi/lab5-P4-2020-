#include <iostream>
#include <map>

#include "include/asignatura.h"
#include "include/clase.h"
#include "include/controladorAsignatura.h"
#include "include/controladorClase.h"
#include "include/controladorUsuario.h"
#include "include/docente.h"
//#include "include/headers/estcla.h"
//#include "include/headers/estrategiaModoSus1.h"
//#include "include/headers/estrategiaModoSus2.h"
//#include "include/headers/estrategiaModoSus3.h"
//#include "include/headers/estrategiaNotifs.h"
#include "include/estudiante.h"
//#include "include/headers/factory.h"
//#include "include/headers/handlerMensajes.h"
#include "include/iControladorAsignatura.h"
#include "include/iControladorClase.h"
#include "include/iControladorUsuario.h"
//#include "include/headers/mensaje.h"
#include "include/monitoreo.h"
#include "include/practico.h"
#include "include/rol.h"
#include "include/teorico.h"
#include "include/usuario.h"
//#include "include/headers/visualizacion.h"
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

using namespace std;

map<string,Estudiante*> coleccionGlobalEstudiantes;
map<string,Docente*> coleccionGlobalDocentes;
map<int,Asignatura*> coleccionGlobalAsignaturas;
map<int,Clase*> coleccionGlobalClases;

int main(){

  map<string,Estudiante*>* colEstudiantes = &coleccionGlobalEstudiantes;
  map<string,Docente*>* colDocentes = &coleccionGlobalDocentes;
  map<int,Asignatura*>* colAsignaturas = &coleccionGlobalAsignaturas;
  map<int,Clase*>* colClases = &coleccionGlobalClases;

  ControladorUsuario* Cu = new ControladorUsuario();
  ControladorAsignatura* Ca = new ControladorAsignatura();
  ControladorClase* Cc = new ControladorClase();

  //los controladores tienen punteros a las colecciones en atributos
  //de esta manera las colecciones se declaran en el main y son unicas para todo controlador que necesite usarlas
  Cu->setColEst(colEstudiantes);
  Cu->setColDoc(colDocentes);
  Cu->setColAsig(colAsignaturas);
  Ca->setColDoc(colDocentes);
  Ca->setColAsig(colAsignaturas);
  Cc->setColEst(colEstudiantes);
  Cc->setColDoc(colDocentes);
  Cc->setColAsig(colAsignaturas);
  Cc->setColCla(colClases);

  //ALTA DE USUARIO
  Cu->agregarEstudiante("nombre","pass","email","url","1.234.567-8");
  Cu->confirmarAlta();

  Cu->agregarDocente("aaaaaa","123","email2","a","s");
  Cu->confirmarAlta();
  /*
  auto it = coleccionGlobalEstudiantes.find("email");

  cout << "est de " << it->first <<
     " = " << it->second->getNombre() << endl;

  auto it2 = coleccionGlobalDocentes.find("email2");

  cout << "doc de " << it2->first << " = " << it2->second->getNombre() << endl;*/

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
  Ca->asignarDocente("email2",1,teorico);

  Ca->confirmarAsignacion();
  //asigno el docente y ahora me fijo si aparece en docentes libres
  //ds = Ca->consultarDocentesLibres(1);
/*
  for(auto ite2 = ds.begin(); ite2!=ds.end() ; ite2++){
      cout << "Email docente libre de la asig calculo: "<< ite2->first << "\n";
  };
  */
  //INSCRIPCION A ASIGNATURA
  /*
  Cu->iniciarSesion("email","pass");
  set<dtAsignatura> set = Cu->consultarAsigNoIns();
  for(auto it = set.begin(); it!=set.end(); it++)
    cout << it->getNombre();
  cout << "\n";
  Cu->inscribir(1);
  Cu->confirmarInscripcion();
  set = Cu->consultarAsigNoIns();
  for(auto it = set.begin(); it!=set.end(); it++)
    cout << it->getNombre();*/

  //INICIO DE CLASE


  return 0;
}
