#include <iostream>
#include "diccionario.h"
#include "NodoABB.h"
#include "personaje.h"
#include "fuego.h"
#include "grafo.h"
int main() {
    /*
    Diccionario<string, Personaje*> *mi_dicc = new Diccionario<string, Personaje *>();
    int vida = 100;
    int escudo = 1;
    int energia = 15;
    string tipo = "fuego";
    string nombre = "ariadna";
    nombre = "ariadna";
    Personaje *mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre,mi_personaje);
    nombre = "amiadna";
    mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre, mi_personaje);
    nombre = "juan";
    mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre, mi_personaje);
    nombre = "bruno";
    mi_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
    mi_dicc->agregarPersonaje(nombre, mi_personaje);

    mi_dicc->mostrarOrdenados();


    delete mi_dicc;*/

    Grafo<Vertice<int> *> *mi_grafo = new Grafo<Vertice<int> *>;

    Lista<Vertice<int> *> *lista_origenes  = new Lista<Vertice<int> *>;
    Lista<Vertice<int> *> *lista_destinos  = new Lista<Vertice<int> *>;
    

    int valor = 15;
    Vertice<int> *vertice = new Vertice<int>(valor, 0);
    lista_origenes->alta(vertice);
    valor = 10;
    vertice = new Vertice<int>(valor, 0);
    lista_destinos->alta(vertice);

    /*valor = 10;
    vertice = new Vertice<int>(valor, 0);
    lista_origenes->alta(vertice);
    valor = 15;
    vertice = new Vertice<int>(valor, 0);
    lista_destinos->alta(vertice);*/

    valor = 9;
    vertice = new Vertice<int>(valor, 0);
    lista_origenes->alta(vertice);
    valor = 10;
    vertice = new Vertice<int>(valor, 0);
    lista_destinos->alta(vertice);

    valor = 15;
    vertice = new Vertice<int>(valor, 0);
    lista_origenes->alta(vertice);
    valor = 9;
    vertice = new Vertice<int>(valor, 0);
    lista_destinos->alta(vertice);

    /*valor = 9;
    vertice = new Vertice<int>(valor, 0);
    lista_origenes->alta(vertice);
    valor = 15;
    vertice = new Vertice<int>(valor, 0);
    lista_destinos->alta(vertice);*/


    mi_grafo->cargarGrafo(lista_origenes, lista_destinos);
    //mi_grafo->agregarVertice(vertice1, vertice2);
    mi_grafo->mostrar();
    //mi_grafo->cargarGrafo(lista_origenes, lista_destinos);
    //mi_grafo->mostrar();
    //delete mi_grafo;

    delete mi_grafo;
    return 0;
}
