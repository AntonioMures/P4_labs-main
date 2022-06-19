#include "../include/DTReserva.h"

DTReserva::DTReserva(int cod, DTFecha* chIn, DTFecha* chOut, EstadoReserva est, float costo, int hab) {
     this->codigo = cod;
     this->checkIn = chIn;
     this->checkOut = chOut;
     this->estado = est;
     this->costo =  costo;
     this->habitacion = hab;
};

int DTReserva::getCodigo() {
     return this->codigo;
};

DTFecha* DTReserva::getCheckIn() {
     return this->checkIn;
};

DTFecha* DTReserva::getCheckOut() {
     return this->checkOut;
};

EstadoReserva DTReserva::getEstado() {
     return this->estado;
};

float DTReserva::getCosto() {
     return this->costo;
};

int DTReserva::getHabitacion() {
     return this->habitacion;
};

DTReserva::~DTReserva(){
     //Nada dinámico ok
};