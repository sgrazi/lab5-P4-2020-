#include <iostream>
#include <map>

#include "include/asignatura.h"
//#include "include/headers/clase.h"
#include "include/controladorAsignatura.h"
//#include "include/headers/controladorClase.h"
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
//#include "include/headers/iControladorClase.h"
#include "include/iControladorUsuario.h"
//#include "include/headers/mensaje.h"
//#include "include/headers/monitoreo.h"
//#include "include/headers/practico.h"
#include "include/rol.h"
//#include "include/headers/teorico.h"
#include "include/usuario.h"
//#include "include/headers/visualizacion.h"
#include "include/dtAsignatura.h"
//#include "include/dts/dtClase.h"
#include "include/dtDocente.h"
#include "include/dtEstudiante.h"
//*#include "include/dts/dtFecha.h"
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

int main(){

  map<string,Estudiante*>* colEstudiantes = &coleccionGlobalEstudiantes;
  map<string,Docente*>* colDocentes = &coleccionGlobalDocentes;
  map<int,Asignatura*>* colAsinaturas = &coleccionGlobalAsignaturas;

  ControladorUsuario* Cu = new ControladorUsuario();
  ControladorAsignatura* Ca = new ControladorAsignatura();

  //los controladores tienen punteros a las colecciones en atributos
  //de esta manera las colecciones se declaran en el main y son unicas para todo controlador que necesite usarlas
  Cu->setColEst(colEstudiantes);
  Cu->setColDoc(colDocentes);
  Ca->setColDoc(colDocentes);
  Ca->setColAsig(colAsinaturas);

  /* //ALTA DE USUARIO
  Cu->agregarEstudiante("c","a","email","a","s");
  Cu->confirmarAlta();

  Cu->agregarDocente("ale","a","email2","a","s");
  Cu->confirmarAlta();

  auto it = coleccionGlobalEstudiantes.find("email");

  cout << "est de " << it->first <<
     " = " << it->second->getNombre() << endl;

  auto it2 = coleccionGlobalDocentes.find("email2");

  cout << "doc de " << it2->first << " = " << it2->second->getNombre() << endl;
  */

  /*//ALTA DE ASIG

  Ca->agregarAsignatura("calculo",1,1,0,0);

  Ca->confirmarAlta();

  auto it = coleccionGlobalAsignaturas.find(1);

  cout << "Asignatura " << it->first <<
     " = " << it->second->getNombre() << endl;*/

  //ASIGNACION DE DOC A ASIG



  return 0;
}
