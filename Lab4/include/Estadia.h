#include <set>
#include "Calificacion.h"
#include "DTFecha.h"
#include "DTCalificacion.h"
#include "DTEstadia.h"

class Huesped;
class Reserva;

#ifndef ESTADIA
#define ESTADIA

class Estadia{

    private:
        int codigo;
        DTFecha* checkInEstadia;
        DTFecha* checkOutEstadia;
        int promo;
        Reserva* res;
        Huesped* hues;
        Calificacion* cal;

    public:
        int getCodigo();
        int alojamientoDias();
        Estadia(Reserva* res, Huesped* hues);
        Estadia(Reserva* res, Huesped* hues,DTFecha* checkin);//Este constructor se usa para los datos de prueba
        DTFecha* getCheckInEstadia();
        DTFecha* getCheckOutEstadia();
        int getPromo();
        Reserva* getRes();
        Huesped* getHues();
        Calificacion* getCal();
        float costoEstadia();
        DTCalificacion getCalificacion();
        void setCalificacion(Calificacion* cal);
        void setReserva(Reserva* res);
        void setHuesped(Huesped* hues);
        void desvincularHuesped(Huesped*);
        // BUG:  void vincular(int idReserva, Huesped* h);
        DTEstadia getDatosEstadia();
        ~Estadia();
};

#endif