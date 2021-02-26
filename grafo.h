//
// Created by franco on 18/2/21.
//

#ifndef TP_3_ALGORITMOS_2_GRAFO_H
#define TP_3_ALGORITMOS_2_GRAFO_H

#include "lista.h"
#include "vertice.h"
#include <iostream>
#include "casillero.h"
#include <fstream>
#include <cstdlib>

using namespace std;

#pragma region CONSTANTES
const string RUTA = "datos.txt";

const string ELEMENTO_AIRE = "aire";
const string ELEMENTO_AGUA = "agua";
const string ELEMENTO_FUEGO = "fuego";
const string ELEMENTO_TIERRA = "tierra";


const string TERRENO_VOLCAN = "volcan";
const string TERRENO_MONTANIA = "montaña";
const string TERRENO_LAGO = "lago";
const string TERRENO_PRECIPICIO = "precipicio";
const string TERRENO_VACIO = "vacio";
const string TERRENO_CAMINO = "camino";


const int PESO_VACIO = 15;
const int PESO_CAMINO = 1;
const int PESO_ELEMENTO_OPUESTO = 2;
const int PESO_MISMO_ELEMENTO = 0;
const int PESO_DISTINTO_ELEMENTO = 1;

const int PESO_INFINITO = 10000;
#pragma endregion

class Grafo {

#pragma region ATRIBUTOS
private:
    Lista<Lista<Vertice<Casillero *> *> *> *raiz = nullptr;

    Lista<Casillero *> *listaCasilleros = nullptr;

    int largo = 0;

    int **matrizPesoAire = nullptr;
    int **matrizCaminoAire = nullptr;

    int **matrizPesoFuego = nullptr;
    int **matrizCaminoFuego = nullptr;

    int **matrizPesoAgua = nullptr;
    int **matrizCaminoAgua = nullptr;

    int **matrizCaminoTierra = nullptr;
    int **matrizPesoTierra = nullptr;
#pragma endregion

#pragma region METODOS

#pragma region METODOS PRIVADOS
private:

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Reserva la memoria para las matrices dependiendo el largo del grafo.
     */
    void iniciarMatrices(int **matrizPeso[], int **matrizCamino[]);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Lee el archivo añadiendo los casilleros que lee a la lista.
     *      Retorna la lista de casilleros.
     */
    Lista<Casillero *> *leer_archivo();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Asigna los casilleros de la lista al grafo estableciendo
     *      las conexiones entre estos.
     */
    void cargarGrafo();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Si verticeOrigen se encuentra en el grafo retorna la sublista en donde se encuentra.
     */
    Lista<Vertice<Casillero *> *> *buscarSublista(Vertice<Casillero *> *verticeOrigen);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Agrega el verticeDestino a la sublista de verticeOrigen si este
     *      se encuentra en el grafo sino agrega una sublista con ambos vertices
     */
    void agregarVertice(Vertice<Casillero *> *verticeOrigen, Vertice<Casillero *> *verticeDestino);

#pragma region ARMADO DE MATRICES

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la energia necesaria para que un personaje de
     *      aire vaya al casillero destono.
     */
    int calcularPesoAire(Casillero *destino);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la energia necesaria para que un personaje de
     *      tierra vaya al casillero destono.
     */
    int calcularPesoTierra(Casillero *destino);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la energia necesaria para que un personaje de
     *      fuego vaya al casillero destono.
     */
    int calcularPesoFuego(Casillero *destino);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la energia necesaria para que un personaje de
     *      agua vaya al casillero destono.
     */
    int calcularPesoAgua(Casillero *destino);

    /*
     *  PRE:
     *      El casillero destino tiene que ser accesible por el
     *      personaje.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la energia necesaria para que el personaje vaya al
     *      casillero.
     */
    int calcularPesoElemento(Casillero *destino, string elementoPersonaje);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la energia necesaria para que un personaje vaya
     *      al casillero de destino desde el de origen segun el elemento del personaje.
     *      Si el destino no es accesible desde el origen retorna un valor muy grande.
     */
    int calcularPeso(Casillero *origen, Casillero *destino, string tipo);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la matriz de casilleros correspondiente al elemento del personaje.
     */
    int **matrizCamino(string elementoPersonaje);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la matriz de energia correspondiente al elemento del personaje.
     */
    int **matrizEnergia(string elementoPersonaje);

#pragma endregion

#pragma region CAMINOS MINIMOS

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Actualiza la matriz de pesos y caminos para que tengan los valores
     *      de los caminos minimos.
     */
    void caminosMinimos(Lista<Casillero *> *lista, string elementoPersonaje, int **matrizPesos, int **matrizCaminos);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Aplica el algoritmo de floyd-warshall a la matriz de pesos y casilleros.
     */
    void algoritmoFloyd(int **matrizPesos, int **matrizCasilleros);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la matriz de casilleros correspondiente al elemento del personaje.
     */
    void encontrarCamino(int origen, int destino, int **matrizCasilleros);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Implementacion recursiva de la funcion homonima.
     */
    void obtenerCaminoMinimo(int origen, int destino, int **matrizCasilleros, Lista<Vertice<int> *> *lista);

#pragma endregion

#pragma endregion

#pragma region METODOS PUBLICOS
public:

#pragma region CONSTRUCTOR

    /*
     *  PRE: -
     *
     *  POST:
     *      Las matrices de caminos minimos y pesos quedan calculadas.
     *
     *  Descripcion:
     *      Constructor de grafo que lo carga a partir del archivo de casilleros
     *      e inicia las matrices de caminos minimos y pesos.
     */
    Grafo();

#pragma endregion

#pragma region MOSTRAR

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *     Muestra por consola las conexiones entre los casilleros.
     */
    void mostrar();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Muestra por consola la matriz pasada por parametro.
     */
    void mostrarMatriz(int **vec);

    /*
     *  PRE:
     *      lista : debe contener el numero de casillero desde el origen
     *              hasta el destino de forma ordenada respecto al camino.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Muestra por pantalla la secuencia del camino.
     */
    void mostrarCamino(Lista<Vertice<int> *> *lista);
#pragma endregion

    /*
     *  PRE:
     *      origen : numero de casillero de origen. Debe estar entre el 1 y el valor
     *               de casillero maximo.
     *      destino : numero de casillero de destino. Debe estar entre el 1 y el valor
     *               de casillero maximo.
     *      elementoPersonaje: debe ser un elemento valido que posea una matriz de
     *               de energia y de casilleros correspondiente.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor de la energia minima necesaria para ir de un casillero
     *      a otro dependiendo del elemento del personaje.
     */
    int energiaNecesaria(int origen, int destino, string elementoPersonaje);

    /*
     *  PRE:
     *      origen: numero del casillero de origen.
     *      destino: numero del casillero de destino.
     *      elementoPersonaje: elemento valido para un personaje.
     *
     *  POST:
     *      La lista esta ordenada respecto al camino minimo.
     *
     *  Descripcion:
     *      Retorna la lista de numeros de casilleros del camino minimo entre el origen y el
     *      destino.
     */
    Lista<Vertice<int> *> *obtenerCaminoMinimo(int origen, int destino, string elementoPersonaje);

#pragma region DESTRUCTOR

    /*
     *  PRE: -
     *
     *  POST:
     *      Libera de memoria todas las matrices y la lista de casilleros.
     *
     *  Descripcion:
     *      Destructor de grafo.
     */
    ~Grafo();

#pragma endregion

#pragma endregion

#pragma endregion

};


#endif //TP_3_ALGORITMOS_2_GRAFO_H
