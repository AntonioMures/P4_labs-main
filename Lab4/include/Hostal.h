#include <string>
#include <set>
#include <map>

#include "Habitacion.h"
#include "Estadia.h"
#include "DTHabitacion.h"
#include "DTHostal.h"
#include "Calificacion.h"
#include "DTCalificacion.h"

class Empleado;
//class Habitacion;

#ifndef HOSTAL
#define HOSTAL

using namespace std;

class Hostal {

    private:
    string nombre;
    int telefono;
    string direccion;
    map<int, Habitacion*> mapHabitacion;
    map<Estadia*, Calificacion*> mapCalificacion;
    map<string, Empleado*> mapEmpleado;

    public:

    string getNombre();
    int getTelefono();
    string getDireccion();
    map<int, Habitacion*> getHabitaciones();
    map<Estadia*, Calificacion*> getCalificaciones();
    map<string, Empleado*> getEmpleados();


    Hostal(string nombre, int telefono, string direccion, map<int, Habitacion*> mapHabitacion, map<Estadia*, Calificacion*> mapCalificacion, map<string, Empleado*> mapEmpleado);
    float calificacionPromedio();
    void agregarHabitacion(Habitacion* hab);
    void eliminarHabitacion(Habitacion* hab);
    bool checkEmpleado(string email);
    map<int, DTHabitacion> mostrarHabitaciones();
    DTHostal getDatosHostal();
    DTCalificacion getCalificacion(Calificacion* cal);
    void removerCalifiacion(Calificacion*,Estadia*);
    void agregarEmpleado(string email, Empleado* emp);
    ~Hostal();
};

#endif