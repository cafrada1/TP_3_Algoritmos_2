//
// Created by franco on 24/11/20.
//

#include "tierra.h"

const int ENERGIA_RECUPERADA = 10;

const string NOMBRE_ALIMENTO = "Hierbas";

Tierra::Tierra(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo) : Personaje(
        vida, nombre,
        escudo, energia, tipo) {

}

void Tierra::alimentarse() {
    unsigned int energia_anterior = obtenerEnergia();

    cambiarEnergia(ENERGIA_RECUPERADA);

    if (energia_anterior < obtenerEnergia()) {
        cout << " \n\n" << obtenerNombre() << " se ha alimentado con " << NOMBRE_ALIMENTO << endl;
        cout << "Ha recuperado " << obtenerEnergia() - energia_anterior << " de energia\n" << endl;
    } else {
        cout << " \n\n" << obtenerNombre() << " ya esta lleno. No puede alimentarse mas\n" << endl;
    }
}
