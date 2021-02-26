//
// Created by franco on 24/11/20.
//

#ifndef TP2_AGUA_H
#define TP2_AGUA_H

#include "personaje.h"

class Agua : public Personaje {

    // Atributos
private:
    int cantidad_alimentado = 0;
    int COSTO_ENERGIA_ATAQUE = 5;
    int COSTO_ENERGIA_DEFENSA = 12;
    int DEBILIDAD_TIERRA = -10;
    int FORTALEZA_FUEGO = -30;
    int ATAQUE = -20;
    int DEFENSA_PERSONAL = 50;
    int DEFENSA_EQUIPO = 10;
    std::string elemento_debilidad = "tiera";
    std::string elemento_fortaleza = "fuego";
    //Metodos
public:
    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     */
    Agua(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo);

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
     * FUNCIONAMIENTO: defiende al personaje aumentando 50 puntos su vida.
     */
    void defenderse(Tablero &tablero);

};

#endif //TP2_AGUA_H
