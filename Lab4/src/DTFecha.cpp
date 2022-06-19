#include <iostream>
#include "../include/DTFecha.h"

using namespace std;

DTFecha::DTFecha(){
    dia=mes=anio=hora=1;
};

DTFecha::DTFecha(int d, int m, int a, int h) {
    if (d<1 || d>31 || m<1 || m>12 || a<1900 || h<0 || h>23)
        throw invalid_argument("Ha ingresado una fecha no soportada o incorrecta");
    else {
        dia = d;
        mes = m;
        anio = a;
        hora = h;
    }
};

int DTFecha::getDia() {
    return this->dia;
};

int DTFecha::getMes() {
    return this->mes;
};

int DTFecha::getAnio() {
    return this->anio;
};

int DTFecha::getHora() {
    return this->hora;
};

bool DTFecha::operator<(DTFecha* f){
    if (anio<f->getAnio())
        return true;
    else if (anio==f->getAnio() && mes<f->getMes())
        return true;
    else if (anio==f->getAnio() && mes==f->getMes() && dia<f->getDia())
        return true;
//    La hora no es relevante para las comparaciones en este rubro
//    else if (anio==f->getAnio() && mes==f->getMes() && dia==f->getDia() && hora<f->getHora())
//        return true;
    else
        return false;
};

bool DTFecha::operator==(DTFecha* f){
    // La hora no es relevante para las comparaciones en este rubro
    //return anio==f->getAnio() && mes==f->getMes() && dia==f->getDia() && hora==f->getHora();
    return anio==f->getAnio() && mes==f->getMes() && dia==f->getDia();
};

bool DTFecha::operator>(DTFecha* f){
    return !(*this<f) && !(*this==f);
};

bool DTFecha::operator<=(DTFecha* f){
    return *this<f || *this==f;
};

bool DTFecha::operator>=(DTFecha* f){
    return *this>f || *this==f;
};

bool DTFecha::operator!=(DTFecha* f){
    return !(*this==f);
};

void DTFecha::sumarUnDia(){
    dia++;
    if (dia==32){
        dia=1;
        mes++;
        if (mes==13){
            mes=1;
            anio++;
        }
    }
};

DTFecha::~DTFecha(){
};