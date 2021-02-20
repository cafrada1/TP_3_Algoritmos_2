//
// Created by franco on 15/11/20.
//

#ifndef TP2_LISTA_H
#define TP2_LISTA_H

#include <string>
#include "nodo.h"
#include <iostream>

using namespace std;

template<typename Dato>
class Lista {
private:
    Nodo<Dato> *primero;
    int largo;

public:
    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     */
    Lista();

    /*
     * PRE: -
     *
     * POST: Setea el valor de siguiente al hasta entonces ultimo elemento con el valor del
     *  nuevo ultimo elemento.
     *
     * FUNCIONAMIENTO: agrega al final de la lista el elemento .
     */
    void alta(Dato elemento_agregar);

    /*
     * PRE: -
     *
     * POST: Devuelve la cantidad de elementos que contiene la lista.
     *
     * FUNCIONAMIENTO: -
     */
    int obtenerLargo();

    /*
     * PRE: -
     *
     * POST: devuelve el dato del elemento encontrado y si no lo encuentra devuelve
     * un puntero nulo. Si en la lista hay mas de una coincidencia devuelve la primera.
     *
     * FUNCIONAMIENTO: -
     * */
    Dato buscarElemento(string nombre);

    /*
     * PRE: posicion mayor a 0 y menor al largo de la lista.
     * POST: -
     * FUNCIONAMIENTO: elimina el elemento de la posicion pasada y apunta el anterior al eliminado
     *                  al siguiente de la lista.
     */
    void baja(int posicion);

    /*
     * PRE: -
     * POST: Devuelve si la lista tiene elementos.
     * FUNCIONAMIENTO: -
     */
    bool listaVacia();

    /*
     * PRE: -
     *
     * POST: Muestra la informacion de los elementos  de la lista con su respectiva posicion.
     *
     * FUNCIONAMIENTO: -
     */
    void mostrarLista();

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     */
    Nodo<Dato> *buscarNodo(int posicion);

    Nodo<Dato> *buscarNodo(Dato valor);

    ~Lista();
};


template<typename Dato>
Lista<Dato>::Lista() {

    primero = nullptr;

    largo = 0;
}

template<typename Dato>
int Lista<Dato>::obtenerLargo() {
    return largo;
}

template<typename Dato>
bool Lista<Dato>::listaVacia() {
    return largo == 0;
}


template<typename Dato>
void Lista<Dato>::alta(Dato elemento_agregar) {
    Nodo<Dato> *nuevo_nodo = new Nodo<Dato>(elemento_agregar);

    if (largo == 0) {
        primero = nuevo_nodo;
    } else {
        buscarNodo(largo)->asignarSiguiente(nuevo_nodo);
    }

    largo++;
}


template<typename Dato>
Dato Lista<Dato>::buscarElemento(string nombre) {

    Nodo<Dato> *actual = primero;

    while (actual != nullptr && actual->obtenerDato()->obtenerNombre() != nombre) {
        actual = actual->obtenerSiguiente();
    }

    if (!actual) {
        return nullptr;
    }
    return actual->obtenerDato();
}

template<typename Dato>
void Lista<Dato>::baja(int posicion) {

    Nodo<Dato> *nodo_aux = buscarNodo(posicion);

    if (posicion == 1) {
        primero = nodo_aux->obtenerSiguiente();

    } else {
        Nodo<Dato> *nodo_anterior = buscarNodo(posicion - 1);

        nodo_anterior->asignarSiguiente(nodo_aux->obtenerSiguiente());
    }

    largo--;

    delete nodo_aux;
}

template<typename Dato>
void Lista<Dato>::mostrarLista() {

    if (largo == 0) {
        cout << "\nLa lista esta vacia\n" << endl;
    } else {
        for (int i = 1; i <= largo; i++) {
            Dato elemento = buscarNodo(i)->obtenerDato();
            cout << "\n--------------------" << endl;
            cout << "Elemento Nº" << i << ": " << endl;
            elemento->mostrarDatos();
        }
        cout << "--------------------" << endl;
    }
}

template<typename Dato>
Nodo<Dato> *Lista<Dato>::buscarNodo(int posicion) {
    if (listaVacia() || posicion > largo) {
        return nullptr;
    }

    Nodo<Dato> *buscado = primero;

    for (int i = 1; i < posicion; i++) {
        buscado = buscado->obtenerSiguiente();
    }

    return buscado;
}

template<typename Dato>
Nodo<Dato> *Lista<Dato>::buscarNodo(Dato valor) {
    if (listaVacia()) {
        return nullptr;
    }

    Nodo<Dato> *buscado = primero;
    int i = 0;
    while ((buscado->obtenerDato() != valor) && (i<largo)) {
        buscado = buscado->obtenerSiguiente();
        i++;
    }
    if (buscado->obtenerDato() != valor){
        return nullptr;
    }

    return buscado;
}

template<typename Dato>
Lista<Dato>::~Lista() {
    while (!listaVacia()) {
        baja(1);
    }
}

#endif //TP2_LISTA_H
