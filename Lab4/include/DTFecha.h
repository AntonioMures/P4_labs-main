#ifndef DTFECHA
#define DTFECHA

class DTFecha{
     private:
          int dia, mes, anio, hora;
     public:
          DTFecha();
          DTFecha(int d, int m, int a, int h);
          int getDia();
          int getMes();
          int getAnio();
          int getHora();
          bool operator<(DTFecha*);
          bool operator==(DTFecha*);
          bool operator>(DTFecha*);
          bool operator<=(DTFecha*);
          bool operator>=(DTFecha*);
          bool operator!=(DTFecha*);
          void sumarUnDia();
          ~DTFecha();
};

#endif