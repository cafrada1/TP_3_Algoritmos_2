//
// Created by franco on 31/1/21.
//

#ifndef TP_3_ALGORITMOS_2_DICCIONARIO_H
#define TP_3_ALGORITMOS_2_DICCIONARIO_H

//QUITE EL INCLUDE DE PERSONAJE.H Y FUEGO.H
#include "NodoABB.h"

using namespace std;

template<typename T1, typename T2>
class Diccionario {

#pragma region ATRIBUTOS

private:
    NodoABB<T1, T2> *raiz;

#pragma endregion


#pragma region METODOS
#pragma region METODOS PRIVADOS

private:

    /*
     *  PRE:
     *      nodo : direccion de memoria valida.
     *      key : valor no existente como key de otro nodo.
     *
     *  POST:
     *      Si el diccionario no esta vacio setea el padre del nodo agregado.
     *
     *  Descripcion:
     *      Inserta al diccionario un nuevo nodo con los valores pasados por parametro.
     */
    NodoABB<T1, T2> *agregarNodo(NodoABB<T1, T2> *nodo, T1 key, T2 personaje);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la direccion del nodo con la misma key que la pasada por parametro
     *      si esta se encuentra en el diccionario.
     *      Retorna nullptr si el elemento no se encuentra en el diccionario.
     */
    NodoABB<T1, T2> *buscar(NodoABB<T1, T2> *nodo, T1 key);

    /*
     *  PRE: -
     *
     *  POST:
     *      Realiza un salto de linea al mostrar una key.
     *
     *  Descripcion:
     *      Si nodo no es nulltpr:
     *        1) Se llama recursivamente pasando como parametro a su hijo izquierdo.
     *        2) Muestra por pantalla la key del nodo.
     *        3) Se llama recursivamente pasando como parametro a su hijo derecho
     */
    void mostrarOrdenados(NodoABB<T1, T2> *nodo);

#pragma region QUITAR NODOS

    /*
     *  PRE:
     *      *nodo : debe ser una direccion de memoria valida.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Llama a la funcion correspondiente para eliminar el nodo
     *      dependiendo del tipo de nodo.
     */
    void quitarNodo(NodoABB<T1, T2> *nodo);

    /*
     *  PRE:
     *      *nodo debe contener un *padre con direccion de memoria valida.
     *      *nodo debe contener un *izquierdo con direccion de memoria valida.
     *
     *  POST:
     *      Libera la memoria ocupada por *nodo.
     *
     *  Descripcion:
     *      Elimina el nodo pasado como parametro.
     *      Conecta al nodo padre de nodo con su nodo hijo izquierdo.
     */
    void quitarHijoIzquierdo(NodoABB<T1, T2> *nodo);

    /*
     *  PRE:
     *      *nodo debe contener un *padre con direccion de memoria valida.
     *      *nodo debe contener un *derecho con direccion de memoria valida.
     *
     *  POST:
     *      Libera la memoria ocupada por *nodo.
     *
     *  Descripcion:
     *      Conecta al nodo padre de nodo con su nodo hijo derecho.
     */
    void quitarHijoDerecho(NodoABB<T1, T2> *nodo);

    /*
     *  PRE:
     *      *nodo debe contener un *padre con direccion de memoria valida.
     *
     *  POST:
     *      Libera la memoria ocupada por *nodo.
     *
     *  Descripcion:
     *      Elimina el nodo pasado como parametro.
     *      Coloca en nullptr al atributo *izquierdo o *derecho del padre del nodo
     *      dependiendo de si este es hijo izquierdo o derecho respectivamente.
     */
    void quitarHoja(NodoABB<T1, T2> *nodo);

    /*
     *  PRE:
     *      *nodo debe contener un *padre con direccion de memoria valida.
     *      *nodo debe contener un *izquierdo con direccion de memoria valida.
     *      *nodo debe contener un *derecho con direccion de memoria valida.
     *
     *  POST:
     *      Libera la memoria ocupada por *nodo.
     *
     *  Descripcion:
     *      Elimina el nodo pasado como parametro.
     *      Conecta al nodo padre con el nodo sucesor.
     */
    void quitarDosHijos(NodoABB<T1, T2> *nodo);

    /*
     *  PRE: -
     *
     *  POST:
     *      Libera la memoria ocupada por la raiz.
     *      Setea raiz a nullptr.
     *
     *  Descripcion:
     *      Elimina la raiz del diccionario.
     */
    void quitarRaiz();

    /*
     *  PRE:
     *      *nodo : debe ser una direccion de memoria valida.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el predecesor del nodo.
     */
    NodoABB<T1, T2> *encuentraMinimo(NodoABB<T1, T2> *nodo);

    /*
     *  PRE: -
     *
     *  POST:
     *      Libera la memoria de los nodos del diccionario.
     *      Setea raiz en nullptr.
     *
     *  Descripcion:
     *      Elimina todos los nodos del diccionario.
     */
    void limpiar();

#pragma endregion

#pragma endregion


#pragma region METODOS PUBLICOS
public:

#pragma region CONSTRUCTOR

    /*
     *  PRE: -
     *
     *  POST: Setea raiz en nullptr.
     *
     *  Descripcion:
     *      Constructor de diccionario.
     */
    Diccionario();

#pragma endregion

    /*
     *  PRE:
     *      key no debe estar en el diccionario.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Agrega un nodo al diccionario con key como key y personaje como value.
     */
    void agregarPersonaje(T1 key, T2 personaje);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna true si la key se encuentra en el diccionario.
     *      Retorna false si la key no se encuentra en el diccionario
     */
    bool buscar(T1 key);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Muestra de menor a mayor las key del diccionario.
     */
    void mostrarOrdenados();

    /*
     *  PRE: -
     *
     *  POST:
     *      No libera la memoria de nodo.
     *
     *  Descripcion:
     *      Elimina el nodo que contenga la key pasada como parametros si esta
     *      se encuentra en el diccionario.
     */
    void quitarNodo(T1 key);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna true si raiz es nullptr.
     *      Retorna false si raiz es distinta de nullptr.
     */
    bool vacio();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor de value si la key se encuentra en el diccionario.
     *      Retorna nullptr si la key no se encuentra.
     */
    T2 traer(T1 key);


#pragma region DESTRUCTOR

    /*
     *  PRE: -
     *
     *  POST:
     *      Libera la memoria de los nodos del diccionario.
     *
     *  Descripcion:
     *      Destructor de diccionario.
     *      ELimina todos los nodos .
     */
    ~Diccionario();

#pragma endregion

#pragma endregion

#pragma endregion

};

#pragma region IMPLEMENTACION DE METODOS

template<typename T1, typename T2>
Diccionario<T1, T2>::Diccionario() {
    raiz = nullptr;
}

template<typename T1, typename T2>
NodoABB<T1, T2> *Diccionario<T1, T2>::agregarNodo(NodoABB<T1, T2> *nodo, T1 key, T2 personaje) {

    if (nodo == nullptr) {
        nodo = new NodoABB<T1, T2>(key, personaje);
        return nodo;
    } else if (nodo->getKey() > key) {
        nodo->setIzquierdo(agregarNodo(nodo->getIzquierdo(), key, personaje));
        nodo->getIzquierdo()->setPadre(nodo);
    } else {
        nodo->setDerecho(agregarNodo(nodo->getDerecho(), key, personaje));
        nodo->getDerecho()->setPadre(nodo);
    }
    return nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::agregarPersonaje(T1 key, T2 personaje) {

    raiz = agregarNodo(raiz, key, personaje);

}

template<typename T1, typename T2>
NodoABB<T1, T2> *Diccionario<T1, T2>::buscar(NodoABB<T1, T2> *nodo, T1 key) {
    if (nodo == nullptr || key == nodo->getKey()) {
        return nodo;
    } else if (nodo->getKey() > key) {
        return buscar(nodo->getIzquierdo(), key);
    }
    return buscar(nodo->getDerecho(), key);
}

template<typename T1, typename T2>
bool Diccionario<T1, T2>::buscar(T1 key) {
    NodoABB<T1, T2> *encontrado = buscar(raiz, key);

    return (encontrado != nullptr);
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::mostrarOrdenados(NodoABB<T1, T2> *nodo) {
    if (nodo != nullptr) {
        mostrarOrdenados(nodo->getIzquierdo());
        cout << nodo->getKey() << endl;
        mostrarOrdenados(nodo->getDerecho());
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::mostrarOrdenados() {
    mostrarOrdenados(raiz);
}


template<typename T1, typename T2>
NodoABB<T1, T2> *Diccionario<T1, T2>::encuentraMinimo(NodoABB<T1, T2> *nodo) {
    if (nodo->getDerecho() != nullptr) {
        return encuentraMinimo(nodo->getDerecho());
    }
    return nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarRaiz() {
    if (raiz->dosHijos()) {
        quitarDosHijos(raiz);
    } else {
        NodoABB<T1, T2> *aux = raiz;
        if (raiz->esHoja()) {
            raiz = nullptr;
        } else if (raiz->hijoDerechoUnico()) {
            raiz = raiz->getDerecho();
        } else if (raiz->hijoIzquierdoUnico()) {
            raiz = raiz->getIzquierdo();
        }
        delete aux;
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarHoja(NodoABB<T1, T2> *nodo) {
    if (nodo == nodo->getPadre()->getIzquierdo()) {
        nodo->getPadre()->setIzquierdo(nullptr);
    } else {
        nodo->getPadre()->setDerecho(nullptr);
    }
    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarHijoDerecho(NodoABB<T1, T2> *nodo) {

    nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getDerecho());
    nodo->getDerecho()->setPadre(nodo->getPadre());

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarHijoIzquierdo(NodoABB<T1, T2> *nodo) {

    nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getDerecho());
    nodo->getIzquierdo()->setPadre(nodo->getPadre());

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarDosHijos(NodoABB<T1, T2> *nodo) {
    NodoABB<T1, T2> *nodo_predecesor = encuentraMinimo(nodo->getIzquierdo());
    T2 aux_value = nodo->getValue();
    T1 aux_key = nodo->getKey();

    nodo->setValue(nodo_predecesor->getValue());
    nodo->setKey(nodo_predecesor->getKey());

    nodo_predecesor->setValue(aux_value);
    nodo_predecesor->setKey(aux_key);

    if (nodo_predecesor->getIzquierdo() != nullptr) {

        nodo_predecesor->getPadre()->setHijoNuevo(nodo_predecesor->getPadre(), nodo_predecesor->getIzquierdo());
        nodo_predecesor->getIzquierdo()->setPadre(nodo_predecesor->getPadre());
    } else {
        nodo_predecesor->quitarPadre(nodo_predecesor);

    }

    delete nodo_predecesor;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodo(NodoABB<T1, T2> *nodo) {
    if (nodo == raiz) {
        quitarRaiz();
    } else if (nodo->esHoja()) {
        quitarHoja(nodo);
    } else if (nodo->hijoDerechoUnico()) {
        quitarHijoDerecho(nodo);
    } else if (nodo->hijoIzquierdoUnico()) {
        quitarHijoIzquierdo(nodo);
    } else {
        quitarDosHijos(nodo);
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodo(T1 key) {
    NodoABB<T1, T2> *nodo = buscar(raiz, key);
    quitarNodo(nodo);
}

template<typename T1, typename T2>
bool Diccionario<T1, T2>::vacio() {
    return (raiz == nullptr);
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::limpiar() {
    while (!vacio()) {
        quitarRaiz();
    }
}

template<typename T1, typename T2>
T2 Diccionario<T1,T2>::traer(T1 key){
    if(buscar(key)){
        return buscar(raiz,key)->getValue();
    }
    return nullptr;
}

template<typename T1, typename T2>
Diccionario<T1, T2>::~Diccionario() {
    limpiar();
};

#pragma endregion

#endif //TP_3_ALGORITMOS_2_DICCIONARIO_H
