#include "../include/Huesped.h"
#include "../include/Habitacion.h"
#include "../include/DTReserva.h"
#include "../include/Reserva.h"
#include "../include/ReservaIndividual.h"
#include "../include/ReservaGrupal.h"

#include <iostream>

int main(){
     Usuario us = Huesped("Guille", "gui@mail.com", "123", true);

     Habitacion hab = Habitacion(1, 12, 4);

     DTFecha in = DTFecha(1,2,21,16);
     DTFecha out = DTFecha(4,2,21,16);

     ReservaIndividual r = ReservaIndividual(1, &in, &out, Abierta, &us, &hab, false);


     return 0;
}