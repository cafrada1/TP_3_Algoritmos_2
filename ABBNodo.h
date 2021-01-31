//
// Created by franco on 31/1/21.
//

#ifndef TP_3_ALGORITMOS_2_ABBNodo_H
#define TP_3_ALGORITMOS_2_ABBNodo_H

template<typename Dato>
class NodoABB{
private:
    Dato valor;
    NodoABB<Dato> *izquierdo;
    NodoABB<Dato> *derecho;
    NodoABB<Dato> *padre;

public:
    NodoABB(Dato valor);

    void setValor(Dato valor);
    void setDerecho(NodoABB<Dato> *derecho);
    void setIzquierdo(NodoABB<Dato> *izquierdo);
    void setPadre(NodoABB<Dato> *padre);

    Dato getValor();
    NodoABB<Dato> *getDerecho();
    NodoABB<Dato> *getIzquierdo();
    NodoABB<Dato> *getPadre();

    bool esHijoIzquierdoUnico();
    bool esHijoDerechoUnico();
    bool esHoja();

};

template<typename Dato>
NodoABB<Dato>::NodoABB(Dato valor){
    this->valor = valor;
    derecho = nullptr;
    padre = nullptr;
    izquierdo = nullptr;
}

template<typename Dato>
void NodoABB<Dato>::setValor(Dato valor){
    this->valor = valor;
}

template<typename Dato>
void NodoABB<Dato>::setIzquierdo(NodoABB<Dato> *izquierdo ){
    this->izquierdo = izquierdo;
}

template<typename Dato>
void NodoABB<Dato>::setDerecho(NodoABB<Dato> *derecho ){
    this->derecho = derecho;
}

template<typename Dato>
void NodoABB<Dato>::setPadre(NodoABB<Dato> *Padre ){
    this->padre = padre;
}

template<typename Dato>
NodoABB<Dato>  *NodoABB<Dato>::getIzquierdo(){
    return izquierdo;
}

template<typename Dato>
NodoABB<Dato> *NodoABB<Dato>::getDerecho(){
    return derecho;
}

template<typename Dato>
NodoABB<Dato> *NodoABB<Dato>::getPadre(){
    return  padre;
}

template<typename Dato>
Dato NodoABB<Dato>::getValor(){
    return  valor;
}

template<typename Dato>
bool NodoABB<Dato>::esHijoIzquierdoUnico() {
    return (izquierdo != nullptr && derecho == nullptr);
}

template<typename Dato>
bool NodoABB<Dato>::esHijoDerechoUnico() {
    return (izquierdo == nullptr && derecho != nullptr);
}

template<typename Dato>
bool NodoABB<Dato>::esHoja() {
    return (izquierdo == nullptr && derecho == nullptr);
}
#endif //TP_3_ALGORITMOS_2_ABBNodo_H
