#include <string>
#include "DTCargoEmpleado.h"

using namespace std;

#ifndef DTEMPLEADO
#define DTEMPLEADO

class DTEmpleado {
   private:
      string nombre, email, password;
      DTCargoEmpleado Cargo;
      bool recibeNotificaciones;
   public:
      DTEmpleado(string nombre,string email, string pass, DTCargoEmpleado, bool recibeNotificaciones);
      string getNombre();
      string getEmail();
      string getPassword();
      DTCargoEmpleado getCargo();
      bool getRecibeNotificaciones();
      ~DTEmpleado();
};

#endif