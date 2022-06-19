#include "DTFecha.h"

#ifndef IFECHASISTEMA
#define IFECHASISTEMA

using namespace std;

class IFechaSistema {
     public:
          // Constructor
          IFechaSistema();

          // Funciones
          virtual DTFecha getFechaSistema() = 0;
          virtual void ActualizarFechaSistema(DTFecha) = 0;
          
          virtual ~IFechaSistema();
};

#endif