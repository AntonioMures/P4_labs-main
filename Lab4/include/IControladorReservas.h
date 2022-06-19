#include "DTEstadia.h"
#include "DTCalificacion.h"
#include "DTReserva.h"
#include "DTHuesped.h"
#include <string>
#include <map>
#include <set>
#include <string>
#include "DTFecha.h"

#ifndef ICONTROLADORRESERVAS
#define ICONTROLADORRESERVAS

using namespace std;

class IControladorReservas {
     public:
          // Constructor
          IControladorReservas();
          // Funciones

          virtual bool existeEstadia(int identificador) = 0;
          virtual void elegirEstadia(int identificador) = 0;
          virtual int getIdEstadia() = 0; 
          virtual map<int, DTEstadia> listarEstadiasHuesped(string email, string nombre) = 0; 

          //Muestra la lista de reservas no canceladas del huésped en las cuales el huésped está registrado como parte de la reserva en ese hostal
          virtual map<int,DTReserva> listarReservasNoCanceladasDelHuesped(string email) = 0;

          virtual map<int, DTEstadia> listarEstadiasHostal(string nombre) = 0;
          virtual DTEstadia mostrarDatosEstadia(int seleccion) = 0;
          virtual DTCalificacion verCalificaion(int seleccion, string &resp) = 0;
          virtual DTReserva reservaAsociada(int seleccion) = 0;
          virtual int CamasDispEnHab(string nombreHostal,int numHab,DTFecha in, DTFecha out) = 0;
          virtual bool existeReserva(int) = 0;
          virtual void altaEstadia(int codReserva,string huespedQueReserva) = 0;
          virtual void confirmarReservaIndividual(string nombreHostal, int numHab,string huespedQueReserva, DTFecha* checkin, DTFecha* checkout) = 0;
          virtual void confirmarReservaGrupal(string nombreHostal, int numHab,string huespedQueReserva, DTFecha* checkin, DTFecha* checkout,map<string,DTHuesped> conjHuespedes) = 0;
          virtual void LiberarMemoria() = 0;
          virtual map<int,DTReserva> listarReservasHostal()=0;
          virtual map<int,DTReserva> listarReservasHostalSeleccionado(string nombre) = 0;
          virtual void eliminarReserva(int) =0;

          virtual void cancelarCreacionReserva() = 0;


          virtual DTEstadia estadiaActivaHuesped(string email) = 0;
          virtual void finalizarEstadiaActiva(DTFecha fecha, DTEstadia estadia) = 0;          

          //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
          //virtual void setEstadiaTemp(int valor) = 0;
          //virtual int getEstadiaTemp() = 0;
          //virtual void elegirHabitacionReserva(int numHab) = 0;
          //virtual void elegirHostal(string nombreHostal) = 0;
          //virtual void ingresarDatosReserva(DTFecha* checkin, DTFecha* checkout, bool esIndividual) = 0;
          //virtual void elegirHuesped(string) = 0;
          
          // Destructor
		virtual ~IControladorReservas();
};

#endif