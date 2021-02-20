#include <iostream>
#include "diccionario.h"
#include "NodoABB.h"
#include "personaje.h"
#include "fuego.h"
#include "casillero.h"
#include "vertice.h"
#include "grafo.h"

int main() {

#pragma region PRUEBA DICCIONARIO
    /*
    Diccionario<string, Personaje*> *mi_dicc = new Diccionario<string, Personaje *>();
    int vida = 100;
    int escudo = 1;
    int energia = 15;
    string tipo = "fuego";
    string nombre = "ariadna";
    nombre = "juan";
    Personaje *mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre,mi_personaje);
    nombre = "fa";
    mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre, mi_personaje);
    nombre = "da";
    mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre, mi_personaje);
    nombre = "de";
    mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre, mi_personaje);


    nombre = "daaa";
    mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre, mi_personaje);
    nombre = "ga";
    mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre, mi_personaje);


    mi_dicc->mostrarOrdenados();

    mi_dicc->quitarNodo("fa");

    delete mi_dicc;
     */

#pragma endregion

#pragma region PRUEBA GRAFO
    Grafo *mi_grafo = new Grafo();


    mi_grafo->mostrar();


    Lista<Vertice<int> *> *lista = mi_grafo->obtenerCaminoMinimo(1,5,"fuego");

    mi_grafo->mostrarCamino(lista);

    delete lista;
    delete mi_grafo;
#pragma endregion
    return 0;
}
