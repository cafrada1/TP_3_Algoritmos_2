//
// Created by franco on 18/11/20.
//

#ifndef TP2_FUEGO_H
#define TP2_FUEGO_H

#include "personaje.h"

class Fuego : public Personaje {
private:

    const int COSTO_ENERGIA_ATAQUE = 5;
    const int COSTO_ENERGIA_DEFENSA = 5;
    const int DEBILIDAD = -10;
    const int FORTALEZA = -30;
    const int ATAQUE = -20;
    const int DEFENSA_PERSONAL = 10;
    std::string elemento_debilidad = "agua";
    std::string elemento_fortaleza = "aire";
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

    bool validarEnergiaAtaque();

    bool validarEnergiaDefensa();

    void objetivos(Tablero &tablero, string objetivos[]);

    int calculo_ataque(int posicion, string elemento, int defensa);


    void defenderse(Tablero &tablero);
};


#endif //TP2_FUEGO_H
