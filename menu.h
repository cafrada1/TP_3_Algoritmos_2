#include <iostream>
#include "diccionario.h"
#include "Tablero.h"
#include "lista.h"
#include <fstream>
#include <cstdlib>

const string NOMBRE_ARCHIVO = "../partida.csv";
const int CANTIDAD_PERSONAJES = 3;
const int CANTIDAD_JUGADORES = 2;

using namespace std;

#ifndef MENU_H_
#define MENU_H_

class Menu{

private:
    Diccionario<string,Personaje*>* personajes;
    Tablero tablero;
public:
    Menu();

    //PRE:
    //POS: Muestra las opciones del menú
    void mostrar_menu();

    //PRE:
    //POS:
    void elegir_opcion();

    //PRE: La opcion es de tipo int
    //POS:
    int ingresar_opcion();

    void procesar_opcion(int opcion, bool &continuar);

    //PRE:
    //POS:
    void pedir_datos_personaje(string &elemento, string &nombre);

    //PRE:
    //POS: Agrega un nuevo personaje a la lista
    void agregar_nuevo_personaje();

    //PRE: El nombre del personaje se encuentra en la lista
    //POS: Elimina al personaje de la lista
    void eliminar_personaje(string nombre);

    //PRE: El personaje se encuentra en la lista
    //POS: Devuelve la posicion del prsonaje en la lista
    int buscar_personaje(string nombre);

    //PRE:
    //POS: Muestra los nombres de todos los personajes de la lista
    void mostrar_nombres_personajes();

    //PRE: El personaje se encuentra en la lista
    //POS : Muestra los datos del personaje pedido
    void mostrar_datos_personaje(string nombre);

    //PRE: El personaje se encuentra en la lista
    //POS: Alimenta al personaje pedido
    void alimentar_personaje(string nombre);

    //PRE:
    //POS: Verifica si el personaje se encuentra o no en la lista
    bool esta_en_el_diccionario(string nombre);

    void comenzar_juego();

    void mostrar_menu_2();

    //PRE: diccPersonajes debe tener nodos con los personajes.
    //POST: muestra los detalles del personaje deseado.
    void buscarPersonaje();

    void seleccionarPersonajes(string jugador1[], string jugador2[]);

    void comienzoJuego();

    void guardarPartida(string jugador[], int num);

    ~Menu();
private:

    string pedirNombre();

    //PRE:
    //POS: Si el elemento no es válido, le pide al usuario que lo vuelva a ingresar hasta que lo sea
    void validar_elemento(string &elemento);

    //PRE: La opcion es de tipo int
    //POS: Devuelve true si la opcion se encuentra entre 1 y 6; false en caso contrario
    bool validar_opcion(int opcion, int minimo, int maximo);

    void validar_datos(string &elemento);

    void cargar_atributos_personaje(Personaje* &nuevo_personaje,int vida,string nombre,int escudo,int energia,string tipo);


    //PRE:
    //POST: devuelve true si existe el archivo partida.csv, false en caso contrario.
    bool existePartida();

    //PRE:
    //POST: si el personaje no esta repetido, devuelve el nombre.
    string chequeaRepetido(string repetidos[]);

    bool estaRepetido(std::string nombre, std::string repetidos[]);

    //PRE:
    //POST: devuelve la cantidad de vida total de los personajes del jugador.
    int contadorVida(string jugador[]);

    void imprimirTurno(int num);

    void primerasOpcInternas(string nombre);

    void segundasOpcInternas(string nombre);

    string eleccionPersonaje(string jugador[]);


    void posicionarPersonajes(int contador, string jugador1[], string jugador2[]);

    void ponerPersonaje(string personaje, int numeroJugador);


    void atacar(string nombre);

    void cargarPartida();

    string opcionGuardar();
};



#endif