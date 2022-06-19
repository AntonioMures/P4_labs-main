#include <map>
#include <set>
#include <string>

#include "DTEmpleado.h"
#include "DTEstadia.h"
#include "DTHuesped.h"
#include "DTReserva.h"
#include "Hostal.h"

#ifndef ICONTROLADORUSUARIOS
#define ICONTROLADORUSUARIOS

//interfaz
class IControladorUsuarios {
     public:
          // Constructor
          IControladorUsuarios();

          // Funciones 
          virtual map<string,DTHuesped> listarHuespedes() = 0;
          virtual map<string,DTEmpleado> listarEmpleados() = 0;
          virtual string getEmHuesped() = 0;
          virtual bool existeUsuario(string email) = 0;
          virtual bool existeHuesped(string email) = 0;
          virtual void ConfirmarHuesped(string nombre, string email, string password, bool esFinger) = 0;
          virtual void ConfirmarEmpleado(string nombre, string email, string password, bool recibeNotificaciones) = 0;
          virtual string buscarHostal(string email) = 0;
          virtual map<string,DTEmpleado> listarEmpleadosSinAsignar() = 0;
          /*
          Descripción: Asocia un Empleado a un Hostal en el sistema
          Pre: El sistema tiene en memoria los datos del empleado, el cargo y el hostal
          Post: El empleado asignado queda asociado como Empleado del Hostal en el sistema
          */
          //virtual void asignarEmpleado() = 0;

          //(Ver Diagrama de Comunicación)
          virtual void vincularEmpCargo(string email, DTCargoEmpleado cargo) = 0;

          virtual void vincularReserva(Reserva*, string email) = 0;
          virtual void suscribirse(string email) = 0;
          virtual void eliminarSuscripcion(string email) = 0;
          virtual map<int,DTCalificacion> consultarNotificaciones(string mail) = 0;
          virtual void cancelarAsignacion() = 0;
          virtual void liberarMemoria() = 0;
          virtual DTHuesped datosHuesped(string email) = 0;

          // Destructor
		virtual ~IControladorUsuarios();

          //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
          //virtual void elegirHuesped(string email) = 0;
};

#endif