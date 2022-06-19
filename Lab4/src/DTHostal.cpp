#include "../include/DTHostal.h"

DTHostal::DTHostal(string nombre, int telefono, string direccion) {
    this->nombre = nombre;
    this->telefono = telefono;
    this->direccion = direccion;
};

string DTHostal::getNombre() {
    return this->nombre;
};

int DTHostal::getTelefono() {
    return this->telefono;
};

string DTHostal::getDireccion() {
    return this->direccion;
};