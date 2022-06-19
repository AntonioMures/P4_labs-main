#include <iostream>
#include "../include/Hostal.h"
#include "../include/Calificacion.h"
#include "../include/Estadia.h"
#include "../include/ReservaIndividual.h"
#include "../include/Empleado.h"
#include "../include/Habitacion.h"
#include "../include/Huesped.h"
#include "../include/DTCargoEmpleado.h"
#include "../include/DTFecha.h"
#include <map>

using namespace std;

int main () {

    map<int, Habitacion*> hab;
    map<Estadia*, Calificacion*> cal;
    map<string, Empleado*> emp;
    
    //Fechas
    DTFecha* checkin = new DTFecha(21,3,2022, 10);
    DTFecha* checkout = new DTFecha(31,3,2022, 11);
    DTFecha* fechaCal = new DTFecha(3,4,2022, 16);

    // Empleados
    Empleado* emp1 = new Empleado("Empleado1", "test1@test.com", "pass1", Administracion, true);
    Empleado* emp2 = new Empleado("Empleado2", "test2@test.com", "pass2", Recepcion, false);
    emp["Test1"] = emp1;
    emp["Test2"] = emp2;

    //Huespedes
    Huesped* hues1 = new Huesped("Huesped1", "test1@test.com", "pass1", true);
   
    //Habitaciones
    Habitacion* hab1 = new Habitacion(101, 200.5, 4);
    Habitacion* hab2 = new Habitacion(201, 305.5, 3);
    hab[101] = hab1;

    //Reservas
    Reserva* res1 = NULL;
    Reserva* res2 = new ReservaIndividual(10001, checkin, checkout, hues1, hab1, false);

    //Calificaciones
    Calificacion* cal1 = new Calificacion(5, fechaCal, "Aca va un comentario", NULL);
    Calificacion* cal2 = new Calificacion(3, fechaCal, "Aca va un comentario", NULL);
   
    //Estadias
    Estadia* est1 = new Estadia(checkin, checkout, 85, res1, hues1, cal1);
    Estadia* est2 = new Estadia(checkin, checkout, 100, res2, hues1, cal2);
   
   
    cal[est1] = cal1;
    cal[est2] = cal2;
    

    //Hostal
    Hostal hostal("testNombre", 1111, "testDireccion", hab, cal, emp);

    //Tests

    cout << "Test getNombre: " << (hostal.getNombre()) << "\n Se espera testNombre \n";
    cout << "Test getTelefono: " << (hostal.getTelefono()) << "\n Se espera 1111 \n";
    cout << "Test getDireaccion: " << (hostal.getDireccion()) << "\n Se espera testDireccion \n";

    map<int, Habitacion*> habTest = hostal.getHabitaciones();

    cout << "Test getHabitaciones: " << (habTest[101]->getPrecio()) << "\n Se espera 200.5 \n";

    map<Estadia*, Calificacion*> calTest = hostal.getCalificaciones();

    cout << "Test getCalificaciones: " << (calTest[est1]->getPuntuacion()) << "\n Se espera 5 \n";

    map<string, Empleado*> empTest = hostal.getEmpleados();

    //cout << "Test getEmpleados: " << (empTest["Empleado1"]->getCargo()) << "\n Se espera Administracion \n";

    cout << "Test calificacionPromedio: " << (hostal.calificacionPromedio()) << "\n Se espera 4 \n";

    hostal.agregarHabitacion(hab2);
    cout << "Test agregarHabitacion completado \n";

    hostal.eliminarHabitacion(hab1);
    cout << "Test eliminarHabitacion completado \n";

    habTest = hostal.getHabitaciones();
    cout << "Test getHabitaciones: " << (habTest[201]->getCapacidad()) << "\n Se espera 3 \n";

    cout << "Test checkEmpleado: " << (hostal.checkEmpleado("test1@test.com")) << "\n Se espera true \n";

    /*
    g++ testHostal.cpp ../src/DTFecha.cpp ../src/ReservaIndividual.cpp ../src/Habitacion.cpp ../include/EstadoReserva.h ../src/Calificacion.cpp ../src/Estadia.cpp ../src/Huesped.cpp ../src/DTEstadia.cpp ../src/DTCalificacion.cpp ../src/DTrespCalificacion.cpp ../src/Reserva.cpp ../src/respCalificacion.cpp ../src/Usuario.cpp ../src/DTHabitacion.cpp ../src/DTHuesped.cpp ../src/Hostal.cpp ../src/Empleado.cpp ../src/DTHostal.cpp -o testHostal
    */

    return 0;

}