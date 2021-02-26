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
     * FUNCIONAMIENTO: defiende al personaje aumentando 10 puntos su vida.
     */
    void defenderse(Tablero &tablero);
};


#endif //TP2_FUEGO_H
