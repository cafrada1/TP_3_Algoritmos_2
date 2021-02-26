//
// Created by franco on 8/2/21.
//

#include "casillero.h"
#include <math.h>

#pragma region IMPLEMENTACION DE METODOS

#pragma region CONSTRUCTOR

Casillero::Casillero(int x, int y, string terreno, int numeroCasillero) {
    posX = x;
    posY = y;
    tipoTerreno = terreno;
    numero = numeroCasillero;
}


#pragma endregion

#pragma region SETTERS

void Casillero::setX(int x) {
    posX = x;
}

void Casillero::setY(int y) {
    posY = y;
}

void Casillero::setTerreno(string tipo) {
    tipoTerreno = tipo;
}

void Casillero::cambiarDisponible() {
    if (disponible) {
        disponible = false;
    } else {
        disponible = true;
    }
}

#pragma endregion

#pragma region GETTERS

bool Casillero::getDisponible() {
    return disponible;
}

int Casillero::getX() {
    return posX;
}

int Casillero::getY() {
    return posY;
}

int Casillero::getNumero() {
    return numero;
}

string Casillero::getTerreno() {
    return tipoTerreno;
};
#pragma endregion

int Casillero::distancia(Casillero *casillero) {
    return (abs(casillero->getX() - posX) + abs(casillero->getY() - posY));
}


void Casillero::mostrar() {
    //cout << "(" << posX << "," << posY << "," << numero<<")";
    cout << "( x = " << posX << ", y = " << posY << ", nº" << numero << ", Terreno: " << getTerreno() << ")";
}

#pragma endregion
