//
// Created by milagros on 30/1/21.
//

#ifndef TP_3_ALGORITMOS_2_LISTA_H
#define TP_3_ALGORITMOS_2_LISTA_H

#include "nodo.h"
#include <string>

using namespace std;

template<typename Dato>
class Lista {

private:
    Nodo<Dato>* primero;
    Nodo<Dato>* actual;

public:
    //POST: crea la lista con primero = 0, actual = 0
    Lista();

    //POST: si la lista está vacia, inserta el dato d en primero; sino lo inserta en último
    void insertar(Dato nuevoDato);

    //POST: iguala al puntero actual a la primera posicion o a 0.
    void reiniciar ( );

    // POS: devuelve true si actual no apunta a 0, sino devuelve false.
    bool haySiguiente ( );

    //PRE: haySiguiente == True.
    //POST: devuelve el elemento actual y avanza.
    Dato siguiente ( );

    //POST: devuelve true si el elemento está en la lista, o false si no está .
    bool busqueda(string nombre);

    //POST: devuelve si la lista está vacia.
    bool vacia();

    //POST: elimina todos los elementos de la lista.
    virtual ~Lista();


private:
    //PRE: 0 <= pos < cantidad de elementos dentro de la lista
    //POST: devuelve el nodo en pos.
    Nodo<Dato> * obtenerNodo(int pos);

    //PRE: 0 <= pos < cantidad de elementos dentro de la lista
    //POST: elimina al elemento en pos.
    void baja(int pos);
};

template<typename Dato>
Lista<Dato>::Lista()
{
    primero = 0;
    actual = 0;
}

template<typename Dato>
bool Lista<Dato>::vacia()
{
    return primero == 0;
}

template<typename Dato>
void Lista<Dato>::insertar(Dato nuevoDato)
{
    Nodo<Dato>* nuevo = new Nodo<Dato>(nuevoDato);
    if(vacia())
    {
        nuevo -> cambiarSiguiente(primero);
        primero = nuevo;
        reiniciar();
    }
    else
    {
        Nodo<Dato>* ultimo = primero;
        while(ultimo -> obtenerSiguiente()!= 0)
        {
            ultimo = ultimo -> obtenerSiguiente();
        }
        ultimo -> cambiarSiguiente(nuevo);
    }
}

template<typename Dato>
Nodo<Dato>* Lista<Dato>::obtenerNodo(int pos)
{
    Nodo<Dato> *aux = primero;
    for(int i = 0; i < pos; i++)
        aux = aux -> obtenerSiguiente();
    return aux;
}

template<typename Dato>
Dato Lista<Dato>::siguiente()
{
    Nodo<Dato>* aux = actual;
    actual = actual -> obtenerSiguiente();
    return aux -> obtenerDato();
}

template<typename Dato>
bool Lista<Dato>::busqueda(string nombre) {
    bool encontrado = false;
    reiniciar();
    while (haySiguiente() && ! encontrado) {
        if (siguiente() == nombre)
            encontrado = true;
    }
    return encontrado;
}

template<typename Dato>
void Lista<Dato>::baja(int pos)
{
    Nodo<Dato>* borrar;
    if (pos == 0)
    {
        borrar = primero;
        primero = primero -> obtenerSiguiente();
    }
    else
    {
        Nodo<Dato>* anterior = obtenerNodo(pos - 1);
        borrar = anterior -> obtenerSiguiente();
        Nodo<Dato>* siguiente = borrar -> obtenerSiguiente();
        anterior -> cambiarSiguiente(siguiente);
    }
    reiniciar();
    delete borrar;
}

template<typename Dato>
void Lista<Dato>::reiniciar()
{
    actual = primero;
}

template<typename Dato>
bool Lista<Dato>::haySiguiente()
{
    return (actual != 0);
}

template<typename Dato>
Lista<Dato>::~Lista()
{
    while (! vacia())
        baja(0);
}




#endif //TP_3_ALGORITMOS_2_LISTA_H
