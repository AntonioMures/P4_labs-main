#include "DTFecha.h"
#include "EstadoReserva.h"
#include "Huesped.h"
#include "Reserva.h"

#include <stdexcept>

#ifndef RESERVAINDIVIDUAL
#define RESERVAINDIVIDUAL

class ReservaIndividual:public Reserva{
     private:
          //bool pagado; //lab0
          int alojamientoDias();
     public:
          ReservaIndividual(int codigo, DTFecha*, DTFecha*, Huesped*, Habitacion*);
          ~ReservaIndividual();
          //bool getPagado(); //lab0
          float costo();
          DTReserva getDatosReserva();
          void vincularReservaIndividual(Habitacion*,string emailHuesped);
          int cantidadDeEstadias();
};

#endif