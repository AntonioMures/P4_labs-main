#include "../include/ControladorCalificacion.h"
#include "../include/Reserva.h"

//Constructor

Reserva :: Reserva(int c, DTFecha* in, DTFecha* out, Huesped* hue, Habitacion* hab){
     this->codigo = c;
     this->checkin = in;
     this->checkout = out;
	this->estado = Abierta; //Al crearse siempre se crea en estado Abierta 
     this->habitacion = hab;
     this->huesped = hue;
     
};

//Getters

int Reserva::getCodigo() {
     return this->codigo;
};

DTFecha* Reserva::getCheckin(){
     return this->checkin;
};

DTFecha* Reserva::getCheckOut(){
     return this->checkout;
};

EstadoReserva Reserva::getEstado(){
     return this->estado;
};

Huesped* Reserva::getHuesped(){
     return this->huesped;
};

Habitacion* Reserva::getHabitacion() {
     return this->habitacion;
};

// Setters

void Reserva::setCodigo(int cod) {
     this->codigo = cod;
};

void Reserva::setCheckin(DTFecha* in){
     this->checkin = in;
};

void Reserva::setCheckOut(DTFecha* out){
     this->checkout = out;
};

void Reserva::setEstado(EstadoReserva est){
     this->estado = est;
};

void Reserva::setHuesped(Huesped* hue){
     this->huesped = hue;
};

void Reserva::setHabitacion(Habitacion* hab) {
     this->habitacion = hab;
};

void Reserva::eliminarEstadias(){
     ControladorCalificacion* icc=ControladorCalificacion::getInstancia();
     //1:
     //1.*
     for (map<int, Estadia *>::iterator it=estadias.begin(); it!=estadias.end(); ++it){
          Estadia* est=it->second;
          //1.*.2
          icc->RemoverNotificaion(est->getCal(),habitacion->getHostal());
          //1.*.3
          icc->EliminarCalificacion(est->getCal(),est);
          //1.*.4 (DiagCom modificado) desvincular huesped
          est->desvincularHuesped(huesped);
          //1.*.5 (DiagCom modificado)
          estadias.erase(it->first);
          delete est;
     }
     //2 (DiagCom modificado) desvincular habitación
     habitacion->desvincularReserva(this);
};

void Reserva::cerrarReserva(){
     switch (estado){
     case Abierta:
          estado=Cerrada;
          break;
     case Cerrada:
          throw invalid_argument("La reserva ya está cerrada, no se puede cerrar");
          break;
     case Cancelada:
          throw invalid_argument("La reserva está cancelada, no se puede cerrar");
          break;
     default:
          break;
     }
};


DTReserva Reserva::getDatosReserva(){
     DTReserva r=DTReserva(codigo,checkin,checkout,estado,costo(),habitacion->getNumero());
     return r;
};

int Reserva::cantidadDeEstadias(){
     return estadias.size();
};


// Destructor

Reserva::~Reserva(){};