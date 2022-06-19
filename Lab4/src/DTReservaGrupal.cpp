#include "../include/DTReservaGrupal.h"

DTReservaGrupal::DTReservaGrupal(int cod, DTFecha* chIn, DTFecha* chOut, EstadoReserva est, float costo, int hab):DTReserva(cod, chIn, chOut, est, costo, hab) {};

int DTReservaGrupal::getCodigo() {
     return this->codigo;
};

DTFecha* DTReservaGrupal::getCheckIn() {
     return this->checkIn;
};

DTFecha* DTReservaGrupal::getCheckOut() {
     return this->checkOut;
};

EstadoReserva DTReservaGrupal::getEstado() {
     return this->estado;
};

float DTReservaGrupal::getCosto() {
     return this->costo;
};

int DTReservaGrupal::getHabitacion() {
     return this->habitacion;
};

DTReservaGrupal::~DTReservaGrupal(){
     //Nada dinámico ok
};