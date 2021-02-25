//
// Created by milagros on 30/1/21.
//

#ifndef PART2TP_NODOABB_H
#define PART2TP_NODOABB_H
#include <iostream>
using namespace std;

template<typename T1 ,typename T2>
class NodoABB{
private:
    T1 key;
    T2 value;
    NodoABB<T1, T2> *izquierdo = nullptr;
    NodoABB<T1, T2> *derecho = nullptr;
    NodoABB<T1, T2> *padre = nullptr;

public:
    NodoABB();
    NodoABB(T1 key, T2 value);

    void setKey(T1 key);
    void setNodo(T1 key, T2 value);
    void setValue(T2 value);

    void setDerecho(NodoABB<T1, T2> *derecho);
    void setIzquierdo(NodoABB<T1, T2> *izquierdo);
    void setPadre(NodoABB<T1, T2> *padre);

    void setHijoNuevo(NodoABB<T1, T2> *padre);
    void setHijoNuevo(NodoABB<T1, T2> *padre, NodoABB<T1, T2> *hijo_nuevo);
    void quitarPadre(NodoABB<T1, T2> *nodo);

    T1 getKey();
    T2 getValue();
    NodoABB<T1, T2> *getDerecho();
    NodoABB<T1, T2> *getIzquierdo();

    NodoABB<T1, T2> *getPadre();
    bool hijoIzquierdoUnico();
    bool hijoDerechoUnico();
    bool dosHijos();

    bool esHoja();
    ~NodoABB();
};

template<typename T1, typename T2>
NodoABB<T1, T2>::NodoABB(){
}
template<typename T1, typename T2>
NodoABB<T1, T2>::NodoABB(T1 key, T2 value){
    this->key = key;
    this->value = value;
}

template<typename T1, typename T2>
void NodoABB<T1, T2>::setKey(T1 key){
    this->key = key;
}

template<typename T1, typename T2>
void NodoABB<T1, T2>::setValue(T2 value){
    this->value = value;
}

template<typename T1, typename T2>
void NodoABB<T1, T2>::setIzquierdo(NodoABB<T1, T2> *izquierdo ){
    this->izquierdo = izquierdo;
}
template<typename T1, typename T2>
void NodoABB<T1, T2>::setDerecho(NodoABB<T1, T2> *derecho ){
    this->derecho = derecho;
}

template<typename T1, typename T2>
void NodoABB<T1, T2>::setPadre(NodoABB<T1, T2> *padre ){
    this->padre = padre;
}

template<typename T1, typename T2>
NodoABB<T1, T2>  *NodoABB<T1, T2>::getIzquierdo(){
    return izquierdo;
}

template<typename T1, typename T2>
NodoABB<T1, T2> *NodoABB<T1, T2>::getDerecho(){
    return derecho;
}

template<typename T1, typename T2>
NodoABB<T1, T2> *NodoABB<T1, T2>::getPadre(){
    return  padre;
}

template<typename T1, typename T2>
T1 NodoABB<T1, T2>::getKey() {
    return  key;
}

template<typename T1, typename T2>
T2 NodoABB<T1, T2>::getValue(){
    return  value;
}

template<typename T1, typename T2>
bool NodoABB<T1, T2>::hijoIzquierdoUnico() {
    return ((izquierdo != nullptr) && (derecho == nullptr));
}

template<typename T1, typename T2>
bool NodoABB<T1, T2>::hijoDerechoUnico() {
    return ((izquierdo == nullptr) && (derecho != nullptr));
}

template<typename T1, typename T2>
bool NodoABB<T1, T2>::esHoja() {
    return ((izquierdo == nullptr) && (derecho == nullptr));

}
template<typename T1, typename T2>
bool NodoABB<T1, T2>::dosHijos() {
    return ((izquierdo != nullptr) && (derecho != nullptr));

}

template <typename T1, typename T2>
void NodoABB<T1, T2>::setHijoNuevo(NodoABB<T1, T2> *padre){
    padre->setDerecho(nullptr);
    padre->setIzquierdo(nullptr);
}

template <typename T1, typename T2>
void NodoABB<T1, T2>::quitarPadre(NodoABB<T1, T2> *nodo) {

    if (nodo == nodo->getPadre()->getDerecho()){
        nodo->getPadre()->setDerecho(nullptr);
    }
    else{
        nodo->getPadre()->setIzquierdo(nullptr);
    }
}
template <typename T1, typename T2>
void NodoABB<T1, T2>::setHijoNuevo(NodoABB<T1, T2> *padre, NodoABB<T1, T2> *hijo_nuevo){

    if (padre->hijoDerechoUnico()){
            padre->setDerecho(hijo_nuevo);
        }
    else if (padre->hijoIzquierdoUnico()){
        padre->setIzquierdo(hijo_nuevo);
    }
    else if (!padre->esHoja()){
        if (padre->getDerecho() == hijo_nuevo->getPadre()){
            padre->setDerecho(hijo_nuevo);
        }
        else{
            padre->setIzquierdo(hijo_nuevo);
        }
    }
}

template <typename T1, typename T2>
NodoABB<T1, T2>::~NodoABB(){
    cout <<"Borrado "<< key <<endl;
    delete value;

}
#endif //PART2TP_NODOABB_H
