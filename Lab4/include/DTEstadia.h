#include <string>
#include "DTFecha.h"

using namespace std;

#ifndef DTESTADIA
#define DTESTADIA

class DTEstadia {
     private:

        DTFecha* checkInEstadia;
        DTFecha* checkOutEstadia;
        int promo;
        string hues;
        int cal;
        int hab;
        float costo;

     public:

        DTEstadia(DTFecha* checkInEstadia, DTFecha* checkOutEstadia, int promo, string hues, int cal, int hab, float costo);
        DTFecha* getCheckInEstadia();
        DTFecha* getCheckOutEstadia();
        int getPromo();
        string getHues();
        int getCal();
        int getHab();
        float getCosto();
        ~DTEstadia();

};

#endif