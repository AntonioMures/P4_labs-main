#include "../include/ControladorUsuarios.h"
#include "../include/DTReservaGrupal.h"
#include "../include/ReservaGrupal.h"
#include "../include/DTHuesped.h"

ReservaGrupal::ReservaGrupal(int c, DTFecha* in, DTFecha* out, Huesped* hue, Habitacion* hab, map<string,Huesped*> conjuntoHuespedes):Reserva(c, in, out, hue, hab){
     huespedes=conjuntoHuespedes;
}; 

int ReservaGrupal::getCantidadDeHuespedes(){
     int i = this->huespedes.size();
     return i;
}

int ReservaGrupal::alojamientoDias(){
     int diasIn = this->checkin->getAnio()*365 + this->checkin->getDia();
     for (int i = 1; i < this->checkin->getMes(); i++) {
          diasIn = diasIn + 30;
     }
     int diasOut = this->checkout->getAnio()*365 + this->checkout->getDia();
     for (int i = 1; i < this->checkout->getMes(); i++) {
          diasOut = diasOut + 30;
     }
     return (diasOut - diasIn);
}

float ReservaGrupal::costo() {
     return (this->alojamientoDias() * this->habitacion->getPrecio() * this->getCantidadDeHuespedes());
};

//DTReserva ReservaGrupal::getDatosReserva(){
//     DTReserva dr = DTReservaGrupal(this->codigo, this->checkin, this->checkout, this->estado, this->costo(), this->habitacion->getNumero());
//     return dr;
//};

void ReservaGrupal::vincularReservaGrupal(Habitacion* habitac,string huespedQueReserva,map<string,Huesped*> conjuntoHuesp){
     ControladorUsuarios* icu=ControladorUsuarios::getInstancia();
     Huesped* u=icu->obtenerHuesped(huespedQueReserva);
     if (u==NULL)
          throw std::invalid_argument("El email del huésped que reserva no corresponde a un huésped");
     else {
          setHuesped(u);
          setHabitacion(habitac);
          huespedes=conjuntoHuesp;
     }
};

int ReservaGrupal::cantidadDeEstadias(){
     return huespedes.size();
};

ReservaGrupal::~ReservaGrupal() {
};