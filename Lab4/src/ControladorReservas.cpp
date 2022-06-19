#include "../include/FechaSistema.h"
#include "../include/ControladorReservas.h"
#include "../include/ControladorHostal.h"
#include "../include/ControladorUsuarios.h"
#include "../include/ReservaIndividual.h"
#include "../include/ReservaGrupal.h"
#include "../include/Utils.h"

// CONSTRUCTOR
ControladorReservas * ControladorReservas::instancia = NULL;

ControladorReservas::ControladorReservas(){
     maxCodEstadiaExistente=0;
     maxCodReservaExistente=0;
};

ControladorReservas * ControladorReservas::getInstancia(){
     if( instancia == NULL )
          instancia = new ControladorReservas();
     return instancia;
};

// FUNCIONES

bool ControladorReservas::existeEstadia(int identificador){
     if(!this->estadias.empty()){
          if(this->estadias.find(identificador) != this->estadias.end()){
               return true;    
          } else return false;   
     } else return false;
} 


DTEstadia ControladorReservas::estadiaActivaHuesped(string email) {
     ControladorUsuarios* conUsu = ControladorUsuarios::getInstancia();
     bool exists = conUsu->existeUsuario(email);
    if (exists){ //Me fijo que exista el usuario
        map<int, DTEstadia> DTEstadias = listarEstadiasHuesped(email, conUsu->buscarHostal(email)); //Devuelve la coleccion de estadias del huespued
        map<int, Estadia*>::iterator iter = estadias.begin();
        while(iter != estadias.end() && (iter->second->getCheckOutEstadia() != NULL)) //Mientras no llegue al final y la estadia tenga checkout sigue iterando
            ++iter;
        if (iter->second->getCheckOutEstadia() == NULL) 
            return iter->second->getDatosEstadia();  //Retorno el dtEstadia 
        else 
            throw invalid_argument("El huesped no tiene estadias activas.");  //Recorrio toda la coleccion y todas tenian checkout
    else 
        throw invalid_argument("No existe el usuario."); //El usuario no existe en el sistema 
    }
}


void ControladorReservas::finalizarEstadiaActiva(DTFecha fecha, DTEstadia estadia) {
     if (estadia->checkOutEstadia == NULL) 
        estadia->checkOutEstadia = fecha;
}


Estadia* ControladorReservas::getEstadia(int identificador){
     return this->estadias.find(identificador)->second;
}

void ControladorReservas::elegirEstadia(int identificador){
     if(existeEstadia(identificador)){
          this->IdEstadia = identificador;    
     }
}

int ControladorReservas::getIdEstadia(){
     return this->IdEstadia;
}

map<int, DTEstadia> ControladorReservas::listarEstadiasHuesped(string email, string nombre){
     map<int, DTEstadia> DTestadias;
     if(!this->estadias.empty()){
          map<int, Estadia*>::iterator iter = estadias.begin();
          while(iter != estadias.end()){
               if((iter->second->getHues()->getEmail() != email) && (iter->second->getRes()->getHabitacion()->getHostal()->getNombre() != nombre) && (iter->second->getCheckOutEstadia() == NULL)){
                    ++iter;
               } else {
                    DTestadias.insert(map<int, DTEstadia>::value_type(iter->first, iter->second->getDatosEstadia()));
               }
          }
     }
     return DTestadias;
}

//SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
//void ControladorReservas::setEstadiaTemp(int valor) {
//     this->estadiaTemp = valor;
//};
//
//int ControladorReservas::getEstadiaTemp() {
//     return this->estadiaTemp;
//};

map<int, DTEstadia> ControladorReservas::listarEstadiasHostal(string nombre) {
     map<int, DTEstadia> ret;
     if (!this->estadias.empty()) {
          for (map<int, Estadia*>::iterator t = estadias.begin(); t != estadias.end(); ++t) {
               Estadia* actual = t->second;
               if (actual->getRes()->getHabitacion()->getHostal()->getNombre() == nombre) {
                    ret.insert(map<int, DTEstadia>::value_type(t->first, actual->getDatosEstadia()));
               }
          }
     }
     return ret;
};

DTEstadia ControladorReservas::mostrarDatosEstadia(int seleccion) {
     map<int, Estadia*>::iterator t = estadias.find(seleccion);
     DTEstadia ret = t->second->getDatosEstadia();
     return ret;
};

DTCalificacion ControladorReservas::verCalificaion(int seleccion, string &resp) {
     map<int, Estadia*>::iterator t = estadias.find(seleccion);
     DTCalificacion ret = t->second->getCalificacion();
     resp = t->second->getCal()->getComentario();
     return ret;
}

DTReserva ControladorReservas::reservaAsociada(int seleccion) {
     map<int, Estadia*>::iterator t = estadias.find(seleccion);
     DTReserva ret = t->second->getRes()->getDatosReserva();
     return ret;
};

map<int,Reserva*> ControladorReservas::getReservas(){
     return reservas;
};

int ControladorReservas::getCodReservaNuevo(){
     return maxCodReservaExistente++;
};

int ControladorReservas::getCodEstadiaNuevo(){
     return maxCodEstadiaExistente++;
};

//SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
//void ControladorReservas::ingresarDatosReserva(DTFecha *checkin, DTFecha *checkout, bool esIndividual){
//     if (&checkin>&checkout)
//          throw invalid_argument("La fecha de CheckIn no puede ser mayor que la fecha de Check Out");
//     else {
//          memoriaReservas.checkin=checkin;
//          memoriaReservas.checkout=checkout;
//          memoriaReservas.individual=esIndividual;
//     }
//};

int ControladorReservas::CamasDispEnHab(string nombreHostal,int numHab,DTFecha in, DTFecha out){
     ControladorHostal *ich=ControladorHostal::getInstancia();
     Habitacion* hab=ich->obtenerHabitacion(nombreHostal,numHab);
     //almacena las reservas de esa habitación
     map<int,Reserva*> resHabit;
     for (map<int,Reserva*>::iterator it=reservas.begin(); it!=reservas.end(); ++it)
          if (it->first==numHab)
               resHabit.insert(make_pair(it->second->getCodigo(),it->second));

     //va guardando el peor caso de camas disponibles
     int camasDisponibles=hab->getCapacidad();

     //Recorrer días desde in hasta out
     for (DTFecha x=in;x>&out;in.sumarUnDia()){
          //listar reservas en esa fecha
          map<int,Reserva*> reservasX;
          for (map<int,Reserva*>::iterator it=resHabit.begin(); it!=resHabit.end(); ++it)
               if (it->second->getCheckin()<=&in && it->second->getCheckOut()>=&out)
                    reservasX.insert(make_pair(it->second->getCodigo(),it->second));
          
          //recorrer lista y restar a capacidad para ese día las camas no disponibles
          int capacidadEseDia=camasDisponibles;
          for (map<int,Reserva*>::iterator it=reservasX.begin(); it!=reservasX.end(); ++it)
               capacidadEseDia = capacidadEseDia - it->second->cantidadDeEstadias();
          
          //elige el peor caso
          camasDisponibles=menorEntero(camasDisponibles,capacidadEseDia);
     }
          
     return camasDisponibles;
};

//SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
//void ControladorReservas::elegirHostal(string nombreHostal){
//     ControladorHostal* ich=ControladorHostal::getInstancia();
//     map<string, DTHostal> hostales=ich->listarHostales();
//     if (hostales.find(nombreHostal)!=hostales.end())
//          memoriaReservas.nombreHostal=nombreHostal;
//     else
//          throw invalid_argument("El nombre del hostal no es correcto");
//};

//SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
//void ControladorReservas::elegirReserva(int c){
//     if (reservas.find(c)!=reservas.end())
//          memoriaReservas.codReserva=c;
//     else
//          throw invalid_argument("El código del hostal no es correcto");
//};

bool ControladorReservas::existeReserva(int c){
     return reservas.find(c)!=reservas.end();
};


//SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
//void ControladorReservas::elegirHuesped(string email){
//     ControladorUsuarios* icu=ControladorUsuarios::getInstancia();
//     map<string, DTHuesped> huespedes = icu->listarHuespedes();
//     if (huespedes.find(email)!=huespedes.end())
//          memoriaReservas.huespedDeLaReserva=email;
//     else
//          throw invalid_argument("El email del huésped no es correcto");
//};

void ControladorReservas::altaEstadia(int codReserva,string huespedQueReserva){
     //El último throw antes de saber que todo está en orden
     if (reservas.find(codReserva)==reservas.end())
          throw invalid_argument("El código de la reserva no es correcto");
     
     //Se sigue el diagrama de comunicación
     //1:
     FechaSistema* ifs=FechaSistema::getInstancia();
     //2:
     DTFecha fecha=ifs->getFechaSistema();
     //3:
     ControladorUsuarios* icu=ControladorUsuarios::getInstancia();
     Reserva* r=reservas.find(codReserva)->second;
     Huesped* h=icu->obtenerHuesped(huespedQueReserva);
     Estadia* e=new Estadia(r, h);
     //4:
     e->setReserva(r);
     e->setHuesped(h);
     estadias.insert(make_pair(e->getCodigo(),e));
     //5: cerrar reserva
     r->cerrarReserva();
};

//SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
//void ControladorReservas::elegirHabitacionReserva(int numHab){
//     ControladorHostal* ich=ControladorHostal::getInstancia();
//     if (ich->obtenerHabitacion(memoriaReservas.nombreHostal,numHab)!=NULL)
//          memoriaReservas.habitacionElegida=numHab;
//     else
//          throw invalid_argument("El número de habitación no es correcto");
//};

void ControladorReservas::confirmarReservaIndividual(string nombreHostal, int numHab,string huespedQueReserva, DTFecha* checkin, DTFecha* checkout){
     //Se sigue el diagrama de comunicación del caso de uso Realizar Reserva
     //1:
     ControladorHostal *ich=ControladorHostal::getInstancia();
     if (!ich->existeHostal(nombreHostal))
          throw invalid_argument("El hostal no existe");
     //2:
     if (!ich->existeHabitacion(numHab,nombreHostal))
          throw invalid_argument("El habitacion no es correcta");
     //3:
     ControladorUsuarios* icu=ControladorUsuarios::getInstancia();
     if (!icu->existeHuesped(huespedQueReserva))
          throw invalid_argument("El huésped no es correcto");
     //4:
     maxCodReservaExistente++;
     Huesped* hues=icu->obtenerHuesped(huespedQueReserva);
     Habitacion* hab=ich->obtenerHabitacion(nombreHostal,numHab);
     Reserva* r=new ReservaIndividual(getCodReservaNuevo(),checkin,checkout,hues,hab);
     //5:
     icu->vincularReserva(r,huespedQueReserva);
     //6::
     reinterpret_cast<ReservaIndividual*>(r)->vincularReservaIndividual(hab,huespedQueReserva);

     LiberarMemoria();
};

void ControladorReservas::confirmarReservaGrupal(string nombreHostal, int numHab,string huespedQueReserva, DTFecha* checkin, DTFecha* checkout,map<string,DTHuesped> conjuntoHuesp){
     //Se sigue el diagrama de comunicación del caso de uso Realizar Reserva
     //1:
     ControladorHostal *ich=ControladorHostal::getInstancia();
     if (!ich->existeHostal(nombreHostal))
          throw invalid_argument("El hostal no existe");
     //2:
     if (!ich->existeHabitacion(numHab,nombreHostal))
          throw invalid_argument("El habitacion no es correcta");
     //3:
     ControladorUsuarios* icu=ControladorUsuarios::getInstancia();
     if (!icu->existeHuesped(huespedQueReserva))
          throw invalid_argument("El huésped no es correcto");
     //4:
     maxCodReservaExistente++;
     Huesped* hues=icu->obtenerHuesped(huespedQueReserva);
     Habitacion* hab=ich->obtenerHabitacion(nombreHostal,numHab);
     //5:
     map<string,Huesped*> conjPunterosAHsp;
     for (map<string,DTHuesped>::iterator it=conjuntoHuesp.begin();it!=conjuntoHuesp.end();++it)
          conjPunterosAHsp.insert( make_pair(it->first,icu->obtenerHuesped(it->first)) );
     
     Reserva* r=new ReservaGrupal(getCodReservaNuevo(),checkin,checkout,hues,hab,conjPunterosAHsp);
     //6::
     reinterpret_cast<ReservaGrupal*>(r)->vincularReservaGrupal(hab,huespedQueReserva,conjPunterosAHsp);
     
     LiberarMemoria();
};

void ControladorReservas::LiberarMemoria(){
     //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
     //memoriaReservas.checkin = memoriaReservas.checkout = NULL; //No se borra la instancia
     //memoriaReservas.huespedQueReserva="";
     //memoriaReservas.nombreHostal="";
     //memoriaReservas.numHabitacion=0;
     //memoriaReservas.habitacionElegida=0;
     //memoriaReservas.codReserva=0;
     //memoriaReservas.huespedDeLaReserva="";
};


map<int,DTReserva> ControladorReservas::listarReservasHostal(){
     map<int,DTReserva> salida;
     for (map<int,Reserva*>::iterator it=reservas.begin(); it!=reservas.end(); ++it)
          salida.insert(make_pair(it->first,it->second->getDatosReserva()));
     return salida;
};

map<int,DTReserva> ControladorReservas::listarReservasHostalSeleccionado(string nombre){
     map<int,DTReserva> dr;
     for(map<int, Reserva*>::iterator iter = reservas.begin(); iter != reservas.end(); ++iter){
          if(iter->second->getHabitacion()->getHostal()->getNombre() == nombre)
               dr.insert(map<int, DTReserva>::value_type(iter->first, iter->second->getDatosReserva()));
     }
     return dr;
};

map<int,DTReserva> ControladorReservas::listarReservasNoCanceladasDelHuesped(string h){
     map<int,DTReserva> resultado;
     ControladorUsuarios* CUsu=ControladorUsuarios::getInstancia();
     map<int, Reserva *> todas=CUsu->obtenerHuesped(h)->getReservas();
     for (map<int, Reserva *>::iterator it=todas.begin();it!=todas.end();++it)
          if (it->second->getEstado()!=Cancelada)
               resultado.insert(make_pair(it->first,it->second->getDatosReserva()));
     return resultado;
};

void ControladorReservas::eliminarReserva(int codReserva){
     if (existeReserva(codReserva)){
          Reserva* r=reservas.find(codReserva)->second;
          r->eliminarEstadias();
          delete r;
     } else
          throw ("La reserva no existe");
};

void ControladorReservas::cancelarCreacionReserva(){
};


Estadia* ControladorReservas::DPRegistrarEstadia(Reserva* r,string emailHuesped,DTFecha *checkin){
//Se parece mucho alta estadia     
     //3:
     ControladorUsuarios* icu=ControladorUsuarios::getInstancia();
     Huesped* h=icu->obtenerHuesped(emailHuesped);
     Estadia* e=new Estadia(r, h,checkin);
     //4:
     e->setReserva(r);
     e->setHuesped(h);
     estadias.insert(make_pair(e->getCodigo(),e));
     //5: cerrar reserva
     r->cerrarReserva();
     return e;
};


// DESTRUCTOR
ControladorReservas::~ControladorReservas(){}