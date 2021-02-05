//
// Created by franco on 31/1/21.
//
#include "diccionario.h"
#include "fuego.h"
#include <string>
Diccionario::Diccionario() {
    raiz = nullptr;
}

NodoABB<string , Personaje *> *Diccionario::agregarNodo(NodoABB<string , Personaje *> *nodo, Personaje *personaje) {

    if (nodo == nullptr){
        nodo = new NodoABB<string , Personaje *>(personaje->obtenerNombre(),personaje );
        return nodo;
    }
    else if (nodo->getKey() > personaje->obtenerNombre()){
        nodo->setIzquierdo(agregarNodo(nodo->getIzquierdo(),personaje));
        nodo->getIzquierdo()->setPadre(nodo);
    }
    else {
        nodo->setDerecho(agregarNodo(nodo->getDerecho(),personaje));
        nodo->getDerecho()->setPadre(nodo);
    }
    return nodo;
}

void Diccionario::agregarPersonaje(Personaje *personaje) {

    raiz = agregarNodo(raiz,personaje);

}

NodoABB<string , Personaje *> *Diccionario::buscar(NodoABB<string , Personaje *> *nodo, string nombre){
    if (nodo == nullptr || nombre == nodo->getValue()->obtenerNombre()){
        return nodo;
    }
    else if (nodo->getValue()->obtenerNombre() > nombre){
        return buscar(nodo->getIzquierdo(),nombre);
    }
    return buscar(nodo->getDerecho(), nombre);
}

bool Diccionario::buscar(string nombre) {
    NodoABB<string , Personaje *> *encontrado = buscar(raiz, nombre);

    return encontrado != nullptr;
}

void Diccionario::mostrarOrdenados(NodoABB<string , Personaje *> *nodo) {
    if (nodo != nullptr){
        mostrarOrdenados(nodo->getIzquierdo());
        //nodo->getValue()->mostrarDatos();
        cout << nodo->getValue()->obtenerNombre()<<" | ";
        mostrarOrdenados(nodo->getDerecho());
    }
}

void Diccionario::mostrarOrdenados() {
    mostrarOrdenados(raiz);
}

NodoABB<string , Personaje *> *Diccionario::getRaiz() {
    return raiz;
}

NodoABB<string , Personaje *> *Diccionario::encuentraMinimo(NodoABB<string , Personaje *> *nodo) {
    if (nodo->getDerecho() != nullptr){
        return encuentraMinimo(nodo->getDerecho());
    }
    return nodo;
}


void Diccionario::quitarNodo(string nombre) {
    NodoABB<string, Personaje *> *nodo = buscar(raiz, nombre);
    quitarNodo(nodo);
}

void Diccionario::quitarNodo(NodoABB<string , Personaje *> *nodo) {
    if (nodo->esHoja()) {
        if (nodo == getRaiz()){
            raiz = nullptr;
            delete nodo;
        }
        else{
           if (nodo->getPadre() != nullptr) {
               nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nullptr);
           }
           else{
               raiz = nullptr;
           }
           delete nodo;
        }
    }

    else if (nodo->hijoDerechoUnico()){
        if (nodo->getPadre() != nullptr) {
            nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getDerecho());
            nodo->getDerecho()->setPadre(nodo->getPadre());
        }
        else{
            raiz = nodo->getDerecho();
            raiz->setPadre(nullptr);
        }
        delete nodo;
    }

    else if (nodo->hijoIzquierdoUnico()){
        if (nodo->getPadre() != nullptr) {
            nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getDerecho());
            nodo->getIzquierdo()->setPadre(nodo->getPadre());
        }
        else{
            raiz = nodo->getIzquierdo();
            raiz->setPadre(nullptr);
        }
        delete nodo;
    }

    else{
        NodoABB<string , Personaje *> *nodo_predecesor = encuentraMinimo(nodo->getIzquierdo());
        Personaje * aux = nodo->getValue();
        nodo->setValue(nodo_predecesor->getValue());
        nodo->setKey(nodo_predecesor->getKey());
        if (nodo->getIzquierdo() == nodo_predecesor) {
            nodo->setIzquierdo(nullptr);
        }
        else{
            nodo_predecesor->getPadre()->setDerecho(nullptr);
        }
        nodo_predecesor->setValue(aux);
        delete nodo_predecesor;

    }
}

bool Diccionario::vacio(){
    return (raiz == nullptr);
}

void Diccionario::limpiar() {
    while (!vacio()){
        quitarNodo(raiz);
    }
}


Diccionario::~Diccionario(){
    limpiar();
};
