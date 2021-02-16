//
// Created by franco on 24/11/20.
//

#ifndef TP2_AGUA_H
#define TP2_AGUA_H

#include "Personaje.h"
#include "tablero.h"

class Agua : public Personaje{

    // Atributos
private:

    int cantidad_alimentado = 0;
    unsigned int COSTO_ENERGIA_ATAQUE = 5;
    int MINIMO_ENERGIA_DEFENSA = 12;
    int DEBILIDAD_TIERRA = -10;
    int FORTALEZA_FUEGO = -30;
    int ATAQUE = -20;
    int DEFENSA_PERSONAL = 50;
    int DEFENSA_EQUIPO = 10;

    //Metodos
public:
    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     */
    Agua(unsigned int vida, std::string nombre, unsigned int escudo, unsigned int energia, std::string tipo, int posicion, Tablero tablero);

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




    void atacar(int fila, int columna);



    void defenderse();

};

#endif //TP2_AGUA_H
