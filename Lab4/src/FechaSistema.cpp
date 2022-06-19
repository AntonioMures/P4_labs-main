#include <iostream>
#include "../include/FechaSistema.h"

using namespace std;

FechaSistema * FechaSistema::Instancia = NULL;

FechaSistema::FechaSistema(){};
FechaSistema* FechaSistema::getInstancia(){
    if (Instancia==NULL)
        Instancia=new FechaSistema();
    return Instancia;
};

DTFecha FechaSistema::getFechaSistema(){
    if (Instancia==NULL)
        Instancia=new FechaSistema();
    return Fecha;
};

void FechaSistema::ActualizarFechaSistema(DTFecha f){
    if (Instancia==NULL){
        Instancia=new FechaSistema();
        Fecha=f;
    } else
        Fecha=f;
};

FechaSistema::~FechaSistema(){};