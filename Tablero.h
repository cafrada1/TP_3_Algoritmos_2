#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "casillero.h"
#include "vertice.h"
#include "grafo.h"
#include "personaje.h"

const int MAX_FILA = 8;
const int MAX_COLUMNA = 8;

class Casillero;
class personaje;
class Tablero{

protected:

        const int TABLERO[MAX_FILA][MAX_COLUMNA] = { {1,1,3,3,3,6,2,2},
                                                     {1,1,3,6,2,2,2,2},
                                                     {3,2,2,2,2,3,3,3},
                                                     {2,5,5,5,1,6,5,5},
                                                     {5,5,6,5,5,5,5,3},
                                                     {5,5,5,6,4,4,4,3},
                                                     {3,4,4,4,4,1,1,1},
                                                     {3,3,4,3,6,1,1,1}};

        Casillero *tablero[MAX_FILA][MAX_COLUMNA];



public:

    /*
     * PRE: fila, columna y el terreno a cargar en ese casillero
     * POST:
     * FUNCIONAMIENTO:
     */
    void cargar_casillero(int terreno, int fila, int columna );
    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO: caraga el tablero segun los valores cargados en la matriz TABLERO
     */
    void cargar_tablero();
    /*
     * PRE: fila, columna y el personaje a cargar en ese casillero
     * POST:
     * FUNCIONAMIENTO:
     */
    void ponerPersonaje(int fila, int columna, string personaje);
    /*
     * PRE: fila y columna
     * POST: true si esta disponible, false si no lo esta.
     * FUNCIONAMIENTO:
     */
    bool consulta_disponible(int fila, int columna);
    /*
     * PRE: fila y columna
     * POST: devuelve el nombre del personaje en ese casillero
     * FUNCIONAMIENTO:
     */
    string consulta_personaje(int fila, int columna);
    /*
     * PRE:fila, columna
     * POST:
     * FUNCIONAMIENTO: cambia el estado de disponible.
     */
    void cambiarDisponible(int fila, int columna){tablero[fila][columna]->cambiarDisponible();};
    /*
     * PRE: fila y columna
     * POST:Devuelve el equipo al que pertenece el personaje que se encuentra en esa casilla.
     * FUNCIONAMIENTO:
     */
    int consulta_equipo(int fila, int columna){return tablero[fila][columna]->getEquipo();};
    /*
     * PRE: Recibe la fila y la columna y equipo a guardar
     * POST:
     * FUNCIONAMIENTO: Desactiva defensas especiales en caso de que las haya
     */
    void guardar_equipo(int fila, int columna, int equipo){tablero[fila][columna]->setEquipo(equipo);};

    /*
     * PRE: Recibe la fila y la columna
     * POST:Devuelve el nombre del personaje que se encuentra en esa casilla
     * FUNCIONAMIENTO:
     */
    string sacarPersonaje(int fila, int columna);



    /*
     * PRE:
     * POST:Imprime por pantalla el tablero
     */
    void mostrar_tablero();

    void espacio();
    string colorIndice(char color);
    string inicioColor(char colorLetra, char colorFondo);
    void print(string palabra, char colorFondo, char colorLetra);
    char elegir_color_fondo(string terreno);
    void mostrar_casillero( char color_fondo, char color_letra, string personaje);
    void mostrar_vacio(int i);
    void mostrar_indice_fila();

    void mostrar_movimiento(Lista<Vertice<int>*> *lista);

    ~Tablero();
};

#endif // TABLERO_H_INCLUDED
