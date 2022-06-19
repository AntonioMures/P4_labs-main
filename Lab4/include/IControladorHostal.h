#include "Hostal.h"
#include "DTHostal.h"
#include "DTFecha.h"
#include "DTHabitacion.h"
#include "DTCalificacion.h"
#include <string>
#include <map>

#ifndef ICONTROLADORHOSTAL
#define ICONTROLADORHOSTAL

class IControladorHostal {
     public:
          // Constructor
          IControladorHostal();
          // Funciones
          virtual bool existeHostal(string nombre) = 0;
          virtual void ConfirmarHostal(string nombre, int telefono, string direccion) = 0;
          virtual map<string, DTHostal> listarHostales() = 0;
          virtual void confirmarHabitacion(string nombreHos, int numero, float precio, int capacidad) = 0;
          virtual bool existeHabitacion(int hab,string nomHostal) = 0;

          virtual Hostal* getPunteroHostal(string nombreHostal) = 0;
          //Pre: nomHostal es un hostal válido
          //Post: Devuelve un map<NumeroHab,CapacidadDisponible> de las habitaciones con CapacidadDisponible!=0 del hostal
          virtual map<int,int> listarHabitacionesDisponibles(string nomHostal,DTFecha in, DTFecha out) = 0;
          
          virtual DTHabitacion mostrarDatosHabitacion(string nomHostal,int numHab) = 0;
          virtual map<string,float> mostrarTop3Hostales() = 0;
          virtual map<int,DTCalificacion> datosCalificacionesHostal(string nombre) = 0;
          virtual string getHostalDeEmpleado(string email) = 0;
          virtual void asignarEmpleado(string email, string hostal) = 0;
          virtual DTHostal datosHostal(string) = 0;

          // Destructor
		virtual ~IControladorHostal();

          //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
          //virtual void elegirHabitacion(string nomHostal,int numHab) = 0;
          //virtual void elegirHostal(string nombre) = 0;
          //virtual string getNombreHostElegido() = 0;
};

#endif