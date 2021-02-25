//
// Created by franco on 11/11/20.
//

#ifndef TP2_PERSONAJE_H
#define TP2_PERSONAJE_H


#include <string>
#include <iostream>
#include "Tablero.h"

using namespace std;



class Tablero;
class Personaje {
protected:
    // Atributos


    int vida;

    unsigned int escudo;

    unsigned int energia;

    int posicion;

    int equipo;

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



    void cambiarEscudo(int cambio_escudo);

    /*
     * PRE: -
     * POST: Muestra por pantalla el contenido de los atributos de personaje.
     * FUNCIONAMIENTO: -
     */
    void mostrarDatos();


    int obtenerPosicion(){return posicion;};



    void setPosicion(int nuevaPosicion){ posicion = nuevaPosicion;};


    void setEquipo(int numero_equipo){equipo = numero_equipo;};



    /*
     * PRE: -
     * POST: ---------------------------
     * FUNCIONAMIENTO: -
     */
    virtual void defenderse() = 0;


    virtual bool validarEnergia() = 0;

    virtual void objetivos(Tablero &tablero, string objetivos[]) = 0;

    virtual int calculo_ataque(int posicion, string elemento, int defensa) = 0;



    /*void mostrarEnemigo(Diccionario<string,Personaje*>* personajes, string nombre){
        personajes->traer(nombre)->mostrarDatos();
    };*/

    /*
     * PRE: -
     * POST: -
     * FUNCIONAMIENTO: -
     */
    virtual ~Personaje() = default;
};

#endif //TP2_PERSONAJE_H
