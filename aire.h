//
// Created by franco on 18/11/20.
//

#ifndef TP2_AIRE_H
#define TP2_AIRE_H

#include "personaje.h"
#include "Tablero.h"
class Aire : public Personaje {

private:
    Tablero tablero;
    const int COSTO_ENERGIA_ATAQUE = 8;
    const int COSTO_ENERGIA_DEFENSA = 15;
    const int DEBILIDAD = -10;
    const int FORTALEZA = -20;
    const int ATAQUE = -15;
    const int ESCUDO_EXTRA = 2;
    const int DEFENSA_EQUIPO = 10;
    std::string elemento_debilidad = "fuego";
    std::string elemento_fortaleza = "agua";


public:
    /*
     * PRE:
     *
     * POST:
     *
     * FUNCIONAMIENTO:
     */
    Aire(unsigned int vida, std::string nombre, unsigned int escudo, unsigned int energia, std::string tipo, int posicion, Tablero tablero);


    /*
     * PRE: -
     *
     * POST: -
     *
     * FUNCIONAMIENTO: muestra por pantalla que el personaje no necesita alimentarse.
     */
    void alimentarse();


    void atacar();

    void calculo_ataque(Personaje *personaje_atacado);

    void defenderse();

};

#endif //TP2_AIRE_H
