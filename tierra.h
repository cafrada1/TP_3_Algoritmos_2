//
// Created by franco on 24/11/20.
//

#ifndef TP2_TIERRA_H
#define TP2_TIERRA_H

#include "personaje.h"
#include "Tablero.h"
class Tierra : public Personaje {

private:
    Tablero tablero;
    const int COSTO_ENERGIA_ATAQUE = 6;
    const int MINIMO_ENERGIA_DEFENSA = 5;
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
    Tierra(unsigned int vida, std::string nombre, unsigned int escudo, unsigned int energia, std::string tipo, int posicion, Tablero tablero);


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


    void atacar(int fila, int columna);



    void defenderse();

};


#endif //TP2_TIERRA_H
