//
// Created by franco on 6/2/21.
//

#ifndef TP_3_ALGORITMOS_2_GRAFO_H
#define TP_3_ALGORITMOS_2_GRAFO_H
#include "lista.h"
#include "vertice.h"

template <typename T1>
class Grafo{
private:
    Lista<Lista<T1> *> *raiz;
public:
    Grafo();
    void cargarGrafo(Lista<T1> *lista_origenes , Lista<T1> *lista_destinos );
    void agregarVertice(T1 vertice_origen, T1 vertice_destino);
    Lista<T1> *buscarSublista(T1 vertice_origin);
    void mostrar();
    Lista<Lista<T1> *> *caminosMinimos(T1 inicio, T1 fin);
    ~Grafo();
};

template <typename T1>
Grafo<T1>::Grafo(){
    raiz = new Lista<Lista<T1> *>;
}
template <typename T1>
void Grafo<T1>::cargarGrafo(Lista<T1> *lista_origenes , Lista<T1> *lista_destinos ) {
    for (int i = 0; i<lista_destinos->obtenerLargo(); i++){

        agregarVertice(lista_origenes->buscarNodo(i+1)->obtenerDato(),
                       lista_destinos->buscarNodo(i+1)->obtenerDato());
        agregarVertice(lista_destinos->buscarNodo(i+1)->obtenerDato(),
                       lista_origenes->buscarNodo(i+1)->obtenerDato());

        /*
         * Lista<T1> *sublista = new Lista<T1>()
         * sublista->alta(lista_datos->buscarNodo(i));
         * raiz->(sublista);
         TODO  CAMBIAR TODO ESTO  EN AGREGAR VERTICE NO ACA
         */
    }
}

template <typename T1>
Lista<T1> *Grafo<T1>::buscarSublista(T1 vertice_origen) {
    if (raiz->obtenerLargo() == 0){
        return nullptr;
    }

    Lista<T1> *sublista = raiz->buscarNodo(raiz->obtenerLargo())->obtenerDato();
    Nodo<T1> *nodo  = sublista->buscarNodo(sublista->obtenerLargo());
    int i = 2;
    while ((nodo->obtenerDato()->getValue() != vertice_origen->getValue()) && (i <= raiz->obtenerLargo())){
        sublista = raiz->buscarNodo(i)->obtenerDato();
        nodo = sublista->buscarNodo(sublista->obtenerLargo());
        i++;
    }
    if (nodo->obtenerDato()->getValue() != vertice_origen->getValue()){
        return nullptr;
    }
    return sublista;
}

template <typename T1>
void Grafo<T1>::agregarVertice(T1 vertice_origen, T1 vertice_destino){

    Lista<T1> *sublista = buscarSublista(vertice_origen);
    if (sublista != nullptr){
        sublista->alta(vertice_destino);
    }
    else{
        sublista = new Lista<T1>();
        sublista->alta(vertice_origen);
        sublista->alta(vertice_destino);
        raiz->alta(sublista);
    }
}

template <typename T1>
void Grafo<T1>::mostrar(){
    Lista<T1> *sublista = nullptr;

    for (int i = 0; i<raiz->obtenerLargo(); i++){
        sublista = raiz->buscarNodo(i+1)->obtenerDato();
        cout << sublista->buscarNodo(sublista->obtenerLargo())->obtenerDato()->getValue() <<" -> ";
        for (int j = 1; j<sublista->obtenerLargo()-1; j++){
            cout << sublista->buscarNodo(j)->obtenerDato()->getValue() << "-> ";
        }
        cout << sublista->buscarNodo(sublista->obtenerLargo()-1)->obtenerDato()->getValue() <<endl;
    }
}


template <typename T1>
Lista<Lista<T1> *> *Grafo<T1>::caminosMinimos(T1 inicio, T1 fin) {


    inicio->setAcumulado(inicio->getPeso());
    Lista<T1> *sublista = buscarSublista(inicio);
    T1 actual = inicio;
    T1 siguiente = inicio;

    for (int i = 0; i< inicio->sublista->obtenerLargo(); i++ ){

        siguiente =  sublista->buscarNodo(i+1)->obtenerDato();

        siguiente->setAnterior(actual);

        siguiente->setAcumulado(actual->getAcumulado()+siguiente->getPeso());


    }



}

template <typename T1>
Grafo<T1>::~Grafo() {
    if (raiz!= nullptr){
        delete raiz;
    }
}




#endif //TP_3_ALGORITMOS_2_GRAFO_H
