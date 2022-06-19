#include <iostream>
#include "../include/Estadia.h"
#include "../include/ReservaIndividual.h"
#include "../include/Habitacion.h"
#include "../include/EstadoReserva.h"
#include "../include/Calificacion.h"
#include "../include/Huesped.h"
#include "../include/DTFecha.h"

using namespace std;


int main () {

    //Fechas
    DTFecha* checkin = new DTFecha(21,3,2022, 10);
    DTFecha* checkout = new DTFecha(31,3,2022, 11);
    DTFecha* fechaCal = new DTFecha(3,4,2022, 16);

     //Habitaciones
    Habitacion* hab1 = new Habitacion(101, 200.5, 4);

    //Huespedes
    Huesped* hues1 = new Huesped("Huesped1", "test1@test.com", "pass1", true);
    Huesped* hues2 = new Huesped("Huesped2", "test2@test.com", "pass2", false);
   
        
    //Calificaciones
    Calificacion* cal1 = new Calificacion(5, fechaCal, "Aca va un comentario", NULL);
    Calificacion* cal2 = new Calificacion(3, fechaCal, "Aca va un comentario", NULL);
   
    //Reservas
    Reserva* res1 = NULL;
    Reserva* res2 = new ReservaIndividual(10001, checkin, checkout, hues1, hab1, false);

    //Estadias
    Estadia est1(checkin, checkout, 85, res2, hues1, cal1);

    //Tests


    DTFecha* chI = est1.getCheckInEstadia();
    DTFecha* chO = est1.getCheckOutEstadia();
    cout << "Test getCheckInEstadia: " << chI->getHora() << chI->getDia() << chI->getMes() << chI->getAnio() << "\n Se espera 102132022 \n";
    cout << "Test getCheckOutEstadia: " << chO->getHora() << chO->getDia() << chO->getMes() << chO->getAnio() << "\n Se espera 113132022 \n";
    cout << "Test getPromo: " << (est1.getPromo()) << "\n Se espera 85 \n";
    cout << "Test getRes: " << (est1.getRes()) << "\n NULL \n";
    cout << "Test getHues: " << (est1.getHues()->getNombre()) << "\n Se espera Huesped1 \n";
    cout << "Test getCal: " << (est1.getCal()->getPuntuacion()) << "\n Se espera 5 \n";
    DTCalificacion DTcal1 = est1.getCalificacion();
    cout << "Test getCalificacion: " << (DTcal1.getComentario()) << "\n Se espera Aca va un comentario \n";
    
    est1.setCalificacion(cal2);
    cout << "Test setCalificacion completo \n";
    cout << "Test getCal: " << (est1.getCal()->getPuntuacion()) << "\n Se espera 3 \n";
    est1.setReserva(res2);
    cout << "Test setReserva completo \n";
    cout << "Test costoEstadia: " << (est1.costoEstadia()) << "\n Se espera 2005 \n";
    cout << "Test getRes: " << (est1.getRes()->getCodigo()) << "\n Se espera 10001 \n";
    est1.setHuesped(hues2);
    cout << "Test setHuesped completo \n";
    cout << "Test getHues: " << (est1.getHues()->getFinger()) << "\n Se espera false \n";
    DTEstadia DTest1 = est1.getDatosEstadia();
    cout << "Test getDatosEstadia: " << (DTest1.getPromo()) << "\n Se espera 85 \n";

    return 0;

};