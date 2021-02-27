#include <iostream>
#include "diccionario.h"
#include "Tablero.h"
#include "lista.h"
#include "vertice.h"
#include <fstream>
#include <cstdlib>
#include <stdio.h>

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
    string jugador1[CANTIDAD_PERSONAJES];
    string jugador2[CANTIDAD_PERSONAJES];
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

    /*
     *  PRE: -
     *  POST: -
     *  Descripcion:
     *      Muestra los detalles del personaje deseado.
     */
    void buscarPersonaje();

    /*
     *  PRE: -
     *  POST: -
     *  Descripcion:
     *      Agrega en los vectores jugador1 y jugador2 los personajes elegidos.
     */
    void seleccionarPersonajes();

    /*
     *  PRE: Personajes ya seleccionados y posicionados. 0 < contador <=2.
     *  POST: -
     *  Descripcion:
     *      Comienza la partida de juego. Finaliza cuando uno de los dos jugadores tiene vida = 0.
     */
    void comienzoJuego(int contador);

    /*
     *  PRE: 0 < num <=2
     *  POST: -
     *  Descripcion:
     *      Crea un csv con los datos de la partida jugada.
     */
    void guardarPartida(string jugador[], int num);

    /*
     *  PRE: El archivo debe existir.
     *  POST: -
     *  Descripcion:
     *      Lee los datos de la partida guardada.
     */
    void leerPartida();

    void moverPersonaje(string nombre);

    ~Menu();

private:

    string pedirNombre();
    /*
     *  PRE: -
     *  POST: -
     *  Descripcion:
     *      Si el elemento no es válido, le pide al usuario que lo vuelva a ingresar hasta que lo sea
     */
    void validar_elemento(string &elemento);

    //PRE: La opcion es de tipo int
    //POS: Devuelve true si la opcion se encuentra entre 1 y 6; false en caso contrario
    bool validar_opcion(int opcion, int minimo, int maximo);

    void validar_datos(string &elemento);

    void cargar_atributos_personaje(Personaje* &nuevo_personaje,int vida,string nombre,int escudo,int energia,string tipo);

    /*
     *  PRE: -
     *  POST: devuelve true si existe el archivo partida.csv, false en caso contrario.
     *  Descripcion:
     *      Cheque la existencia de archivo partida.csv.
     */
    bool existePartida();
    /*
     *  PRE: -
     *  POST: si el personaje no esta repetido, devuelve el nombre.
     *  Descripcion:
     *
     */
    string chequeaRepetido(string repetidos[]);

    /*
     *  PRE: -
     *  POST: devuelve true si esta repetido, false en caso contrario.
     *  Descripcion:
     *      Chequea si el personaje elegido no fue elegido anteriormente.
     */
    bool estaRepetido(std::string nombre, std::string repetidos[]);

    /*
     *  PRE: -
     *  POST: devuelve la cantidad de vida total de los personajes del jugador.
     *  Descripcion:
     *
     */
    int contadorVida(string jugador[]);

    void imprimirTurno(int num);

    /*
     *  PRE: -
     *  POST: -
     *  Descripcion:
     *      Muestra un sub-menu con opciones alimentar o mover el personaje.
     */
    void primerasOpcInternas(string nombre);

    /*
     *  PRE: -
     *  POST: -
     *  Descripcion:
     *      Muestra un sub-menu secundario con opciones atacar o defender.
     */
    void segundasOpcInternas(string nombre, string jugador[]);
    /*
     *  PRE: contador de turnos
     *  POST: -
     *  Descripcion:
     *      Posiciona a los personajes dependiendo de los turnos
     */
    void posicionarPersonajes(int contador);
    /*
     *  PRE: numero de jugar que le toca, y el nombre del personaje que se va a posicionar
     *  POST: -
     *  Descripcion:
     *      Posiciona a los personajes dependiendo de los turnos
     */
    void ponerPersonaje(string personaje, int numeroJugador);
    /*
     *  PRE:  nombre del personaje que va a realizar el ataque
     *  POST: -
     *  Descripcion:
     *      realiza el ataque
     */
    void atacar(string nombre);
    /*
     *  PRE:  nombre del personaje que va a realizar el ataque y vector de nombres del equipo del jugador que se defiende
     *  POST: -
     *  Descripcion:
     *      realiza la defensa del personaje
     */
    void defenderse(string nombre, string jugador[]);
    /*
     *  PRE:
     *  POST: -
     *  Descripcion:
     *      imprime por pantalla un mensaje de bienvenida.
     */
    void bienvenida();

    /*
     *  PRE: -
     *  POST: devuelve un string con la opcion elegida.
     *  Descripcion:
     *
     */
    string opcionGuardar();

    /*
     *  PRE: El archivo debe existir.
     *  POST: -
     *  Descripcion:
     *      Procesa cada linea del archivo csv.
     */
    string procesarLinea(string linea);

    /*
     *  PRE: -
     *  POST: -
     *  Descripcion:
     *      Modifica los datos del diccionario creado a partir de personajes.csv
     *      con los datos de partida.csv.
     */
    void modificarDatos(string nombre,int vida, int escudo, int energia, int numeroCasilla);

    /*
     *  PRE: -
     *  POST: devuelve un numero entero.
     *  Descripcion:
     *      Decide al azar quien comienza la partida.
     */
    int asignarTurno();

};



#endif
