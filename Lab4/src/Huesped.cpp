#include <string>
#include <set>
#include "../include/DTHuesped.h"
#include "../include/Huesped.h"
#include "../include/Reserva.h"
#include "../include/Estadia.h"


Huesped::Huesped(string nom, string email, string pass, bool esFinger):Usuario(nom,email,pass) {
    this->esFinger = esFinger;
};

bool Huesped::getFinger(){
	return this->esFinger;
};

void Huesped::setFinger(bool es){
    this->esFinger = es;
};

//Crea un DTHuesped
DTHuesped Huesped::getDatosHuesped(){
    DTHuesped dt = DTHuesped(getNombre(),getEmail(),getPassword(),this->esFinger);
    return dt;
};

void Huesped::vincularReserva(Reserva* r){
    Reservas.insert(make_pair( r->getCodigo() ,r));
};

map<int,Reserva*> Huesped::getReservas(){
    return Reservas;
};

void Huesped::desvincularEstadia(Estadia * e){
    Estadias.erase(  Estadias.find(e->getCodigo()) );
};

Huesped::~Huesped(){

};