#include "IControladorReservas.h"
#include "DTFecha.h"
#include "ControladorUsuarios.h"
#include "ControladorCalificacion.h"
#include "Estadia.h"
#include "DTEstadia.h"
#include "Habitacion.h"
#include "DTHostal.h"
#include "IControladorReservas.h"
#include "Reserva.h"

#include <map>
#include <string>

using namespace std;

class Habitacion;

#ifndef CONTROLADORRESERVAS
#define CONTROLADORRESERVAS

class ControladorReservas : public IControladorReservas {
     private:
          // Constructor
          ControladorReservas();

          static ControladorReservas * instancia;
          map<int,Estadia*> estadias; 
          int IdEstadia; // identificador de la estadia
          map<int,Reserva*> reservas;
          int maxCodReservaExistente;
          int maxCodEstadiaExistente;
          
          //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN Y PASAJE POR PARÁMETROS
          //static struct {
          //     DTHostal hostal;
          //     string nombreHostal;
          //     DTFecha * checkin;
          //     DTFecha * checkout;
          //     bool individual;
          //     int numHabitacion;
          //     string huespedQueReserva;
          //     int habitacionElegida;
          //     int codReserva;
          //     string huespedDeLaReserva;
          //} memoriaReservas;
          //podría redundar con el struct memoriaReservas, resolver 
          //int estadiaTemp; // Se almacena la estadia elegida por el usuario
     public:
          static ControladorReservas * getInstancia();

          //FUNCIONES

          bool existeEstadia(int identificador);// Martina

          Estadia* getEstadia(int identificador);

          //Además de devolverlo lo incrementa
          int getCodReservaNuevo();


          DTEstadia estadiaActivaHuesped(string email);
          void finalizarEstadiaActiva(DTFecha fecha, DTEstadia estadia);
          
          //Además de devolverlo lo incrementa
          int getCodEstadiaNuevo();

          map<int, DTEstadia> listarEstadiasHuesped(string email, string nombre); // Martina
          void elegirEstadia(int identificador); // Martina
          int getIdEstadia(); // Martina
          map<int,Reserva*> getReservas();
          int CamasDispEnHab(string nombreHostal,int numHab,DTFecha in, DTFecha out);
          bool existeReserva(int);
          void altaEstadia(int codReserva,string huespedQueReserva);
          void confirmarReservaIndividual(string nombreHostal, int numHab,string huespedQueReserva, DTFecha* checkin, DTFecha* checkout);
          void confirmarReservaGrupal(string nombreHostal, int numHab,string huespedQueReserva, DTFecha* checkin, DTFecha* checkout,map<string,DTHuesped> conjHuesp);
          void LiberarMemoria();

          //Muestra la lista de reservas no canceladas del huésped en las cuales el huésped está registrado como parte de la reserva en ese hostal
          map<int,DTReserva> listarReservasNoCanceladasDelHuesped(string email);
          map<int, DTEstadia> listarEstadiasHostal(string nombre);
          DTEstadia mostrarDatosEstadia(int seleccion);
          DTCalificacion verCalificaion(int seleccion, string &resp);
          DTReserva reservaAsociada(int seleccion);
          map<int,DTReserva> listarReservasHostal();
          map<int,DTReserva> listarReservasHostalSeleccionado(string nombre);
          void eliminarReserva(int);
          void cancelarCreacionReserva();

          //Como no existe un caso de uso que permita crear estadías del pasado, se implementa una función en el controlador sólo para cargar datos de prueba
          Estadia* DPRegistrarEstadia(Reserva*,string emailHuesped,DTFecha* checkin);

          //SE REEMPLAZA MEMORIA DEL SISTEMA POR MEMORIA LOCAL EN MAIN PASAJE POR PARÁMETROS
          //void setEstadiaTemp(int valor);
          //int getEstadiaTemp();
          //void elegirHabitacionReserva(int numHab);
          //void elegirHostal(string nombreHostal);
          //void ingresarDatosReserva(DTFecha* checkin, DTFecha* checkout, bool esIndividual);
          //void elegirReserva(int);
          //void elegirHuesped(string);

          // Destructor
		~ControladorReservas();
};

#endif
