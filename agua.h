//
// Created by franco on 24/11/20.
//

#ifndef TP2_AGUA_H
#define TP2_AGUA_H

#include "personaje.h"

class Agua : public Personaje {

    // Atributos
private:
    int cantidad_alimentado = 0;

    //Metodos
public:
    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     */
    Agua(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo);

    /*
     * PRE: -
     *
     * POST: aumenta la salud del personaje no superando el maximo permitido.
     * Si se encuentra en el maximo o se llego al maximo de alimentos no se realizan
     * cambios y se muestra un mensaje por pantalla
     *
     * FUNCIONAMIENTO: aumenta la salud del personaje, muestra
     * por pantalla la salud recuperada y el alimento usado.
     */
    void alimentarse();

};

#endif //TP2_AGUA_H
