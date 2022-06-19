#include "../include/Habitacion.h"
//using namespace std;

Habitacion::Habitacion(int num, float precio, int cap, Hostal* host){
    this->numero = num;
    this->precio = precio;
    this->capacidad = cap;
    this->hostal = host;
};

void Habitacion::setNumero(int num){
    this->numero = num;
};

void Habitacion::setPrecio(float precio){
    this->precio = precio;
};

void Habitacion::setCapacidad(int cap){
    this->capacidad = cap;
};

void Habitacion::setHostal(Hostal* host){
    this->hostal = host;
}

int Habitacion::getNumero(){
    return this->numero;
};

float Habitacion::getPrecio(){
    return this->precio;
};
int Habitacion::getCapacidad(){
    return this->capacidad;
};

Hostal* Habitacion::getHostal(){
    return this->hostal;
};

map<string,Reserva*> Habitacion::getReservas(){
    return reservas;
}

DTHabitacion Habitacion::getDatosHabitacion(){
	DTHabitacion habitacion(this->numero,this->precio,this->capacidad);
	return habitacion;
}

void Habitacion::desvincularReserva(Reserva*){

};

Habitacion::~Habitacion(){};