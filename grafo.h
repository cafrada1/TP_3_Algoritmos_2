//
// Created by franco on 6/2/21.
//

#ifndef TP_3_ALGORITMOS_2_GRAFO_H
#define TP_3_ALGORITMOS_2_GRAFO_H
#include "lista.h"
#include "vertice.h"
#include <iostream>
#include "casillero.h"
#include <fstream>
#include <cstdlib>

using namespace std;

const string RUTA="datos_prueba.txt";

template <typename T1>
class Grafo{
private:
    Lista<Lista<T1> *> *raiz;
public:
    Grafo();
    Lista<Casillero *> *cargarGrafo();
    void agregarVertice(T1 vertice_origen, T1 vertice_destino);
    Lista<T1> *buscarSublista(T1 vertice_origin);
    void mostrar();
    T1 minimoPeso(Lista<T1> *lista);
    Lista<Lista<T1> *> *caminosMinimos(T1 inicio, T1 fin);

    Lista<Casillero *> *leer_archivo();

    void etiquetar(Lista<T1> *lista);

    ~Grafo();
};

template <typename T1>
Grafo<T1>::Grafo(){
    raiz = new Lista<Lista<T1> *>;
}


template <typename T1>
Lista<Casillero *> *Grafo<T1>::cargarGrafo() {

    Lista<Casillero *> *lista = leer_archivo();
    Vertice<Casillero *> *vertice_origen;
    Vertice<Casillero *> *vertice_destino;

    for (int i = 0; i<lista->obtenerLargo(); i++){
        Casillero *nodo_origen = lista->buscarNodo(i+1)->obtenerDato();
        for (int j = 0; j<lista->obtenerLargo(); j++){
            if (i!=j){
                Casillero *nodo_destino = lista->buscarNodo(j+1)->obtenerDato();

                if (nodo_origen->distancia(nodo_destino) <= 1) {
                    vertice_origen = new Vertice<Casillero *>;
                    vertice_destino = new Vertice<Casillero *>;

                    vertice_origen->setValue(nodo_origen);
                    vertice_destino->setValue(nodo_destino);

                    agregarVertice(vertice_origen, vertice_destino);
                }
            }
        }
    }

        /*
         * Lista<T1> *sublista = new Lista<T1>()
         * sublista->alta(lista_datos->buscarNodo(i));
         * raiz->(sublista);
         TODO  CAMBIAR TODO ESTO  EN AGREGAR VERTICE NO ACA
         */
    return lista;
}

template <typename T1>
Lista<T1> *Grafo<T1>::buscarSublista(T1 vertice_origen) {
    if (raiz->obtenerLargo() == 0){
        return nullptr;
    }

    Lista<T1> *sublista = raiz->buscarNodo(raiz->obtenerLargo())->obtenerDato();
    Nodo<T1> *nodo  = sublista->buscarNodo(sublista->obtenerLargo());
    int i = 1;
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
        delete vertice_origen;
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
        sublista->buscarNodo(sublista->obtenerLargo())->obtenerDato()->getValue()->mostrar();
        cout<<" -> ";

        for (int j = 1; j<sublista->obtenerLargo()-1; j++){
           sublista->buscarNodo(j)->obtenerDato()->getValue()->mostrar();

            cout << "-> ";
        }

        sublista->buscarNodo(sublista->obtenerLargo()-1)->obtenerDato()->getValue()->mostrar();
        cout <<endl;
    }

}



template <typename T1>
Lista<Lista<T1> *> *Grafo<T1>::caminosMinimos(T1 inicio, T1 fin) {


    inicio->setAcumulado(0);
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

template<typename T1>
Lista<Casillero *> *Grafo<T1>::leer_archivo() {
    int x,y,peso;
    string lectura;
    string tipo;
    ifstream archivo;
    archivo.open(RUTA, ios::in);

    Lista<Casillero *> *mi_lista = new Lista<Casillero *>;
    if (archivo.fail()){
        cout << "Que poronga"<<endl;
    }
    else{
        while (getline(archivo,lectura, ',')){
            x = stoi(lectura);
            getline(archivo,lectura, ',');
            y = stoi(lectura);
            getline(archivo,tipo, ',');
            getline(archivo,lectura, '\n');
            peso = stoi(lectura);

            mi_lista->alta( new Casillero(x,y,tipo));
        }
    }
    archivo.close();

    return mi_lista;
}


template<typename T1>
void Grafo<T1>::etiquetar(Lista<T1> *lista){
    int peso;
    T1 vertice;
    T1 inicio = lista->buscarNodo(1)->obtenerDato();;

    for (int i = 1; i< lista->obtenerLargo(); i++){
        vertice = lista->buscarNodo(i+1)->obtenerDato();

        peso =  vertice->getPeso();
        vertice->setAcumulado(peso + vertice->getAcumulado());
        vertice->setAnterior(inicio);
        vertice->setLargoCamino(inicio->getLargoCamino()+1);

    }
}

template<typename T1>
T1 Grafo<T1>::minimoPeso(Lista<T1> *lista){
    int pesoMinimo = lista->buscarNodo(2)->obtenerDato()->getAcumulado();
    int pesoAux;
    for (int i = 2; i<lista->obtenerLargo();i++){
        pesoAux = lista->buscarNodo(i)->obtenerDato()->getAcumulado();
        if (pesoAux < pesoMinimo){
            pesoMinimo = pesoAux;
        }
    }
}
#endif //TP_3_ALGORITMOS_2_GRAFO_H
