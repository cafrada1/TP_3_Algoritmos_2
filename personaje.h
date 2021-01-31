//
// Created by franco on 11/11/20.
//

#ifndef TP2_PERSONAJE_H
#define TP2_PERSONAJE_H

#include <string>
#include <iostream>

using namespace std;

class Personaje {
private:
    // Atributos

    unsigned int vida;

    unsigned int escudo;

    unsigned int energia;

    string nombre;

    string tipo;

public:
    // Metodos

    /*
     * PRE: vida, escudo y energia deben estar entre los rangos validos.
     *
     * POST: asigna los atributos al personaje.
     *
     * FUNCIONAMIENTO: -
     *
     * */
    Personaje(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo);

    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO: -
     */
    virtual void alimentarse() = 0;

    /*
     * PRE: -
     *
     * POST: Devuelve la vida actual del personaje
     *
     * FUNCIONAMIENTO: -
     */
    unsigned int obtenerVida();

    /*
     * PRE: -
     *
     * POST: Devuelve la energia actual del personaje
     *
     * FUNCIONAMIENTO: -
     */
    unsigned int obtenerEnergia();

    /*
     * PRE: -
     *
     * POST: Devuelve el escudo actual del personaje
     *
     * FUNCIONAMIENTO: -
     */
    unsigned int obtenerEscudo();

    /*
     * PRE: -
     *
     * POST: Devuelve el nombre del personaje
     *
     * FUNCIONAMIENTO: -
     */
    string obtenerNombre();

    /*
     * PRE: -
     *
     * POST: Devuelve el elemento del pesonaje
     *
     * FUNCIONAMIENTO: -
     */
    string obtenerTipo();

    /*
     * PRE: -
     * POST: suma el valor aumento_vida a la vida actual del personaje.
     * FUNCIONAMIENTO: -
     */
    void cambiarVida(int aumento_vida);

    /*
     * PRE: -
     * POST: suma el valor aumento_energia a la energia actual del personaje.
     * FUNCIONAMIENTO: -
     */
    void cambiarEnergia(int aumento_energia);

    /*
     * PRE: -
     * POST: Muestra por pantalla el contenido de los atributos de personaje.
     * FUNCIONAMIENTO: -
     */
    void mostrarDatos();

    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO: -
     */
    virtual ~Personaje() = default;
};

#endif //TP2_PERSONAJE_H
