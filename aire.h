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


    /*
     * PRE:
     * POST: false si no tiene suficiente energia, true si tiene suficiente.
     * FUNCIONAMIENTO: Corrobora que el personaje tiene suficiente energia para atacar
     */
    bool validarEnergiaAtaque();


    /*
     * PRE:
     * POST: false si no tiene suficiente energia, true si tiene suficiente.
     * FUNCIONAMIENTO: Corrobora que el personaje tiene suficiente energia para defenderse
     */
    bool validarEnergiaDefensa();


    /*
     * PRE: Recibe el objeto tablero por referencia, y un vector tipo string que modificara con los objetivos a atacar.
     * POST:
     * FUNCIONAMIENTO: define los objetivos a atacar.
     */
    void objetivos(Tablero &tablero, string objetivos[]);


    /*
     * PRE: Recibe la posicion, el elemento y la defensa del personaje a atacar.
     * POST: Devuelve la cantidad de daño realizado al enemigo
     * FUNCIONAMIENTO: define la cantidad de daño a realizar a un enemigo.
     */
    int calculo_ataque(int posicion, string elemento, int defensa);


    /*
     * PRE: Recibe el objeto tablero por referencia
     * POST:
     * FUNCIONAMIENTO:EL personaje de aire se desplaza a cualquier casillero del tablero.
     */
    void defenderse(Tablero &tablero);

};

#endif //TP2_AIRE_H
