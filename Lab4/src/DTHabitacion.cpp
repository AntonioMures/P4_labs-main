#include "../include/DTHabitacion.h"

DTHabitacion::DTHabitacion(int num, float p, int c) {
    this->numero = num;
    this->precio = p;
    this->capacidad = c;
};

int DTHabitacion::getNumero() {
    return this->numero;
};

int DTHabitacion::getCapacidad() {
    return this->capacidad;
};

float DTHabitacion::getPrecio() {
    return this->precio;
};

DTHabitacion::~DTHabitacion() {
    
};