//
// Created by franco on 18/11/20.
//

#ifndef TP2_AIRE_H
#define TP2_AIRE_H

#include "personaje.h"

class Aire : public Personaje {

public:
    /*
     * PRE:
     *
     * POST:
     *
     * FUNCIONAMIENTO:
     */
    Aire(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo);


    /*
     * PRE: -
     *
     * POST: -
     *
     * FUNCIONAMIENTO: muestra por pantalla que el personaje no necesita alimentarse.
     */
    void alimentarse();

};

#endif //TP2_AIRE_H
