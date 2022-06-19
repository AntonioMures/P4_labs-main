#include "../include/ControladorHostal.h"
#include "../include/ControladorReservas.h"
#include "../include/Utils.h"

// CONSTRUCTOR
ControladorHostal* ControladorHostal::instancia = NULL;

ControladorHostal::ControladorHostal(){};

ControladorHostal* ControladorHostal::getInstancia(){
     if( instancia == NULL )
          instancia = new ControladorHostal();
     return instancia;
};

// DESTRUCTOR
ControladorHostal::~ControladorHostal(){};

// Funciones
string ControladorHostal::getHostalDeEmpleado(string email){
     string nomHos;
     map<string, Empleado*> emps;
     for(std::map<string, Hostal*>::iterator it = this->hostales.begin(); it != this->hostales.end(); ++it){
          emps = it->second->getEmpleados();
          for(std::map<string, Empleado*>::iterator iter = emps.begin(); iter != emps.end(); ++iter){
               if( iter->second->getEmail() == email )
                    nomHos = it->first;
          }
     }
     return nomHos;
};

map<int, Calificacion*> ControladorHostal::calificacionesHostal(string nombre){
     map<int, Calificacion*> dc;
     Hostal* hos = hostales.find(nombre)->second;
     if (hos==NULL)
          throw invalid_argument("El hostal no es correcto");
     map<Estadia*, Calificacion*> come = hos->getCalificaciones();
     int i = 1;
     for(map<Estadia*, Calificacion*>::iterator iter = come.begin(); iter != come.end(); ++iter){
          dc.insert(map<int, Calificacion*>::value_type(i, iter->second));
          i++;
     }
     return dc;
};

map<int, DTCalificacion> ControladorHostal::datosCalificacionesHostal(string nombre){
     map<int, DTCalificacion> resultado;
     for (map<int, Calificacion *>::iterator it=calificacionesHostal(nombre).begin(); it!=calificacionesHostal(nombre).end(); ++it)
          resultado.insert(make_pair(it->first,it->second->getDatosCalificacion()));
     return resultado;
};

bool ControladorHostal::existeHostal(string nombre){
     if(this->hostales.empty() || this->hostales.find(nombre)==this->hostales.end())
          return false;   
     else return true;
} 

//SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
//string ControladorHostal::getNombreHostElegido(){
//     return memoriaCHostales.nombreHostal;
//}

void ControladorHostal::ConfirmarHostal(string nombre, int telefono, string direccion){
     if(!existeHostal(nombre)){
          map<int, Habitacion*> habitaciones;
          map<Estadia*, Calificacion*> calificaciones;
          map<string, Empleado*> empleados;
          Hostal* host = new Hostal(nombre, telefono, direccion, habitaciones, calificaciones, empleados);
          this->hostales.insert(map<string, Hostal*>::value_type(nombre, host));
     } else throw std::invalid_argument("El hostal ya esta registrado");
};

bool ControladorHostal::existeHabitacion(int hab,string nomHostal){
     return obtenerHabitacion(nomHostal,hab)!=NULL;
};

map<string, DTHostal> ControladorHostal::listarHostales(){
     map<string, DTHostal> dh;
     if( !this->hostales.empty() ){
          for (std::map<string, Hostal*>::iterator it = this->hostales.begin(); it != this->hostales.end(); ++it){
               dh.insert(map<string, DTHostal>::value_type(it->first, it->second->getDatosHostal()));
          }
     }
     return dh;
};

Hostal* ControladorHostal::getPunteroHostal(string nombreHostal){
     return hostales.find(nombreHostal)->second;
};

void ControladorHostal::confirmarHabitacion(string nombreHos, int numero, float precio, int capacidad){
     Hostal* hos;
     bool encontrado = false;
     if( !this->hostales.empty() ){
          for (std::map<string, Hostal*>::iterator it = this->hostales.begin(); it != this->hostales.end(); ++it){
               if(it->first == nombreHos){
                    hos = it->second;
                    encontrado = true;
               }
          }
     }
     if( encontrado )
          Habitacion hab = Habitacion(numero, precio, capacidad, hos);
     else
          throw std::invalid_argument("El hostal ingresado no es correcto");
}


map<int,int> ControladorHostal::listarHabitacionesDisponibles(string nomHostal,DTFecha FIn, DTFecha FOut){
     ControladorReservas* icr=ControladorReservas::getInstancia();

     //Encontrar el Hostal
     map<string,Hostal*>::iterator it=hostales.begin();
     while (it!=hostales.end() && it->first!=nomHostal)
          ++it;
     
     //map<NumeroHab,CapacidadDisponible>
     map<int,int> resultado;

     //Recorrer Habitaciones
     for (map<int, Habitacion *>::iterator itha=it->second->getHabitaciones().begin(); itha!=it->second->getHabitaciones().end(); ++itha){
          Habitacion* h=itha->second;
          int numHab=h->getNumero();
          resultado.insert(map<int,int>::value_type(numHab, icr->CamasDispEnHab(nomHostal,numHab,FIn,FOut)));
     }
     
     return resultado;
};

//SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
//void ControladorHostal::elegirHostal(string nombre){
//     map<string,Hostal*>::iterator it;
//     for (it=hostales.begin(); it!=hostales.end() && it->first!=nombre; ++it){ };
//     if (it!=hostales.end())
//          memoriaCHostales.nombreHostal=nombre;
//     else
//          throw invalid_argument("El nombre del hostal no es correcto");
//};


Habitacion* ControladorHostal::obtenerHabitacion(string nomHostal,int numHab){
     map<string, Hostal*>::iterator hst=hostales.find(nomHostal);
     if (hst!=hostales.end())
          return hst->second->getHabitaciones().find(numHab)->second;
     else
          return NULL;
};

DTHabitacion ControladorHostal::mostrarDatosHabitacion(string nomHostal,int numHab){
     return obtenerHabitacion(nomHostal,numHab)->getDatosHabitacion();
};

map<string,float> ControladorHostal::mostrarTop3Hostales() {
     map<string,float> ret;
     if (hostales.size()==0)
          throw invalid_argument("Aún no hay registrados en el sistema");
     else if (hostales.size()<=3){//retorna todos
          for (map<string, Hostal*>::iterator t = hostales.begin(); t != hostales.end(); ++t) {
               Hostal* actual = t->second;
               ret.insert(map<string,float>::value_type(actual->getNombre(),actual->calificacionPromedio()));
          } 
     } else { //retornar sólo 3
          //crear conjunto de pares hostal, calif
          map<Hostal*,float> todos; //Los map funcionan con primeros parámetro todos distintos
          for (map<string, Hostal*>::iterator t = hostales.begin(); t != hostales.end(); ++t)
               todos.insert(make_pair(t->second,t->second->calificacionPromedio()));
          
          int punt1, punt2, punt3;
          Hostal *host1, *host2, *host3;
          //Elegir el 1:
          host1=todos.begin()->first;
          punt1=host1->calificacionPromedio();
          for (map<Hostal*,float>::iterator t = todos.begin(); t != todos.end(); ++t)
               if (t->first!=host1 && mayor(t->second,punt1)){
                    host1=t->first;
                    punt1=t->second;
               }

          //Elegir el 2:
          todos.erase(host1);
          host2=todos.begin()->first;
          punt2=host2->calificacionPromedio();
          for (map<Hostal*,float>::iterator t = todos.begin(); t != todos.end(); ++t)
               if (t->first!=host2 && mayor(t->second,punt2)){
                    host2=t->first;
                    punt2=t->second;
               }

          //Elegir el 3;
          todos.erase(host2);
          host3=todos.begin()->first;
          punt3=host3->calificacionPromedio();
          for (map<Hostal*,float>::iterator t = todos.begin(); t != todos.end(); ++t)
               if (t->first!=host3 && mayor(t->second,punt3)){
                    host3=t->first;
                    punt3=t->second;
               }
          
          //Armar map para return
          ret.insert(make_pair(host1->getNombre(),punt1));
          ret.insert(make_pair(host2->getNombre(),punt2));
          ret.insert(make_pair(host3->getNombre(),punt3));

     }
     //Se modifica la lógica
     //for (map<string, Hostal*>::iterator t = hostales.begin(); t != hostales.end(); ++t) {
     //     
     //     Hostal* actual = t->second;
     //     ret.insert(map<float, DTHostal>::value_type(actual->calificacionPromedio(), actual->getDatosHostal()));
     //} 
     return ret; 
};

void ControladorHostal::asignarEmpleado(string email, string hostal) {
     map<std::string, Hostal*>::iterator t = this->hostales.find(hostal);
     ControladorUsuarios* contU = ControladorUsuarios::getInstancia();
     Empleado* emp = contU->obtenerEmpleado(email);
     t->second->agregarEmpleado(email, emp);
};

DTHostal ControladorHostal::datosHostal(string h){
     if (hostales.find(h)==hostales.end())
          throw invalid_argument("El hostal no es correcto");
     else
     return hostales.find(h)->second->getDatosHostal();
};