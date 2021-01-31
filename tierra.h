//
// Created by franco on 24/11/20.
//

#ifndef TP2_TIERRA_H
#define TP2_TIERRA_H

#include "personaje.h"

class Tierra : public Personaje {

public:

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     */
    Tierra(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo);


    /*
     * PRE: -
     *
     * POST: aumenta la energia del personaje no superando el maximo permitido.
     * Si se encuentra en el maximo no se realizan cambios y
     * se muestra un mensaje por pantalla
     *
     * FUNCIONAMIENTO: aumenta la energia del personaje, muestra
     * por pantalla la energia recuperada y el alimento usado.
     */
    void alimentarse();

};


#endif //TP2_TIERRA_H
