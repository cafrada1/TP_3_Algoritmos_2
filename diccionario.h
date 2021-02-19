//
// Created by franco on 31/1/21.
//

#ifndef TP_3_ALGORITMOS_2_DICCIONARIO_H
#define TP_3_ALGORITMOS_2_DICCIONARIO_H

#include "personaje.h"
#include "NodoABB.h"
#include "fuego.h"

using namespace std;

template <typename T1, typename T2>

class Diccionario{

private:
    NodoABB<T1 , T2> *raiz;

public:
    Diccionario();

    NodoABB<T1 , T2> *getRaiz();

    NodoABB<T1 , T2> *agregarNodo(NodoABB<T1 , T2> *nodo_nuevo, T1 key, T2 personaje);

    void agregarPersonaje(T1 key, T2 personaje);

    NodoABB<T1 , T2> *buscar(NodoABB<T1 , T2> *nodo, T1 key);

    bool buscar(T1 key);

    void mostrarOrdenados(NodoABB<T1 , T2> *nodo);

    void mostrarOrdenados();

    NodoABB<T1 , T2> *encuentraMinimo(NodoABB<T1 , T2> *nodo);

    void quitarRaiz();

    void quitarNodo( NodoABB<T1 , T2> *nodo);

    void quitarNodo(T1 key);


    void quitarHoja(NodoABB<T1 , T2> *nodo);
    
    void quitarHijoDerecho(NodoABB<T1 , T2> *nodo);
    
    void quitarHijoIzquierdo(NodoABB<T1 , T2> *nodo);
    
    void quitarDosHijos(NodoABB<T1 , T2> *nodo);

    void limpiar();

    bool vacio();


    ~Diccionario();
};

template<typename T1, typename T2>
Diccionario<T1, T2>::Diccionario() {
    raiz = nullptr;
}

template<typename T1, typename T2>
NodoABB<T1 , T2> *Diccionario<T1, T2>::agregarNodo(NodoABB<T1 , T2> *nodo, T1 key, T2 personaje) {

    if (nodo == nullptr){
        nodo = new NodoABB<T1 , T2>(key,personaje);
        return nodo;
    }
    else if (nodo->getKey() > key){
        nodo->setIzquierdo(agregarNodo(nodo->getIzquierdo(), key, personaje));
        nodo->getIzquierdo()->setPadre(nodo);
    }
    else {
        nodo->setDerecho(agregarNodo(nodo->getDerecho(), key, personaje));
        nodo->getDerecho()->setPadre(nodo);
    }
    return nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::agregarPersonaje(T1 key, T2 personaje) {

    raiz = agregarNodo(raiz,key,personaje);

}

template<typename T1, typename T2>
NodoABB<T1 , T2> *Diccionario<T1, T2>::buscar(NodoABB<T1 , T2> *nodo, T1 key){
    if (nodo == nullptr || key == nodo->getKey()){
        return nodo;
    }
    else if (nodo->getKey() > key){
        return buscar(nodo->getIzquierdo(),key);
    }
    return buscar(nodo->getDerecho(), key);
}

template<typename T1, typename T2>
bool Diccionario<T1, T2>::buscar(T1 key) {
    NodoABB<T1 , T2> *encontrado = buscar(raiz, key);

    return (encontrado != nullptr);
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::mostrarOrdenados(NodoABB<T1 , T2> *nodo) {
    if (nodo != nullptr){
        mostrarOrdenados(nodo->getIzquierdo());
        //nodo->getValue()->mostrarDatos();
        cout<<nodo->getKey()<<endl;
        mostrarOrdenados(nodo->getDerecho());
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::mostrarOrdenados() {
    mostrarOrdenados(raiz);
}

template<typename T1, typename T2>
NodoABB<T1 , T2> *Diccionario<T1, T2>::getRaiz() {
    return raiz;
}

template<typename T1, typename T2>
NodoABB<T1 , T2> *Diccionario<T1, T2>::encuentraMinimo(NodoABB<T1 , T2> *nodo) {
    if (nodo->getDerecho() != nullptr){
        return encuentraMinimo(nodo->getDerecho());
    }
    return nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarRaiz() {
    if (raiz->dosHijos()){
        quitarDosHijos(raiz);
    }
    else{
        NodoABB< T1 , T2> *aux = raiz;
        if (raiz->esHoja()){
            raiz = nullptr;
        }
        else if (raiz->hijoDerechoUnico()){
            raiz = raiz->getDerecho();
        }
        else if (raiz->hijoIzquierdoUnico()){
            raiz = raiz->getIzquierdo();
        }
        delete aux;
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarHoja(NodoABB<T1 , T2> *nodo){
    if (nodo == nodo->getPadre()->getIzquierdo()){
        nodo->getPadre()->setIzquierdo(nullptr);
    }
    else{
        nodo->getPadre()->setDerecho(nullptr);
    }
    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarHijoDerecho(NodoABB<T1 , T2> *nodo){

    nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getDerecho());
    nodo->getDerecho()->setPadre(nodo->getPadre());

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarHijoIzquierdo(NodoABB<T1 , T2> *nodo){

    nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getDerecho());
    nodo->getIzquierdo()->setPadre(nodo->getPadre());

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarDosHijos(NodoABB<T1 , T2> *nodo){
    NodoABB<T1 , T2> *nodo_predecesor = encuentraMinimo(nodo->getIzquierdo());
    T2 aux_value = nodo->getValue();
    T1 aux_key = nodo->getKey();

    nodo->setValue(nodo_predecesor->getValue());
    nodo->setKey(nodo_predecesor->getKey());

    nodo_predecesor->setValue(aux_value);
    nodo_predecesor->setKey(aux_key);

    if (nodo_predecesor->getIzquierdo() != nullptr){

        nodo_predecesor->getPadre()->setHijoNuevo(nodo_predecesor->getPadre(), nodo_predecesor->getIzquierdo());
        nodo_predecesor->getIzquierdo()->setPadre(nodo_predecesor->getPadre());
    }
    else{
        nodo_predecesor->quitarPadre(nodo_predecesor);

    }

    delete nodo_predecesor;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodo(NodoABB<T1 , T2> *nodo) {
    if (nodo == raiz){
        quitarRaiz();
    }
    else if (nodo->esHoja()) {
        quitarHoja(nodo);
    }

    else if (nodo->hijoDerechoUnico()){
        quitarHijoDerecho(nodo);
    }

    else if (nodo->hijoIzquierdoUnico()){
        quitarHijoIzquierdo(nodo);
    }

    else{
        quitarDosHijos(nodo);
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodo(T1 key) {
    NodoABB<T1, T2> *nodo = buscar(raiz, key);
    quitarNodo(nodo);
}

template<typename T1, typename T2>
bool Diccionario<T1, T2>::vacio(){
    return (raiz == nullptr);
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::limpiar() {
    while (!vacio()){
        quitarRaiz();
    }
}

template<typename T1, typename T2>
Diccionario<T1, T2>::~Diccionario(){
    limpiar();
};

#endif //TP_3_ALGORITMOS_2_DICCIONARIO_H
