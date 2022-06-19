#include "DTFecha.h"
#include "EstadoReserva.h"
#include "Huesped.h"
#include "DTReservaGrupal.h"
#include "Reserva.h"

#include <stdexcept>

#ifndef RESERVAGRUPAL
#define RESERVAGRUPAL

class ReservaGrupal:public Reserva{
     private:
          map<string,Huesped*> huespedes;
          int alojamientoDias();
          //Las estadías se manejan en la clase padre Reserva
     public:
          //Constructor
          ReservaGrupal(int c, DTFecha* in, DTFecha* out, Huesped* hue, Habitacion* hab, map<string,Huesped*> conjuntoHuespedes);
          // Funciones
          float costo();
          int getCantidadDeHuespedes();
          //DTReserva getDatosReserva(); //creo que no va

          void vincularReservaGrupal(Habitacion*,string huespedQueReserva,map<string,Huesped*> conjuntoHuesp);
          int cantidadDeEstadias();
          // Destructor
          ~ReservaGrupal();
};

#endif