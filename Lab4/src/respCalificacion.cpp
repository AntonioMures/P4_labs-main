#include "../include/respCalificacion.h"

respCalificacion::respCalificacion(string r){
    respuesta = r;
}

string respCalificacion::getRespuesta(){
    return this->respuesta;
};

void respCalificacion::setRespuesta(string r){
    this->respuesta = r;
}

respCalificacion::~respCalificacion(){

};