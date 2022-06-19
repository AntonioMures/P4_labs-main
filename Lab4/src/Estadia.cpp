#include "../include/ControladorReservas.h"
#include "../include/Estadia.h"
#include "../include/FechaSistema.h"
#include "../include/Reserva.h"

Estadia::Estadia(Reserva* res, Huesped* hues) {

    FechaSistema* ifs=FechaSistema::getInstancia();
    DTFecha fsis=ifs->getFechaSistema();
    checkInEstadia = new DTFecha(fsis.getDia(),fsis.getMes(),fsis.getAnio(),fsis.getHora());

    this->checkOutEstadia = NULL; //las nuevas estadías no checkOut
    this->promo = 0;//No existe un caso que redefina este parámetro, tal vez si existiera un Lab5 donde el cliente lo desee agregar lo implementaríamos...
    this->res = res;
    this->hues = hues;
    this->cal = NULL; //las nuevas estadías no tienen 
    
    ControladorReservas* CRes=ControladorReservas::getInstancia();
    codigo=CRes->getCodEstadiaNuevo();

};

Estadia::Estadia(Reserva* res, Huesped* hues,DTFecha* checkin) {
    checkInEstadia=checkin;
    this->checkOutEstadia = NULL; //las nuevas estadías no checkOut
    this->promo = 0;//No existe un caso que redefina este parámetro, tal vez si existiera un Lab5 donde el cliente lo desee agregar lo implementaríamos...
    this->res = res;
    this->hues = hues;
    this->cal = NULL; //las nuevas estadías no tienen 
    
    ControladorReservas* CRes=ControladorReservas::getInstancia();
    codigo=CRes->getCodEstadiaNuevo();

};

int Estadia::getCodigo(){
    return codigo;
};

int Estadia::alojamientoDias() {
    int diasIn = this->checkInEstadia->getAnio()*365 + this->checkInEstadia->getDia();
    for (int i = 1; i < this->checkInEstadia->getMes(); i++) {
        diasIn = diasIn + 30;
    }
    int diasOut = this->checkOutEstadia->getAnio()*365 + this->checkOutEstadia->getDia();
    for (int i = 1; i < this->checkOutEstadia->getMes(); i++) {
        diasOut = diasOut + 30;
    }
    return (diasOut - diasIn);
};

DTFecha* Estadia::getCheckInEstadia() {
    return this->checkInEstadia;
};

DTFecha* Estadia::getCheckOutEstadia() {
    return this->checkOutEstadia;
};

int Estadia::getPromo() {
    return this->promo;
};

Reserva* Estadia::getRes() {
    return this->res;
};

Huesped* Estadia::getHues() {
    return this->hues;
};

Calificacion* Estadia::getCal() {
    return this->cal;
};

float Estadia::costoEstadia() {
    int dias = this->alojamientoDias();
    float precioHab = this->getRes()->getHabitacion()->getPrecio();
    return (dias * precioHab);
};

DTCalificacion Estadia::getCalificacion() {
    if (this->cal != nullptr) {
        return this->cal->getDatosCalificacion();
    } else {
        DTCalificacion nuevo = DTCalificacion(0,0, nullptr, " ");
        return nuevo;
    }
};

void Estadia::setCalificacion(Calificacion* cal) {
    this->cal = cal;
};

void Estadia::setReserva(Reserva* res) {
    this->res = res;
};

void Estadia::setHuesped(Huesped* hues) {
    this->hues = hues;
};

DTEstadia Estadia::getDatosEstadia() {
    if (this->cal != nullptr) {
        DTEstadia est(this->checkInEstadia, this->checkOutEstadia, this->promo, this->hues->getNombre(), this->cal->getPuntuacion(), this->res->getHabitacion()->getNumero(), this->costoEstadia());
        return est;
    } else {
        DTEstadia est(this->checkInEstadia, this->checkOutEstadia, this->promo, this->hues->getNombre(), 0, this->res->getHabitacion()->getNumero(), this->costoEstadia());
        return est;
    }
};

void Estadia::desvincularHuesped(Huesped* h){
    //Desvincular el huesped de la estadia
    h->desvincularEstadia(this);
};

Estadia::~Estadia() {
    delete checkInEstadia;
    delete checkOutEstadia;
};