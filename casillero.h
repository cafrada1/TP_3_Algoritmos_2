//
// Created by franco on 8/2/21.
//

#ifndef TP_3_ALGORITMOS_2_CASILLERO_H
#define TP_3_ALGORITMOS_2_CASILLERO_H

#include <iostream>

using namespace std;

class Casillero {

#pragma region ATRIBUTOS

private:
    int posX = 0;
    int posY = 0;
    string tipoTerreno = "";
    bool disponible = true;
    int numero = 0;
    int equipo;
    string personaje = "nadie";
#pragma endregion

#pragma region METODOS

public:

#pragma region CONSTRUCTOR

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Contructor de la clase.
     */
    Casillero() = default;

    /*
     *  PRE:
     *      X : coordenada x del casillero. Debe ser mayor o igual a 0.
     *      Y : coordenada y del casillero. Debe ser matoy o igual a 0.
     *      terreno : palabra clave del tipo de terreno del casillero.
     *      numeroCasillero : numero mayor a 0 que identifica el casillero.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Contructor de la clase seteando sus atributos con valores dados por el
     *      usuario.
     */
    Casillero(int x, int y, string terreno, int numeroCasillero);

#pragma endregion

#pragma region SETTERS

    /*
     *  PRE:
     *      x : numero mayor o igual a 0.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Setea el atributo posX al valor pasado como parametro.
     */
    void setX(int x);

    /*
     *  PRE:
     *      y : numero mayor o igual a 0.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Setea el atributo posy al valor pasado como parametro.
     */
    void setY(int y);

    /*
     *  PRE:
     *      tipo : palabra clave sobre el tipo de terreno del casillero.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Setea el atributo tipoTerreno al valor pasado como parametro.
     */
    void setTerreno(string tipo);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Si disponible es true lo cambia a false y si es false lo cambia a true.
     */
    void cambiarDisponible();


    /*
     *  PRE: personaje : nombre del personaje que está en el casillero.
     *
     *  POST: -
     *
     *  Descripcion:
     *      pone el nombre del personaje en la casilla
     */
    void ponerPersonaje(string nuevo_personaje){personaje = nuevo_personaje;};

    /*
     *  PRE: personaje : nombre del equipo del personaje.
     *
     *  POST: -
     *
     *  Descripcion:
     *      pone el nombre del equipo del personaje en la casilla
     */
    void setEquipo(int nuevo_equipo){equipo = nuevo_equipo;};

#pragma endregion

#pragma region GETTERS

    /*
    *  PRE: -
     *
    *  POST: -
     *
    *  Descripcion:
    *      Retorna el valor de tipoTerreno.
    */
    string getTerreno();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor de disponible.
     */
    bool getDisponible();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor de posX.
     */
    int getX();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor de posY
     */
    int getY();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *       Retorna el valor del atributo equipo.
     */
    string getPersonaje(){return personaje;};

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor del atributo equipo.
     */

    int getEquipo(){return equipo;};

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor del atributo numero.
     */
    int getNumero();

    /*
     *  PRE:
     *      *casillero : direccion de memoria valida de un casillero instanciado.
     *          Los valores de posX y posY deben ser mayores a 0.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la distancia vectorial al casillero.
     */
#pragma endregion

    int distancia(Casillero *casillero);

    /*
     *  PRE: -
     *
     *  POST:
     *      No realiza un salto de linea.
     *
     *  Descripcion:
     *      Muestra por consola el valor de los atributos del casillero.
     */
    void mostrar();

#pragma endregion

};


#endif //TP_3_ALGORITMOS_2_CASILLERO_H
