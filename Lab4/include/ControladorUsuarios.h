#include <map>
#include <string>
#include "Usuario.h"
#include "IControladorUsuarios.h"
#include "Empleado.h"
#include "Huesped.h"
#include "ControladorHostal.h"

#ifndef CONTROLADORUSUARIOS
#define CONTROLADORUSUARIOS

//Singleton
class ControladorUsuarios : public IControladorUsuarios{
    private:
        static ControladorUsuarios * instancia;
        map<string,Usuario*> Usuarios;
        string emHuesped; // Mail de elegirHuesped
        string emEmpleado; // Mail de elegirEmpleado
        map<string,Empleado*> observers;
    public:
        ControladorUsuarios();
        static ControladorUsuarios * getInstancia();

        //FUNCIONES
        string buscarHostal(string email);
        map<string,DTHuesped> listarHuespedes();
        map<string,DTEmpleado> listarEmpleados();
        Huesped* obtenerHuesped(string email);
        DTHuesped datosHuesped(string email);
        Empleado* obtenerEmpleado(string email);
        string getEmHuesped();

        bool existeUsuario(string email); //Martina
        void ConfirmarHuesped(string nombre, string email, string password, bool esFinger); //Martina
        void ConfirmarEmpleado(string nombre, string email, string password, bool recibeNotificaciones); //por defecto son Desempleado

        bool existeHuesped(string email);

        map<string,DTEmpleado> listarEmpleadosSinAsignar();
        
        //(Ver Diagrama de Comunicación)
        void vincularEmpCargo(string email, DTCargoEmpleado cargo);

        void vincularReserva(Reserva*,string email);
        map<string,Empleado*> getObservers();
        void suscribirse(string email);
        void eliminarSuscripcion(string email);
        //el entero del map es un número ordinal...
        map<int,DTCalificacion> consultarNotificaciones(string mail);
        void cancelarAsignacion();
        void liberarMemoria();

        ~ControladorUsuarios();

        //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
        //void elegirHuesped(string email);
};


#endif