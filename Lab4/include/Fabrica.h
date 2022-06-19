#include "IControladorCalificacion.h"
#include "ControladorCalificacion.h"
#include "IControladorHostal.h"
#include "ControladorHostal.h"
#include "IControladorReservas.h"
#include "ControladorReservas.h"
#include "IControladorUsuarios.h"
#include "ControladorUsuarios.h"
#include "IFechaSistema.h"
#include "FechaSistema.h"

#ifndef FABRICA
#define FABRICA

class Fabrica {
     public:
          // Constructor
          Fabrica();
          // Funciones
          IControladorCalificacion* getInstanciaConCal();
          IControladorHostal* getInstanciaConHos();
          IControladorUsuarios* getInstanciaConUsu();
          IControladorReservas* getInstanciaConRes();
          IFechaSistema* getInstanciaFechaSis();
          // Destructor
		~Fabrica();
};

#endif