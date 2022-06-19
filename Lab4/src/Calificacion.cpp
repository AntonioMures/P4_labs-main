#include "../include/Calificacion.h"
#include "../include/DTCalificacion.h"
#include "../include/DTFecha.h"
#include "../include/DTrespCalificacion.h"
#include "../include/respCalificacion.h"
#include "../include/ControladorCalificacion.h"

Calificacion::Calificacion(int p, DTFecha* f, string c, respCalificacion* r){
    puntuacion = p;
    fecha = f;
    comentario = c;
	respuesta = r;
    ControladorCalificacion* CCal=ControladorCalificacion::getInstancia();
    IDCalif=CCal->getIDCalif();
};

int Calificacion::getPuntuacion(){
    return this->puntuacion;
};

DTFecha* Calificacion::getFecha(){
    return this->fecha;
};

string Calificacion::getComentario(){
    return this->comentario;
};

respCalificacion* Calificacion::getRespuesta(){
    return this->respuesta;
};

int Calificacion::getId(){
    return IDCalif;
};

bool Calificacion::CalificacionConRespuesta(){
    return this->respuesta!=NULL;
};

void Calificacion::setPuntuacion(int p){
    this->puntuacion = p;
};

void Calificacion::setFecha(DTFecha* f){
    this->fecha = f;
};

void Calificacion::setComentario(string c){
    this->comentario = c;
};

void Calificacion::agregarRespuesta(respCalificacion* com){ //setRespuesta
    this->respuesta = com;
};
 
DTCalificacion Calificacion::getDatosCalificacion(){
    return DTCalificacion(IDCalif,puntuacion,fecha,comentario);
};

DTrespCalificacion Calificacion::obtenerRespuesta(){
    if(this->respuesta != NULL){
        DTrespCalificacion nuevo = DTrespCalificacion(respuesta->getRespuesta());
        return nuevo;
    } else {
        string j = "No tiene respuesta";
        DTrespCalificacion nuevo = DTrespCalificacion(j);
        return nuevo;
    }
};

//Elimina el link entre la Calificación y respCalificacion
void Calificacion::DesvincularRespuesta(){
    this->respuesta = NULL;
};

Calificacion::~Calificacion(){
};
