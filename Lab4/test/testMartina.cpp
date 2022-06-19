#include "include/Calificacion.h"
#include "include/DTCalificacion.h"
#include "include/respCalificacion.h"
#include "include/DTrespCalificacion.h"
#include "include/DTFecha.h"

#include <iostream>
using namespace std;

int main(){
    
    DTFecha* fecha1 = new DTFecha(22, 1, 2022, 10);
    DTFecha* fecha2 = new DTFecha(23, 1, 2022, 12);

    Calificacion cal1(10, fecha1, "excelente", NULL);
    Calificacion cal2(3, fecha2, "pesimo", NULL);

    respCalificacion* resp1 = new respCalificacion("me alegro que le haya gustado");
    respCalificacion* resp2 = new respCalificacion("lamentamos su mala experiencia");

    cal1.agregarRespuesta(resp1);

    cout << "Test getPuntuacion calificacion1: " << cal1.getPuntuacion() << "\n Se espera 10 \n";
    cout << "Test getFecha calificacion1: " << cal1.getFecha()->getHora() << cal1.getFecha()->getDia() << cal1.getFecha()->getMes() << cal1.getFecha()->getAnio() << "\n Se espera 1022012022 \n";
    cout << "Test getRespuesta calificacion1: " <<cal1.getRespuesta()->getRespuesta() << "\n Se espera me alegro que le haya gustado \n";
    cout << "Test getComentario calificacion1: " << cal1.getComentario() << "\n Se espera excelente \n";


    cout << "Test getPuntuacion calificacion2: " << cal2.getPuntuacion() << "\n Se espera 3 \n";
    cout << "Test getFecha calificacion2: " << cal2.getFecha()->getHora() << cal2.getFecha()->getDia() << cal2.getFecha()->getMes() << cal2.getFecha()->getAnio() << "\n Se espera 1223012022 \n";
    cout << "Test getRespuesta calificacion1: ";
    if(cal2.getRespuesta() != NULL){
        cout << cal2.getRespuesta()->getRespuesta() << "\n Se espera lamentamos su mala experiencia \n";
    } else {
        cout << "No hay respuesta \n";
    }
    cout << "Test getComentario calificacion1: " << cal2.getComentario() << "\n Se espera pesimo \n";


    cal1.DesvincularRespuesta();
    
    cal2.agregarRespuesta(resp2);
    

    DTrespCalificacion DTrespcal1 = cal1.obtenerRespuesta();
    DTrespCalificacion DTrespcal2 = cal2.obtenerRespuesta();

    cout << "Respuesta a calificacion1: " << DTrespcal1.getRespuesta() << "\n Se espera no tiene respuesta \n";
    cout << "Respuesta a calificacion2: " << DTrespcal2.getRespuesta() << "\n Se espera lamentamos su mala experiencia \n";

    DTCalificacion DTcal1 = cal1.getDatosCalificacion();
    cout << "Test getDatosCalificacion calificacion1: " << DTcal1.getPuntuacion() << "\n Se espera 10 \n";

    return 0;
};