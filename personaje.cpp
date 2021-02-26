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

void Personaje::cambiarVida(int cambio_vida) {

    if (vida + cambio_vida <= MAXIMO_VIDA) {
        vida += cambio_vida;
    } else if (vida < MAXIMO_VIDA) {
        vida = MAXIMO_VIDA;
    }
    if (vida < 0){
        cout<<"El personaje "<< nombre << " ha muerto!";
        vida = 0;
    } else if (cambio_vida < 0){
        cout<<nombre << " ahora tiene "<<vida<<" puntos de vida"<<endl;
    }

}

void Personaje::cambiarEnergia(int aumento_energia) {
    if (energia + aumento_energia <= MAXIMO_ENERGIA) {
        energia += aumento_energia;
    } else if (energia < MAXIMO_ENERGIA) {
        energia = MAXIMO_ENERGIA;
    }
}

void Personaje::cambiarEscudo(int cambio_escudo) {
    escudo += cambio_escudo;

}


void Personaje::mostrarDatos() {
    cout << "\tTipo de personaje: " << obtenerTipo() << endl;
    cout << "\tNombre: " << obtenerNombre() << endl;
    cout << "\tEnergia: " << obtenerEnergia() << endl;
    cout << "\tEscudo: " << obtenerEscudo() << endl;
    cout << "\tVida: " << obtenerVida() << endl;

}


void Personaje::setVida(int vida){
    this->vida = vida;
}

void Personaje::setEnergia(int energia){
    this->energia = energia;
}

void Personaje::setEscudo(int escudo){
    this->escudo = escudo;
}