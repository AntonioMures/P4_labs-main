#include "DTCalificacion.h"
#include "DTrespCalificacion.h"
#include "respCalificacion.h"
#include "DTFecha.h"
#include <string>

using namespace std;

#ifndef CALIFICACION
#define CALIFICACION

class Calificacion {
     private:
          int puntuacion;
          DTFecha* fecha;
		string comentario;
		respCalificacion* respuesta;
          int IDCalif;
     public:
          Calificacion(int p, DTFecha* f, string c, respCalificacion* r);
          int getPuntuacion();
          DTFecha* getFecha();
          respCalificacion* getRespuesta();
          int getId();
          bool CalificacionConRespuesta();
          string getComentario();
          void setPuntuacion(int puntuacion);
          void setFecha(DTFecha* fecha);
          void setComentario(string comentario);
		void agregarRespuesta(respCalificacion* com);
		DTCalificacion getDatosCalificacion();
          DTrespCalificacion obtenerRespuesta();
          void DesvincularRespuesta(); //Elimina el link entre la Calificación y respCalificacion
		~Calificacion();
};

#endif