//
// Created by milagros on 29/1/21.
//

#ifndef TP_3_ALGORITMOS_2_PARTIDA_H
#define TP_3_ALGORITMOS_2_PARTIDA_H

#include "diccionario.h"
#include "lista.h"
#include <fstream>

const string NOMBRE_ARCHIVO = "../partida.csv";
const int CANTIDAD_PERSONAJES = 6;

using namespace std;

class Partida {

public:

    //PRE: diccPersonajes debe tener nodos con los personajes.
    //POST: muestra los detalles del personaje deseado.
    void buscarPersonaje(Diccionario<string, Personaje*> &diccPersonajes);

    //PRE: diccionario jugador y lista repetidos ya creados.
    //POST: si el personaje no esta repetido, lo guarda en el diccionario del personaje que corresponda.
    void seleccionarPersonaje(Diccionario<string, Personaje*> &diccPersonajes, Diccionario<string, Personaje*> &jugador, Lista<string> *repetidos);

    virtual ~Partida() = default;

private:

    //PRE: guarda el personaje elegido en el diccionario
    void guardarPersonaje(Diccionario<string, Personaje*> &diccPersonajes, Diccionario<string, Personaje*> &jugador, string nombre);

    string pedirNombre(Diccionario<string, Personaje*> &diccPersonajes);

};


#endif //TP_3_ALGORITMOS_2_PARTIDA_H
