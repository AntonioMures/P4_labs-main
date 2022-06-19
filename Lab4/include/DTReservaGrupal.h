#include "DTReserva.h"

#ifndef DTRESERVAGRUPAL
#define DTRESERVAGRUPAL

class DTReservaGrupal : public DTReserva {
     protected:
          int codigo;
          DTFecha* checkIn;
          DTFecha* checkOut;
          EstadoReserva estado;
          float costo;
          int habitacion;

     public:
          DTReservaGrupal(int cod, DTFecha* chIn, DTFecha* chOut, EstadoReserva est, float costo, int hab);
          int getCodigo();
          DTFecha* getCheckIn();
          DTFecha* getCheckOut();
          EstadoReserva getEstado();
          float getCosto();
          int getHabitacion();
          //ACA la sobrecarga <<
          ~DTReservaGrupal();
}; 

#endif