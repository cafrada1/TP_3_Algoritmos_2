//
// Created by franco on 15/11/20.
//

#ifndef TP2_NODO_H
#define TP2_NODO_H

template<typename Dato>
class Nodo {
    //Atributos
private:
    Dato elemento;

    Nodo<Dato> *siguiente;

    //Metodos
public:
    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     */
    Nodo(Dato elemento_nuevo);

    /*
     * PRE: -
     * POST: Devuelve el contenido del nodo.
     * FUNCIONAMIENTO: -
     */
    Dato obtenerDato();


    /*
     * PRE: siguiente_nodo debe ser una direccion de memoria valida.
     * POST: asigna la direccion a siguiente
     * FUNCIONAMIENTO: -
     */
    void asignarSiguiente(Nodo<Dato> *siguiente_nodo);


    /*
     * PRE: -
     * POST: Devuelve la direccion del siguiente nodo
     * FUNCIONAMIENTO: -
     */
    Nodo<Dato> *obtenerSiguiente();

    /*
     * PRE:
     * POST:
     * FUNCIONAMIENTO:
     */
    ~Nodo();
};

template<typename Dato>
Nodo<Dato>::Nodo(Dato elemento_nuevo) {
    elemento = elemento_nuevo;
    siguiente = nullptr;
}

template<typename Dato>
Dato Nodo<Dato>::obtenerDato() {
    return elemento;
}

template<typename Dato>
Nodo<Dato> *Nodo<Dato>::obtenerSiguiente() {
    return siguiente;
}

template<typename Dato>
void Nodo<Dato>::asignarSiguiente(Nodo<Dato> *siguiente_nodo) {
    siguiente = siguiente_nodo;
}

template<typename Dato>
Nodo<Dato>::~Nodo() {
    if (elemento != nullptr){
        delete elemento;
    }
}

#endif //TP2_NODO_H
