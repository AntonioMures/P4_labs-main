#include "../include/Hostal.h"
#include "../include/Empleado.h"

#include <map>


Hostal::Hostal(string nombre, int telefono, string direccion, map<int, Habitacion*> mapHabitacion, map<Estadia*, Calificacion*> mapCalificacion, map<string, Empleado*> mapEmpleado) {
    this->nombre = nombre;
    this->telefono = telefono;
    this->direccion = direccion;
    this->mapHabitacion = mapHabitacion;
    this->mapCalificacion = mapCalificacion;
    this->mapEmpleado = mapEmpleado;
};

string Hostal::getNombre() {
    return this->nombre;
};

int Hostal::getTelefono() {
    return this->telefono;
};

string Hostal::getDireccion() {
    return this->direccion;
};

map<int, Habitacion*> Hostal::getHabitaciones() {
    return this->mapHabitacion;
};

map<Estadia*, Calificacion*> Hostal::getCalificaciones() {
    return this->mapCalificacion;
};

map<string, Empleado*> Hostal::getEmpleados() {
    return this->mapEmpleado;
};

float Hostal::calificacionPromedio() {
    int acumulador = 0;
    int contador = 0;
    for (map<Estadia*, Calificacion*>::iterator t = this->mapCalificacion.begin(); t != this->mapCalificacion.end(); ++t) {
        Calificacion* actual = t->second;
        acumulador = acumulador + actual->getPuntuacion();
        contador++;
    }
    if (contador != 0) {
        return (acumulador/contador);
    } else {
        return 0.0;
    }
};

void Hostal::agregarHabitacion(Habitacion* hab) {
    int numero = hab->getNumero();
    this->mapHabitacion[numero] = hab;
};

void Hostal::eliminarHabitacion(Habitacion* hab) {
    int numero = hab->getNumero();
    this->mapHabitacion.erase(numero);
};

bool Hostal::checkEmpleado(string email) {
    bool res = false;
    for (map<string, Empleado*>::iterator t = this->mapEmpleado.begin(); t != this->mapEmpleado.end(); ++t) {
        Empleado* actual = t->second;
        if (actual->getEmail() == email) {
            res = true;
        }
    }
    return res;
};

map<int, DTHabitacion> Hostal::mostrarHabitaciones() {
    map<int, DTHabitacion> ret;
    for (map<int, Habitacion*>::iterator t = this->mapHabitacion.begin(); t != this->mapHabitacion.end(); ++t) {
        Habitacion* actual = t->second;
        DTHabitacion i = actual->getDatosHabitacion();
        int numero = actual->getNumero();
        ret.insert(map<int, DTHabitacion>::value_type(numero, i));
    }
    return ret;
};

DTHostal Hostal::getDatosHostal() {
    DTHostal hostal = DTHostal(this->getNombre(), this->getTelefono(), this->getDireccion());
    return hostal;
};

DTCalificacion Hostal::getCalificacion(Calificacion* cal) {
    return cal->getDatosCalificacion();
};

void Hostal::removerCalifiacion(Calificacion* c,Estadia* e){
    mapCalificacion.erase(e);
};

void Hostal::agregarEmpleado(string email, Empleado* emp) {
    this->mapEmpleado.insert(map<string, Empleado*>::value_type(email, emp));
};

Hostal::~Hostal() {

};





