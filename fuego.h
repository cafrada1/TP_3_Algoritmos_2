//
// Created by franco on 18/11/20.
//

#ifndef TP2_FUEGO_H
#define TP2_FUEGO_H

#include "personaje.h"

class Fuego : public Personaje {

public:

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     */
    Fuego(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo);

    /*
     * PRE: -
     *
     * POST: aumenta la energia del personaje no superando el maximo permitido.
     * Si se encuentra en el maximo  no se realizan cambios y
     * se muestra un mensaje por pantalla
     *
     * FUNCIONAMIENTO: aumenta la energia del personaje, muestra
     * por pantalla la energia recuperada y el alimento usado.
     */
    void alimentarse();
};


#endif //TP2_FUEGO_H
