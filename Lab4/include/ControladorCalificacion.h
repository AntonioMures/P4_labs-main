#include "IControladorCalificacion.h"
#include "ControladorUsuarios.h"

//#include "Estadia.h"
#include <string>

#ifndef CONTROLADORCALIFICACION
#define CONTROLADORCALIFICACION

using namespace std;

class ControladorCalificacion : public IControladorCalificacion {
     private:
          static ControladorCalificacion * instancia;
          map<int, Calificacion*> calificacionesHostal; // Memoria elegirCalificacion

          int maxIdCalif;
          Calificacion* cal; // Memoria elegirCalificacion
          //No corresponde implementar los conjuntos de Calificacion* ni de respCalifiacion* como se describía en el DCD del lab3 
     public:
          // Constructor
          ControladorCalificacion();
          static ControladorCalificacion * getInstancia();

          //Incrementa y devuelve un id nuevo
          int getIDCalif();

          //FUNCIONES
          map<int, DTCalificacion> listarComentarios(string email);
          void elegirCalificacion(int opcion);
          void registrarComentario(string respuesta);
          void RemoverNotificaion(Calificacion*,Hostal*);
          void EliminarCalificacion(Calificacion*,Estadia*);
          void registrarCalificacion(Hostal* host, int identificadorEstadia, int puntuacion, string comentario);

          // Destructor
		~ControladorCalificacion();
};

#endif