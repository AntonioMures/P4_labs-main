#include "../include/DTReservaIndividual.h"

DTReservaIndividual::DTReservaIndividual(int cod, DTFecha* chIn, DTFecha* chOut, EstadoReserva est, float costo, int hab):DTReserva(cod, chIn, chOut, est, costo, hab) {};

int DTReservaIndividual::getCodigo() {
     return this->codigo;
};

DTFecha* DTReservaIndividual::getCheckIn() {
     return this->checkIn;
};

DTFecha* DTReservaIndividual::getCheckOut() {
     return this->checkOut;
};

EstadoReserva DTReservaIndividual::getEstado() {
     return this->estado;
};

float DTReservaIndividual::getCosto() {
     return this->costo;
};

int DTReservaIndividual::getHabitacion() {
     return this->habitacion;
};

DTReservaIndividual::~DTReservaIndividual(){
     //Nada dinámico ok
};