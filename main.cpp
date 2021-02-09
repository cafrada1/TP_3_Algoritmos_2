#include <iostream>
#include "diccionario.h"
#include "NodoABB.h"
#include "personaje.h"
#include "fuego.h"
#include "grafo.h"
#include "casillero.h"
int main() {

    /*Diccionario<string, Personaje*> *mi_dicc = new Diccionario<string, Personaje *>();
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

    Grafo<Vertice<Casillero *> *> *mi_grafo = new Grafo<Vertice<Casillero *> *>;

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

    Lista<Casillero *> *lista = mi_grafo->cargarGrafo();

    mi_grafo->mostrar();

    delete mi_grafo;
    delete lista;
    return 0;
}
