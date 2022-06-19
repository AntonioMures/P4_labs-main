#include "DTReserva.h"

#ifndef DTRESERVAINDIVIDUAL
#define DTRESERVAINDIVIDUAL

class DTReservaIndividual : public DTReserva {
     protected:
          int codigo;
          DTFecha* checkIn;
          DTFecha* checkOut;
          EstadoReserva estado;
          float costo;
          int habitacion;

     public:
          DTReservaIndividual(int cod, DTFecha* chIn, DTFecha* chOut, EstadoReserva est, float costo, int hab);
          int getCodigo();
          DTFecha* getCheckIn();
          DTFecha* getCheckOut();
          EstadoReserva getEstado();
          float getCosto();
          int getHabitacion();
          ~DTReservaIndividual();
}; 

#endif