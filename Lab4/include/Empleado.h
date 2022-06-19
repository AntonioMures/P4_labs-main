#include <string>
#include "Usuario.h"
#include "DTCargoEmpleado.h"
#include "Calificacion.h"
#include "Hostal.h"
#include "DTEmpleado.h"

using namespace std;

#ifndef EMPLEADO
#define EMPLEADO

class Empleado: public Usuario {
   private:
      DTCargoEmpleado Cargo;
      bool recibeNotificaciones;

      int maxNumDeCalifGuardado;
      //El int es un número ordinal
      map<int,Calificacion*> CalifPendientes;

   public:
      Empleado(string nom, string email, string pass, DTCargoEmpleado,bool recibeNotificaciones);
      DTCargoEmpleado getCargo();
      bool getRecibeNotificaciones();
      map<int,Calificacion*> consultarNotificaiones();
      void setCargo(DTCargoEmpleado);
      DTEmpleado getDatosEmpleado();
      void setRecibeNotificaciones(bool);


      void notificar(Calificacion*,Hostal*);
      void removerNotif(Calificacion*,Hostal*);
      ~Empleado();
};

#endif