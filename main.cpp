#include <iostream>
#include "diccionario.h"
#include "NodoABB.h"
#include "personaje.h"
#include "fuego.h"
#include "casillero.h"
#include "vertice.h"
#include "grafo.h"
int main() {

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

    delete mi_dicc;*/

    Grafo *mi_grafo = new Grafo();

    /*Lista<Casillero *> *lista_origen = new Lista<Casillero *>;
    Casillero *cas_1_1 = new Casillero(1,1,'m');
    Casillero *cas_1_2 = new Casillero(1,2,'m');
    Casillero *cas_1_3 = new Casillero(1,3,'m');
    Casillero *cas_2_2 = new Casillero(2,2,'m');
    Casillero *cas_2_1 = new Casillero(2,1,'m');
    lista_origen->alta( cas_1_1);
    lista_origen->alta( cas_1_1);
    lista_origen->alta( cas_1_2);
    lista_origen->alta( cas_1_2);
    lista_origen->alta( cas_1_2);

    Lista<Casillero *> *lista_destino = new Lista<Casillero *>;
    lista_destino->alta( cas_1_2);
    lista_destino->alta( cas_2_1);
    lista_destino->alta( cas_1_1);
    lista_destino->alta( cas_2_2);
    lista_destino->alta( cas_1_3);*/


    mi_grafo->mostrar();


    Lista<Vertice<int> *> *lista = mi_grafo->obtenerCaminoMinimo(1,5,"fuego");

    mi_grafo->mostrarCamino(lista);

    delete lista;
    delete mi_grafo;

    return 0;

}
