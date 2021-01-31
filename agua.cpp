//
// Created by franco on 24/11/20.
//

#include "agua.h"

const int ENERGIA_RECUPERADA = 10;
const int MAXIMO_ALIMENTOS = 3;

const string NOMBRE_ALIMENTO = "Plancton";

Agua::Agua(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo) : Personaje(vida,
                                                                                                                 nombre,
                                                                                                                 escudo,
                                                                                                                 energia,
                                                                                                                 tipo) {

}

void Agua::alimentarse() {
    unsigned int energia_anterior = obtenerEnergia();

    if (cantidad_alimentado < MAXIMO_ALIMENTOS) {
        cambiarEnergia(ENERGIA_RECUPERADA);

        if (energia_anterior < obtenerEnergia()) {
            cout << "\n\n" << obtenerNombre() << " se ha alimentado con " << NOMBRE_ALIMENTO << endl;
            cout << "Ha recuperado " << obtenerEnergia() - energia_anterior << " de energia\n" << endl;
            cantidad_alimentado++;
        }
    } else {
        cout << "\n\n" << obtenerNombre() << " ya esta lleno. No puede alimentarse mas\n" << endl;
    }
}
