//

#include "personaje.h"

//
// Created by franco on 11/11/20.

const int MAXIMO_VIDA = 100;
const int MAXIMO_ENERGIA = 20;

Personaje::Personaje(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo) {
    this->vida = vida;
    this->nombre = nombre;
    this->escudo = escudo;
    this->energia = energia;
    this->tipo = tipo;
}

unsigned int Personaje::obtenerVida() {
    return vida;
}

unsigned int Personaje::obtenerEnergia() {
    return energia;
}

unsigned int Personaje::obtenerEscudo() {
    return escudo;
}

string Personaje::obtenerNombre() {
    return nombre;
}

string Personaje::obtenerTipo() {
    return tipo;
}

void Personaje::cambiarVida(int aumento_vida) {

    if (vida + aumento_vida <= MAXIMO_VIDA) {
        vida += aumento_vida;
    } else if (vida < MAXIMO_VIDA) {
        vida = MAXIMO_VIDA;
    }
}

void Personaje::cambiarEnergia(int aumento_energia) {
    if (energia + aumento_energia <= MAXIMO_ENERGIA) {
        energia += aumento_energia;
    } else if (energia < MAXIMO_ENERGIA) {
        energia = MAXIMO_ENERGIA;
    }
}

void Personaje::mostrarDatos() {
    cout << "\tTipo de personaje: " << obtenerTipo() << endl;
    cout << "\tNombre: " << obtenerNombre() << endl;
    cout << "\tEnergia: " << obtenerEnergia() << endl;
    cout << "\tEscudo: " << obtenerEscudo() << endl;
    cout << "\tVida: " << obtenerVida() << endl;

}

