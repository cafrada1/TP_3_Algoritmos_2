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
    Tierra(int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo);


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
     * FUNCIONAMIENTO: defiende al personaje aumentando 2 puntos su defensa por un turno.
     */
    void defenderse(Tablero &tablero);

};


#endif //TP2_TIERRA_H
