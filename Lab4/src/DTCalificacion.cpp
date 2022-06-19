#include "../include/DTCalificacion.h"
#include "../include/DTFecha.h"

DTCalificacion::DTCalificacion(int id,int p, DTFecha* f, string c){
    idCalif=id;
    puntuacion = p;
    fecha = f;
    comentario = c;    
}
int DTCalificacion::getPuntuacion(){
    return this->puntuacion;
};

DTFecha* DTCalificacion::getFecha(){
    return this->fecha;
};

string DTCalificacion::getComentario(){
    return this->comentario;
};

int DTCalificacion::getId(){
    return idCalif;
};

DTCalificacion::~DTCalificacion(){
    
};