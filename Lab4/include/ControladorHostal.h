#include "IControladorHostal.h"
#include "Hostal.h"
#include "DTHostal.h"

#include <map>
#include <set>
#include <string>
#include <stdexcept>

#ifndef CONTROLADORHOSTAL
#define CONTROLADORHOSTAL

class ControladorHostal : public IControladorHostal {
     private:
          static ControladorHostal* instancia;
          map<std::string, Hostal*> hostales;

          //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
          //static struct{
          //     string nombreHostal;
          //} memoriaCHostales;

     public:
          // Constructor
          ControladorHostal();
          static ControladorHostal* getInstancia();


          //FUNCIONES
          map<int, Calificacion*> calificacionesHostal(string nombre);
          map<int, DTCalificacion> datosCalificacionesHostal(string nombre);
          string getHostalDeEmpleado(string email);
          bool existeHostal(string nombre); //Martina
          bool existeHabitacion(int hab,string nomHostal);
          void ConfirmarHostal(string nombre, int telefono, string direccion);//Martina
          void confirmarHabitacion(string nombreHos, int numero, float precio, int capacidad);
          map<string, DTHostal> listarHostales();
          Hostal* getPunteroHostal(string nombreHostal);
          DTHostal datosHostal(string);

          //Pre: nomHostal es un hostal válido
          //Post: Devuelve un map<NumeroHab,CapacidadDisponible> de las habitaciones con CapacidadDisponible!=0 del hostal
          map<int,int> listarHabitacionesDisponibles(string nomHostal,DTFecha in, DTFecha out);

          /*
          Si el par Hostal-numHab no es correcto returna un puntero NULL
          Esta función no se puede usar desde main
          */
          Habitacion* obtenerHabitacion(string nomHostal,int numHab);
          DTHabitacion mostrarDatosHabitacion(string nomHostal,int numHab);
          map<string,float> mostrarTop3Hostales();
          void asignarEmpleado(string email, string hostal);


          // Destructor
		~ControladorHostal();

          //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
          //void elegirHabitacion(string nomHostal,int numHab);
          //void elegirHostal(string nombre);
          //string getNombreHostElegido(); 
};

#endif