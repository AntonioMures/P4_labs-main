#include "DTFecha.h"
#include <string>

using namespace std;

#ifndef DTCALIFICACION
#define DTCALIFICACION

class DTCalificacion {
     private:
        int puntuacion;
        DTFecha* fecha;
		string comentario;
        int idCalif;

     public:
        DTCalificacion(int id,int p, DTFecha* f, string c);
        int getPuntuacion();
        DTFecha* getFecha();
        string getComentario();
        int getId();
		~DTCalificacion();
};

#endif