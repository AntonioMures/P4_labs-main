#ifndef DTHABITACION
#define DTHABITACION

class DTHabitacion {
     private:
          int numero;
		float precio;
          int capacidad;
     public:
          DTHabitacion(int num, float p, int c);
          int getNumero();
          int getCapacidad();
          float getPrecio();
          ~DTHabitacion();

};

#endif