//
// Created by franco on 31/1/21.
//

#ifndef TP_3_ALGORITMOS_2_DICCIONARIO_H
#define TP_3_ALGORITMOS_2_DICCIONARIO_H

#include "personaje.h"
#include "NodoABB.h"
#include <string>

using namespace std;

class Diccionario{
private:
    NodoABB<string , Personaje *> *raiz;

public:
    Diccionario();

    NodoABB<string , Personaje *> *getRaiz();

    NodoABB<string , Personaje *> *agregarNodo(NodoABB<string , Personaje *> *nodo_nuevo, Personaje *nodo_viejo);

    void agregarPersonaje(Personaje *personaje);

    NodoABB<string , Personaje *> *buscar(NodoABB<string , Personaje *> *nodo, string nombre);

    bool buscar(string nombre);

    void mostrarOrdenados(NodoABB<string , Personaje *> *nodo);

    void mostrarOrdenados();

    NodoABB<string , Personaje *> *encuentraMinimo(NodoABB<string , Personaje *> *nodo);

    void quitarNodo( NodoABB<string , Personaje *> *nodo);

    void quitarNodo(string nombre);

    void limpiar();

    bool vacio();


    ~Diccionario();
};


#endif //TP_3_ALGORITMOS_2_DICCIONARIO_H
