//
// Created by milagros on 28/1/21.
//

#ifndef TP_3_ALGORITMOS_2_PARTIDA_H
#define TP_3_ALGORITMOS_2_PARTIDA_H

#include "diccionario.h"
#include "lista.h"
#include <fstream>

const string NOMBRE_ARCHIVO = "../partida.csv";

using namespace std;

class Partida {

private:
    Diccionario<string, Personaje*> * diccPersonajes;

public:
    //POST: asigna el diccionario d al diccionario diccPersonajes
    Partida(Diccionario<string,Personaje*> * d);

    //PRE: diccionario de jugador debe contener personajes. 0 < num <=2
    //POST: crea un archivo csv con la informacion de los personajes del jugador.
    void guardarPartida(Diccionario<string, Personaje*> * jugador, int num/*,int columna, int fila*/);

    //PRE: diccPersonajes debe tener nodos con los personajes.
    //POST: muestra los detalles del personaje deseado.
    void buscarPersonaje();

    void mostrarNombres();

    //PRE: diccionario jugador y lista repetidos ya creados.
    //POST: si el personaje no esta repetido, lo guarda en el diccionario del personaje que corresponda.
    void seleccionarPersonaje(Diccionario<string, Personaje*> * jugador, Lista<string>* repetidos);

    virtual ~Partida();

private:

    //PRE: guarda el personaje elegido en el diccionario
    void guardarPersonaje(Diccionario<string, Personaje*> * jugador, string nombre);

    string pedirNombre();

};


#endif //TP_3_ALGORITMOS_2_PARTIDA_H
