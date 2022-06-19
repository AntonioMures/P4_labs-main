#include "DTFecha.h"
#include "EstadoReserva.h"

#ifndef DTRESERVA
#define DTRESERVA

class DTReserva {
     protected:
          int codigo;
          DTFecha* checkIn;
          DTFecha* checkOut;
          EstadoReserva estado;
          float costo;
          int habitacion;

     public:
          DTReserva(int cod, DTFecha* chIn, DTFecha* chOut, EstadoReserva est, float costo, int hab);
          int getCodigo();
          DTFecha* getCheckIn();
          DTFecha* getCheckOut();
          EstadoReserva getEstado();
          float getCosto();
          virtual int getHabitacion();
          //ACA la sobrecarga <<
          ~DTReserva();
}; 

#endif