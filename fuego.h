//
// Created by franco on 18/11/20.
//

#ifndef TP2_FUEGO_H
#define TP2_FUEGO_H

#include "Personaje.h"
#include "Tablero.h"

class Fuego : public Personaje{

private:
    Tablero tablero;
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
    Fuego(unsigned int vida,  std::string nombre, unsigned int escudo, unsigned int energia,  std::string tipo, int posicion, Tablero tablero);

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


    void atacar(int fila, int columna);



    void defenderse();
};


#endif //TP2_FUEGO_H
