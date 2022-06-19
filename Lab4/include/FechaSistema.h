#include "DTFecha.h"
#include "IFechaSistema.h"

#ifndef FECHASISTEMA
#define FECHASISTEMA

//Singleton
class FechaSistema : public IFechaSistema{
    private:
        
        static FechaSistema* Instancia;
        DTFecha Fecha;
        
    public:
        FechaSistema();
        
        static FechaSistema* getInstancia();
        DTFecha getFechaSistema();
        void ActualizarFechaSistema(DTFecha);

        ~FechaSistema();
};

#endif