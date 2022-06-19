#include "Calificacion.h"
#include "DTCalificacion.h"
#include "Estadia.h"
#include "Hostal.h"

#include <set>

#ifndef ICONTROLADORCALIFICACION
#define ICONTROLADORCALIFICACION

class IControladorCalificacion {
     public:
          // Constructor
          IControladorCalificacion();
          // Funciones
          virtual map<int, DTCalificacion> listarComentarios(string email) = 0;
          virtual void elegirCalificacion(int opcion) = 0;
          virtual void registrarComentario(string respuesta) = 0;
          virtual void RemoverNotificaion(Calificacion*,Hostal*) = 0;
          virtual void EliminarCalificacion(Calificacion*,Estadia*) = 0;
          virtual void registrarCalificacion(Hostal* host, int identificadorEstadia, int puntuacion, string comentario) = 0;

          // Destructor
		virtual ~IControladorCalificacion();
};

#endif