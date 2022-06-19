#include <string>
#include "../include/Usuario.h"


Usuario::Usuario(string nom, string email, string pass){
    this->nombre=nom;
    this->email=email;
    this->password=pass;
};

string Usuario::getNombre(){
	return nombre;
};

string Usuario::getEmail(){
	return email;
};

string Usuario::getPassword(){
	return password;
};

void Usuario::setNombre(string n){
    nombre=n;
};

void Usuario::setEmail(string e){
    email=e;
};

void Usuario::setPassword(string p){
    password=p;
};

Usuario::~Usuario(){
    
};