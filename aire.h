//
// Created by franco on 18/11/20.
//

#ifndef TP2_AIRE_H
#define TP2_AIRE_H

#include "personaje.h"

class Aire : public Personaje {

private:
    const int COSTO_ENERGIA_ATAQUE = 8;
    const int COSTO_ENERGIA_DEFENSA = 15;
    const int DEBILIDAD = -10;
    const int FORTALEZA = -20;
    const int ATAQUE = -15;
    const int ESCUDO_EXTRA = 2;
    const int DEFENSA_EQUIPO = 10;
    std::string elemento_debilidad = "fuego";
    std::string elemento_fortaleza = "tiera";

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

    bool validarEnergia();

    void objetivos(Tablero &tablero, string objetivos[]);

    int calculo_ataque(int posicion, string elemento, int defensa);



    void defenderse();

};

#endif //TP2_AIRE_H
