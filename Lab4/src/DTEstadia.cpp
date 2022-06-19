#include "../include/DTEstadia.h"

DTEstadia::DTEstadia(DTFecha* checkInEstadia, DTFecha* checkOutEstadia, int promo, string hues, int cal, int hab, float costo) {
    this->checkInEstadia = checkInEstadia;
    this->checkOutEstadia = checkOutEstadia;
    this->promo = promo;
    this->hues = hues;
    this->cal = cal;
    this->hab = hab;
    this->costo = costo;
};

DTFecha* DTEstadia::getCheckInEstadia() {
    return this->checkInEstadia;
};

DTFecha* DTEstadia::getCheckOutEstadia() {
    return this->checkOutEstadia;
};

int DTEstadia::getPromo() {
    return this->promo;
};

string DTEstadia::getHues() {
    return this->hues;
};

int DTEstadia::getCal() {
    return this->cal;
};

int DTEstadia::getHab() {
    return this->hab;
}

float DTEstadia::getCosto() {
    return this->costo;
}

DTEstadia::~DTEstadia() {

};