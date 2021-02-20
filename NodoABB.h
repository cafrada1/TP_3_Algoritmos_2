//
// Created by franco on 4/2/21.
//

#ifndef TP_3_ALGORITMOS_2_NODOABB_H
#define TP_3_ALGORITMOS_2_NODOABB_H

#include <iostream>
using namespace std;

template<typename T1 ,typename T2>
class NodoABB{

#pragma region ATRIBUTOS
private:
    T1 key;

    T2 value;
    NodoABB<T1, T2> *izquierdo = nullptr;
    NodoABB<T1, T2> *derecho = nullptr;
    NodoABB<T1, T2> *padre = nullptr;

#pragma endregion

#pragma region METODOS
public:

#pragma region CONSTRUCTOR
    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Constructor por default de NodoABB.
     */
    NodoABB();

    /*
     *  PRE:
     *      key: no debe ser un valor ya existente como key.
     *      value: debe ser un puntero a una direccion de memoria valido.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Setea los atributos key y value a los pasados por parametro.
     */
    NodoABB(T1 key, T2 value);

#pragma endregion

#pragma region SETTERS
    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Setea el atributo key al valor pasado como parametro.
     */
    void setKey(T1 key);

    /*
     *  PRE: -
     *
     *  POST:
     *      Si value esta contiene un valor anterior no libera la memoria del valor anterior.
     *
     *  Descripcion:
     *      Setea el atributo value al valor pasado como parametro.
     */
    void setValue(T2 value);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Setea el atributo *derecho al valor pasado como parametro.
     */
    void setDerecho(NodoABB<T1, T2> *derecho);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Setea el atributo *izquierdo al valor pasado como parametro.
     */
    void setIzquierdo(NodoABB<T1, T2> *izquierdo);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Setea el atributo *padre al valor pasado como parametro.
     */
    void setPadre(NodoABB<T1, T2> *padre);

    /*
     *  PRE: -
     *
     *  POST:
     *      Si el atributo *derecho y/o izquierdo contienen un valor no libera la memoria
     *      de este valor.
     *
     *  Descripcion:
     *      Setea los atributos *derecho e *izquierdo a nullptr.
     */
    void setHijoNuevo(NodoABB<T1, T2> *padre);

    /*
     *  PRE: 
     *      *padre: debe ser una direccion de memoria valida.
     *      *hijoNuevo : debe ser una direccion de memoria valida.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Setea el nuevo hijo del nodo padre dependiendo si debe ser
     *      hijo derecho o izquierdo.
     */
    void setHijoNuevo(NodoABB<T1, T2> *padre, NodoABB<T1, T2> *hijoNuevo);

    /*
     *  PRE: 
     *      *nodo : puntero a una direccion de memoria valida con un puntero *padre
     *          a una direccion de memoria valida.
     *
     *  POST:
     *      No elimina de memoria el valor a donde apunta *derecho e/o *izquiero.
     *
     *  Descripcion:
     *      Setea el atributo *derecho e *izquierdo a nullptr.
     */
    void quitarPadre(NodoABB<T1, T2> *nodo);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor del atributo key.
     */

#pragma endregion

#pragma region GETTERS
    T1 getKey();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor del atributo value.
     */
    T2 getValue();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor del atributo *derecho.
     */
    NodoABB<T1, T2> *getDerecho();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor del atributo *izquierdo.
     */
    NodoABB<T1, T2> *getIzquierdo();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor del atributo *padre.
     */
    NodoABB<T1, T2> *getPadre();
#pragma endregion

#pragma region TIPO DE HIJO
    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      true si *izquierdo es distinto de nullptr y *derecho es igual a nullptr
     */
    bool hijoIzquierdoUnico();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      true si *derecho es distinto de nullptr y *izquierdo es igual a nullptr
     */
    bool hijoDerechoUnico();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      true si *izquierdo y *derecgi son distintos de nullptr.
     */
    bool dosHijos();

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      true si *izquierdo es distinto son igual a nullptr.
     */
    bool esHoja();
#pragma endregion

#pragma region DESTRUCTOR
    /*
     *  PRE:
     *      el atributo value debe ser una direccion de memoria valida.
     *
     *  POST:
     *      libera la memoria del puntero value
     *
     *  Descripcion:
     *      Destructor de NodoABB aplicando delete al atributo value.
     */
    ~NodoABB();

#pragma endregion

#pragma endregion

};

#pragma region IMPLEMENTACION DE METODOS
#pragma region CONSTRUCTOR
template<typename T1, typename T2>
NodoABB<T1, T2>::NodoABB(){
}
template<typename T1, typename T2>
NodoABB<T1, T2>::NodoABB(T1 key, T2 value){
    this->key = key;
    this->value = value;
}

#pragma endregion

#pragma region SETTERS
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

template <typename T1, typename T2>
void NodoABB<T1, T2>::setHijoNuevo(NodoABB<T1, T2> *padre, NodoABB<T1, T2> *hijoNuevo){

    if (padre->hijoDerechoUnico()){
        padre->setDerecho(hijoNuevo);
    }
    else if (padre->hijoIzquierdoUnico()){
        padre->setIzquierdo(hijoNuevo);
    }
    else if (!padre->esHoja()){
        if (padre->getDerecho() == hijoNuevo->getPadre()){
            padre->setDerecho(hijoNuevo);
        }
        else{
            padre->setIzquierdo(hijoNuevo);
        }
    }
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

#pragma endregion

#pragma region GETTERS
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

#pragma endregion

#pragma region TIPO DE HIJO
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
#pragma endregion

#pragma region DESTRUCTOR
template <typename T1, typename T2>
NodoABB<T1, T2>::~NodoABB(){
    cout <<"Borrado "<< key <<endl;
    delete value;

}

#pragma endregion

#pragma endregion


#endif //TP_3_ALGORITMOS_2_NODOABB_H
