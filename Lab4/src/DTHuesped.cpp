#include <string>
#include "../include/DTHuesped.h"

using namespace std;

DTHuesped::DTHuesped(string nombre, string email, string password, bool esfinger){
    this->nombre = nombre;
    this->email = email;
    this->password = password;
    this->esFinger = esfinger;
};

string DTHuesped::getNombre() {
    return this->nombre;
};

string DTHuesped::getEmail() {
    return this->email;
};

string DTHuesped::getPassword() {
    return this->password;
};

bool DTHuesped::getFinger() {
    return this->esFinger;
};

DTHuesped::~DTHuesped(){
    //Nada dinámico ok
};