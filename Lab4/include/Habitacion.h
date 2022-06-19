#include <map>
#include "DTHabitacion.h"
#include <string>

using namespace std;

class Reserva;
class Hostal;

class Hostal;

#ifndef HABITACION
#define HABITACION

class Habitacion {

    private:
        int numero;
        float precio;
        int capacidad;
        Hostal* hostal;

        map<string,Reserva*> reservas;

    public:
    
        Habitacion(int num, float precio, int cap, Hostal* host);

        void setNumero(int num);
        void setPrecio(float precio);
        void setCapacidad(int cap);
        void setHostal(Hostal* host);
        int getNumero();
        float getPrecio();
        int getCapacidad();
        Hostal* getHostal();
        map<string,Reserva*> getReservas();
        void desvincularReserva(Reserva*);
        DTHabitacion getDatosHabitacion();
        ~Habitacion();
}; 

#endif
