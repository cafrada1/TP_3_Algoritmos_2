//
// Created by franco on 8/2/21.
//

#ifndef TP_3_ALGORITMOS_2_VERTICE_H
#define TP_3_ALGORITMOS_2_VERTICE_H

template <typename T1>
class Vertice{
private:
    T1 value;
    int peso;
    Vertice<T1> *anterior;
    int acumulado = 0;
    int largo_camino = 0;
    bool visitado = false;
public:
    Vertice() = default;

    T1 getValue();
    int getPeso();
    Vertice<T1> *getAnterior();
    int getAcumulado();
    int getLargoCamino();
    bool getVisitado();

    void setValue(T1 value);
    void setPeso(int peso);
    void setAnterior(Vertice<T1> *vertice_anterior);
    void setAcumulado(int acumulado);
    void setLargoCamino(int largo);
    void cambiarVisitado();
    ~Vertice() = default;
};

template <typename T1>
T1 Vertice<T1>::getValue(){
    return value;
};

template <typename T1>
int Vertice<T1>::getPeso(){
    return abs(value->getX()-value->getY());
}

template<typename T1>
Vertice<T1> *Vertice<T1>::getAnterior() {
    return anterior;
}

template<typename T1>
int Vertice<T1>::getAcumulado() {
    return acumulado;
}

template<typename T1>
int Vertice<T1>::getLargoCamino() {
    return largo_camino;
}

template<typename T1>
bool Vertice<T1>::getVisitado() {
    return visitado;
}

template<typename T1>
void Vertice<T1>::setValue(T1 value) {
    this->value = value;
}

template<typename T1>
void Vertice<T1>::setPeso(int peso) {
    this->peso = peso;
}

template<typename T1>
void Vertice<T1>::setAnterior(Vertice<T1> *vertice_anterior) {
    anterior = vertice_anterior;
}

template<typename T1>
void Vertice<T1>::setAcumulado(int acumulado) {
    this->acumulado = acumulado;
}

template<typename T1>
void Vertice<T1>::setLargoCamino(int largo) {
    largo_camino = largo;
}

template<typename T1>
void Vertice<T1>::cambiarVisitado() {
    if (visitado){
        visitado = false;
    }
    else{
        visitado = true;
    }
}

#endif //TP_3_ALGORITMOS_2_VERTICE_H
