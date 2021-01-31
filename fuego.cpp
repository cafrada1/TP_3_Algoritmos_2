//
// Created by franco on 18/11/20.
//

#include "fuego.h"

const string NOMBRE_ALIMENTO = "Madera";

const int VIDA_RECUPERADA = 15;

Fuego::Fuego(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo) : Personaje(vida,
                                                                                                                   nombre,
                                                                                                                   escudo,
                                                                                                                   energia,
                                                                                                                   tipo) {

}

void Fuego::alimentarse() {

    unsigned int vida_anterior = obtenerVida();

    cambiarVida(VIDA_RECUPERADA);

    if (vida_anterior < obtenerVida()) {
        cout << " \n\n" << obtenerNombre() << " se ha alimentado con " << NOMBRE_ALIMENTO << endl;
        cout << "Ha recuperado " << obtenerVida() - vida_anterior << " de vida\n" << endl;
    } else {
        cout << " \n\n" << obtenerNombre() << " ya esta sano. No puede alimentarse mas\n" << endl;
    }

}