#include <map>
#include "DTHuesped.h"
#include "Usuario.h"
#include "Estadia.h"

class Reserva;

using namespace std;

#ifndef HUESPED
#define HUESPED

class Huesped:public Usuario {
    private:
        bool esFinger;
        map<int,Estadia*> Estadias;
        map<int,Reserva*> Reservas;
    public:
        Huesped(string nom, string email, string pass, bool es);
        bool getFinger();
        void setFinger(bool esFinger);

        //Crea un DTHuesped
        DTHuesped getDatosHuesped();
        void vincularReserva(Reserva*);
        //Acá no hace falta desvincular reserva???

        map<int,Reserva*> getReservas();
        void desvincularEstadia(Estadia *);
        ~Huesped();
};

#endif