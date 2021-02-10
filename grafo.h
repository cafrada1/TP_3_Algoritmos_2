//
// Created by franco on 6/2/21.
//

#ifndef TP_3_ALGORITMOS_2_GRAFO_H
#define TP_3_ALGORITMOS_2_GRAFO_H
#include "lista.h"

template <typename T1>
class Grafo{
private:
    Lista< Lista<T1> *> *raiz;
public:
    Grafo();
    void cargarGrafo(Lista<T1 > *lista_datos);
    void agregarVertice(T1 vertice);
};

template <typename T1>
Grafo<T1>::Grafo(){
    raiz = new Lista<Lista<T1> *>;
}
template <typename T1>
void Grafo<T1>::cargarGrafo(Lista<T1> *lista_datos) {
    for (int i = 0; i<lista_datos->obtenerLargo(); i++){
        /*L
         * ista<T1> *sublista = new Lista<T1>()
         * sublista->alta(lista_datos->buscarNodo(i));
         * raiz->(sublista);
         TODO  CAMBIAR TODO ESTO  EN AGREGAR VERTICE NO ACA
         */
    }
}

template <typename T1>
void Grafo<T1>::agregarVertice(T1 vertice){

}
#endif //TP_3_ALGORITMOS_2_GRAFO_H
