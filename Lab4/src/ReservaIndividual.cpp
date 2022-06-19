#include "../include/DTReservaIndividual.h"
#include "../include/ReservaIndividual.h"
#include "../include/ControladorUsuarios.h"

ReservaIndividual::ReservaIndividual(int c, DTFecha* in, DTFecha* out, Huesped* hue, Habitacion* hab):Reserva(c, in, out, hue, hab){
    //this->pagado = pagado; //lab0
}; 

//lab0
//bool ReservaIndividual::getPagado() {
//    return this->pagado;
//}

//calcula cantidad de días del alojamiento
int ReservaIndividual::alojamientoDias() {
    int diasIn = this->checkin->getAnio()*365 + this->checkin->getDia();
    for (int i = 1; i < this->checkin->getMes(); i++) {
        diasIn = diasIn + 30;
    }
    int diasOut = this->checkout->getAnio()*365 + this->checkout->getDia();
    for (int i = 1; i < this->checkout->getMes(); i++) {
        diasOut = diasOut + 30;
    }
    return (diasOut - diasIn);
};

float ReservaIndividual::costo() {
    int dias = this->alojamientoDias();
    float precioHabitacion = this->habitacion->getPrecio();
    return (dias*precioHabitacion);
};

//DTReserva ReservaIndividual::getDatosReserva(){
//    DTReserva dr = DTReservaIndividual(this->codigo, this->checkin, this->checkout, this->estado, this->costo(), this->habitacion->getNumero());
//    return dr;
//};

void ReservaIndividual::vincularReservaIndividual(Habitacion* habitac,string emailHuesped){
    ControladorUsuarios* icu=ControladorUsuarios::getInstancia();
    Huesped* u=icu->obtenerHuesped(emailHuesped);
    if (u==NULL)
        throw invalid_argument("El email no corresponde a un huésped");
    else {
        setHuesped(u);
        setHabitacion(habitac);
    }
};

int ReservaIndividual::cantidadDeEstadias(){
    //Contempla sólamente la del huésped que reserva
    return 1;
};

ReservaIndividual::~ReservaIndividual() {
};