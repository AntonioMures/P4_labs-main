#include <string>
#include "../include/DTEmpleado.h"

DTEmpleado::DTEmpleado(string nom,string mail,string pass, DTCargoEmpleado car,bool recibeNotif){
    nombre=nom;
    email=mail;
    password=pass;
    Cargo=car;
    recibeNotificaciones=recibeNotif;
};

string DTEmpleado::getNombre(){
    return nombre;
};

string DTEmpleado::getEmail(){
    return email;
};

string DTEmpleado::getPassword(){
    return password;
};

DTCargoEmpleado DTEmpleado::getCargo(){
    return Cargo;
};

bool DTEmpleado::getRecibeNotificaciones(){
    return recibeNotificaciones;
};

DTEmpleado::~DTEmpleado(){};