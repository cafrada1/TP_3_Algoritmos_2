//
// Created by franco on 18/11/20.
//

#include "aire.h"

Aire::Aire(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo) : Personaje(vida,
                                                                                                                 nombre,
                                                                                                                 escudo,
                                                                                                                 energia,
                                                                                                                 tipo) {

}

void Aire::alimentarse() {
    cout << "\n\n" << obtenerNombre() << " no necesita alimentarse\n" << endl;
}



