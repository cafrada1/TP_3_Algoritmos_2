//
// Created by franco on 8/2/21.
//

#include "casillero.h"
#include <math.h>

void Casillero::setX(int x) {
    pos_x = x;
}

void Casillero::setY(int y) {
    pos_y = y;
}

void Casillero::setTerreno(string tipo) {
    tipo_terreno = tipo;
}

void Casillero::cambiarDisponible() {
    if (disponible){
        disponible = false;
    }
    else{
        disponible = true;
    }
}

bool Casillero::getDisponible() {
    return disponible;
}

int Casillero::getX() {
    return pos_x;
}

int Casillero::getY() {
    return pos_y;
}

int Casillero::getNumero() {
    return numero;
}

int Casillero::distancia(Casillero *casillero) {
    return (abs(casillero->getX()-pos_x)+abs(casillero->getY()-pos_y));
}

Casillero::Casillero(int x, int y, string terreno, int numero_casillero) {
    pos_x = x;
    pos_y = y;
    tipo_terreno = terreno;
    numero = numero_casillero;
}

void Casillero::mostrar() {
    //cout << "(" << pos_x << "," << pos_y << "," << numero<<")";
    cout << "( x = " << pos_x << ", y = " << pos_y << ", nº" << numero << ", Terreno: " <<getTerreno()<<")";
}

string Casillero::getTerreno() {
    return tipo_terreno;
};

