#include "../include/Utils.h"

int menorEntero(int A, int B){
    if (A<=B)
        return A;
    else
        return B;
};

float mayor(float A, float B){
    if (A>B)
        return A;
    else return B;
};

string estadoReservaString(EstadoReserva e){
    //Abierta, Cerrada, Cancelada
    switch (e){
    case Abierta:
        return "Abierta";
        break;
    case Cerrada:
        return "Cerrada";
        break;
    case Cancelada:
        return "Cancelada";
        break;
    default:
        return "Un error muy poco probable";
        break;
    }
};

string CargoEmpleadoString(DTCargoEmpleado c){
    //{Administracion,Limpieza,Recepcion,Infraestructura, Desempleado}
    switch (c){
        case Administracion:
            return "Administración";
        break;
        case Limpieza:
            return "Limpieza";
            break;
        case Recepcion:
            return "Recepción";
        break;
        case Infraestructura:
            return "Infraestructura";
        break;
        default:
            return "El empleado aún no trabaja en ningún Hostal";
        break;
    }
};