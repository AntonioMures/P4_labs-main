#include "../include/Fabrica.h"

Fabrica::Fabrica(){};

Fabrica::~Fabrica(){};

IControladorHostal* Fabrica::getInstanciaConHos(){
     return ControladorHostal::getInstancia();
};

IControladorUsuarios* Fabrica::getInstanciaConUsu(){
     return ControladorUsuarios::getInstancia();
};

IControladorCalificacion* Fabrica::getInstanciaConCal(){
     return ControladorCalificacion::getInstancia();
};

IControladorReservas* Fabrica::getInstanciaConRes(){
     return ControladorReservas::getInstancia();
};

IFechaSistema* Fabrica::getInstanciaFechaSis(){
     return FechaSistema::getInstancia();
};