//
// Created by franco on 24/11/20.
//

#ifndef TP2_TIERRA_H
#define TP2_TIERRA_H

#include "personaje.h"

class Tierra : public Personaje {

private:

    const int COSTO_ENERGIA_ATAQUE = 6;
    const int COSTO_ENERGIA_DEFENSA = 5;
    const int DEBILIDAD = -10;
    const int FORTALEZA = -20;
    const int ATAQUE_CERCANO = -30;
    const int ATAQUE_MEDIANO = -30;
    const int ATAQUE_LEJANO = -30;
    const int ESCUDO_EXTRA = 2;
    const int DEFENSA_EQUIPO = 10;
    std::string elemento_debilidad = "aire";
    std::string elemento_fortaleza = "agua";

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

    bool validarEnergiaAtaque();

    bool validarEnergiaDefensa();

    void objetivos(Tablero &tablero, string objetivos[]);

    int calculo_ataque(int posicion, string elemento, int defensa);




    void defenderse(Tablero &tablero);

};


#endif //TP2_TIERRA_H
