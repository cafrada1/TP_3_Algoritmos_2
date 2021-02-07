#include <iostream>
#include "diccionario.h"
#include "NodoABB.h"
#include "personaje.h"
#include "fuego.h"
int main() {

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


    delete mi_dicc;
    return 0;
}
