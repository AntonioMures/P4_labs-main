#include "DTFecha.h"
#include "EstadoReserva.h"
#include "Habitacion.h"
#include "DTReserva.h"
#include "Huesped.h"

#ifndef RESERVA
#define RESERVA

class Reserva {
     protected:
          int codigo;
          DTFecha* checkin;
          DTFecha* checkout;
          EstadoReserva estado;
          //Es el huésped que realiza la reserva
          Huesped* huesped;
          Habitacion* habitacion;
          map<int,Estadia*> estadias; //la reserva tiene varias estadías
     public:
          // Constructor
          Reserva(int, DTFecha*, DTFecha*, Huesped*, Habitacion*);
          // Getters
		int getCodigo();
		DTFecha *getCheckin();
		DTFecha *getCheckOut();
		EstadoReserva getEstado();
          Huesped* getHuesped();
          Habitacion* getHabitacion();
          // Setters
          void setCodigo(int);
		void setCheckin(DTFecha*);
		void setCheckOut(DTFecha*);
		void setEstado(EstadoReserva);
          void setHuesped(Huesped*);
          void setHabitacion(Habitacion*);
          // Funciones
          virtual float costo() =0;
          DTReserva getDatosReserva();
          int cantidadDeEstadias();
          void eliminarEstadias();
          void cerrarReserva();
          
          // Destructor
		virtual ~Reserva() =0;
};

#endif