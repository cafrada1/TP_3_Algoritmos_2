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

const string RUTA="datos.txt";

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


class Grafo{
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

    void iniciarMatrices(int **matrizPeso[], int **matrizCamino[]);

    Lista<Casillero *> *leer_archivo();

    Lista<Casillero *> *cargarGrafo();

    Lista<Vertice<Casillero *> *> *buscarSublista(Vertice<Casillero *> * vertice_origin);

    void agregarVertice(Vertice<Casillero *> * vertice_origen, Vertice<Casillero *> * vertice_destino);


    int calcularPesoAire( Casillero *destino);
    int calcularPesoTierra( Casillero *destino);
    int calcularPesoFuego( Casillero *destino);
    int calcularPesoAgua( Casillero *destino);
    int calcularPesoElemento(Casillero *destino, string elementoPersonaje);
    int calcularPeso(Casillero *origen, Casillero *destino, string tipo);

    int **matrizCamino(string elementoPersonaje);
    int **matrizEnergia(string elementoPersonaje);

    void caminosMinimos(Lista<Casillero *> *lista, string elementoPersonaje, int **matrizPesos, int **matrizCaminos);
    void algoritmoFloyd(int **matrizPesos, int **matrizCasilleros);

    void encontrarCamino(int origen, int destino, int **vector_palabras);

    void obtenerCaminoMinimo(int origen, int destino, int **matrizCasilleros, Lista<Vertice<int> *> *lista);

public:

    Grafo();

    void mostrar();

    void mostrarMatriz(int **vec);

    void mostrarCamino(Lista<Vertice<int> *> *lista);

    int energiaNecesaria(int origen, int destino, string elementoPersonaje);

    Lista<Vertice<int> *> *obtenerCaminoMinimo(int origen, int destino, string elementoPersonaje);

    ~Grafo();
};



#endif //TP_3_ALGORITMOS_2_GRAFO_H
