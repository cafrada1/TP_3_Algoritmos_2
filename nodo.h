//
// Created by milagros on 30/1/21.
//

#ifndef TP_3_ALGORITMOS_2_NODO_H
#define TP_3_ALGORITMOS_2_NODO_H

template<typename Dato>

class Nodo {
private:
    Dato elemento;
    Nodo<Dato> * siguiente;

public:

    //POST: crea un nodo con dato = nuevo_elemento y siguiente = 0
    Nodo(Dato nuevoElemento);

    void cambiarSiguiente(Nodo<Dato> * sig);

    //POST: devuelve el nodo siguiente.
    Nodo<Dato> * obtenerSiguiente();

    //POST: devuelve al elemento datos
    Dato obtenerDato();

};

template<typename Dato>
Nodo<Dato>::Nodo(Dato nuevoElemento){
    elemento = nuevoElemento;
    siguiente = 0;
}

template<typename Dato>
void Nodo<Dato>::cambiarSiguiente(Nodo<Dato> * sig) {
    siguiente = sig;
}

template<typename Dato>
Nodo<Dato>* Nodo<Dato>::obtenerSiguiente() {
    return siguiente;
}

template<typename Dato>
Dato Nodo<Dato>::obtenerDato() {
    return elemento;
}


#endif //TP_3_ALGORITMOS_2_NODO_H
