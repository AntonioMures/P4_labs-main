#include <iostream>
#include "../include/Habitacion.h"
#include "../include/DTHabitacion.h"

#include <map>

using namespace std;

int main () {

     //Habitaciones
    Habitacion hab1(101, 200.5, 4);
    Habitacion hab2(201, 305.5, 3);


    //Tests

    cout << "Test getNumero: " << (hab1.getNumero()) << "\n Se espera 101 \n";
    cout << "Test getNumero: " << (hab1.getPrecio()) << "\n Se espera 200.5 \n";
    cout << "Test getCapacidad: " << (hab1.getCapacidad()) << "\n Se espera 4 \n";

    hab1.setNumero(104);
    cout << "Test setNumero: Confirmado \n";
    cout << "Test getNumero: " << (hab1.getNumero()) << "\n Se espera 104 \n";

    hab1.setPrecio(77.5);
    cout << "Test setPrecio: Confirmado \n";
    cout << "Test getPrecio: " << (hab1.getPrecio()) << "\n Se espera 77.5 \n";

    hab1.setCapacidad(8);
    cout << "Test setCapacidad: Confirmado \n";
    cout << "Test getCapacidad: " << (hab1.getCapacidad()) << "\n Se espera 8 \n";

    DTHabitacion DThab1 = hab1.getDatosHabitacion();

    cout << "Test getDatosHabitacion()\n";
    cout << "Test getNumero: " << (DThab1.getNumero()) << "\n Se espera 104 \n";
    cout << "Test getPrecio: " << (DThab1.getPrecio()) << "\n Se espera 77.5 \n";
    cout << "Test getCapacidad: " << (DThab1.getCapacidad()) << "\n Se espera 8 \n";

    return 0;

}