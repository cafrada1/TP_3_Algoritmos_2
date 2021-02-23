#include <iostream>
#include "personaje.h"
#include "diccionario.h"
#include "NodoABB.h"
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"
#include "menu.h"

using namespace std;

int main() {

	//if existe partida, cargar la partida

	//borrar la partida sería un método de partida? guardarla tambien?
	srand(time(0));

    Diccionario<string, Personaje*> *personajes = new Diccionario<string, Personaje *>();

    Menu menu_principal;

    personajes->mostrarOrdenados();

    menu_principal.elegir_opcion(*personajes);

    /*
    Personaje *personaje1 = new Fuego(100, "charmander", 1, 15, "agua");
    personajes->agregarPersonaje("charmander", personaje1);

    Personaje *personaje2 = new Agua(100, "squirtle", 1, 15, "agua");
    personajes->agregarPersonaje("squirtle", personaje2);

    Personaje *personaje3 = new Tierra(100, "toph", 1, 15, "tierra");
    personajes->agregarPersonaje("toph", personaje3);

    Personaje *personaje4 = new Aire(100, "aang", 1, 15, "aire");
    personajes->agregarPersonaje("aang", personaje4);

    Personaje *personaje5 = new Tierra(100, "solomon", 1, 15, "tierra");
    personajes->agregarPersonaje("solomon", personaje5);

    Personaje *personaje6 = new Fuego(100, "zuko", 1, 15, "fuego");
    personajes->agregarPersonaje("zuko", personaje6);

    Personaje *personaje7 = new Aire(100, "appa", 1, 15, "aire");
    personajes->agregarPersonaje("appa", personaje7);

    Personaje *personaje8 = new Agua(100, "katara", 1, 15, "agua");
    personajes->agregarPersonaje("katara", personaje8);

    Personaje *personaje9 = new Fuego(100, "ozai", 1, 15, "fuego");
    personajes->agregarPersonaje("ozai", personaje9);

    Personaje *personaje10 = new Tierra(100, "gaara", 1, 15, "tierra");
    personajes->agregarPersonaje("gaara", personaje10);

    Personaje *personaje11 = new Aire(100, "momo", 1, 15, "aire");
    personajes->agregarPersonaje("momo", personaje11);

    personajes->mostrarOrdenados();
    */

    //Personaje *p1 = personajes->traer("aang");

    //cout << "Nombre: " << p1->obtenerNombre() << endl;
    //cout << "Elemento: " << p1->obtenerTipo() << endl;
    //cout << "Vida: " << p1->obtenerVida() << endl;
    //cout << "Escudo: " << p1->obtenerEscudo() << endl;
    //cout << "Energía: " << p1->obtenerEnergia() << endl;


    delete personajes;
    return 0;
}
