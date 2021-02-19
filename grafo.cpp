//
// Created by franco on 18/2/21.
//
#include "grafo.h"

void Grafo::iniciarMatrices(int **matrizPeso[], int **matrizCamino[]){
    *matrizPeso = new int * [largo];
    *matrizCamino = new int * [largo];

    for (int i=0; i<largo;i++){
        (*matrizPeso)[i] = new int [largo];
        (*matrizCamino)[i] = new int [largo];
    }
}


Grafo::Grafo(){
    raiz = new Lista<Lista<Vertice<Casillero *> *> *>;

    listaCasilleros = cargarGrafo();

    largo = listaCasilleros->obtenerLargo();

    iniciarMatrices(&matrizPesoAgua, &matrizCaminoAgua);
    iniciarMatrices(&matrizPesoAire, &matrizCaminoAire);
    iniciarMatrices(&matrizPesoFuego, &matrizCaminoFuego);
    iniciarMatrices(&matrizPesoTierra, &matrizCaminoTierra);

    caminosMinimos(listaCasilleros,ELEMENTO_AIRE, matrizPesoAire, matrizCaminoAire);
    caminosMinimos(listaCasilleros,ELEMENTO_AGUA, matrizPesoAgua, matrizCaminoAgua);
    caminosMinimos(listaCasilleros,ELEMENTO_FUEGO, matrizPesoFuego, matrizCaminoFuego);
    caminosMinimos(listaCasilleros,ELEMENTO_TIERRA, matrizPesoTierra, matrizCaminoTierra);

}


Lista<Casillero *> *Grafo::cargarGrafo() {

    Lista<Casillero *> *lista = leer_archivo();

    Vertice<Casillero *> *verticeOrigen;
    Vertice<Casillero *> *verticeDestino;
    Casillero *nodoOrigen;
    Casillero *nodoDestino;

    for (int i = 0; i<lista->obtenerLargo(); i++){
        nodoOrigen = lista->buscarNodo(i+1)->obtenerDato();
        
        for (int j = 0; j<lista->obtenerLargo(); j++){
        
            if (i!=j){
                nodoDestino = lista->buscarNodo(j+1)->obtenerDato();

                if (nodoOrigen->distancia(nodoDestino) <= 1) {
                    verticeOrigen = new Vertice<Casillero *>;
                    verticeDestino = new Vertice<Casillero *>;

                    verticeOrigen->setValue(nodoOrigen);
                    verticeDestino->setValue(nodoDestino);

                    agregarVertice(verticeOrigen, verticeDestino);
                }
            }
        }
    }

    return lista;
}


Lista<Vertice<Casillero *> *> *Grafo::buscarSublista(Vertice<Casillero *> * verticeOrigen) {
    if (raiz->obtenerLargo() == 0){
        return nullptr;
    }

    Lista<Vertice<Casillero *> *> *sublista = raiz->buscarNodo(1)->obtenerDato();
    Nodo<Vertice<Casillero *> *> *nodo  = sublista->buscarNodo(1);
    int i = 1;
    while ((nodo->obtenerDato()->getValue() != verticeOrigen->getValue()) && (i <= raiz->obtenerLargo())){
        sublista = raiz->buscarNodo(i)->obtenerDato();
        nodo = sublista->buscarNodo(1);
        i++;
    }
    if (nodo->obtenerDato()->getValue() != verticeOrigen->getValue()){
        return nullptr;
    }
    return sublista;
}


void Grafo::agregarVertice(Vertice<Casillero *> * verticeOrigen, Vertice<Casillero *> * verticeDestino){

    Lista<Vertice<Casillero *> *> *sublista = buscarSublista(verticeOrigen);
    if (sublista != nullptr){
        sublista->alta(verticeDestino);
        delete verticeOrigen;
    }
    else{
        sublista = new Lista<Vertice<Casillero *> *>();
        sublista->alta(verticeOrigen);
        sublista->alta(verticeDestino);
        raiz->alta(sublista);
    }
}


void Grafo::mostrar(){
    Lista<Vertice<Casillero *> *> *sublista = nullptr;

    for (int i = 0; i<raiz->obtenerLargo(); i++){

        sublista = raiz->buscarNodo(i+1)->obtenerDato();
        cout <<sublista->buscarNodo(1)->obtenerDato()->getValue()->getNumero();
        cout<<" -> ";

        for (int j = 2; j<sublista->obtenerLargo(); j++){
            cout << sublista->buscarNodo(j)->obtenerDato()->getValue()->getNumero();

            cout << "-> ";
        }

        cout<<sublista->buscarNodo(sublista->obtenerLargo())->obtenerDato()->getValue()->getNumero();
        cout <<endl;
    }

}



Lista<Casillero *> *Grafo::leer_archivo() {
    int x,y;
    string lectura;
    string tipo;
    ifstream archivo;
    archivo.open(RUTA, ios::in);
    int contador = 1;

    Lista<Casillero *> *mi_lista = new Lista<Casillero *>;
    if (archivo.fail()){
        cout << "ERROR AL ABRIR EL ARCHIVO"<<endl;
    }
    else{
        while (getline(archivo,lectura, ',')){
            x = stoi(lectura);
            getline(archivo,lectura, ',');
            y = stoi(lectura);
            getline(archivo,tipo, '\n');

            mi_lista->alta( new Casillero(x,y,tipo,contador));
            contador++;
        }
    }
    archivo.close();

    return mi_lista;
}


void Grafo::caminosMinimos(Lista<Casillero *> *lista, string elementoPersonaje,
                           int **matrizPesos, int **matrizCaminos) {


    for (int i = 0; i < largo; i++) {
        for (int j = 0; j < largo; j++) {
            matrizPesos[i][j] = calcularPeso(lista->buscarNodo(i+1)->obtenerDato(),
                                             lista->buscarNodo(j+1)->obtenerDato(),
                                             elementoPersonaje);

            matrizCaminos[i][j] = j+1;
        }
    }
    algoritmoFloyd(matrizPesos,matrizCaminos);

}


int Grafo::calcularPesoAire( Casillero *destino) {
    int peso;

    if (destino->getTerreno() == TERRENO_PRECIPICIO ){
        peso = PESO_MISMO_ELEMENTO;
    }
    else if (destino->getTerreno() == TERRENO_MONTANIA){
        peso = PESO_ELEMENTO_OPUESTO;
    }
    else {
        peso = PESO_DISTINTO_ELEMENTO;
    }

    return peso;

}


int Grafo::calcularPesoAgua( Casillero *destino) {
    int peso;

    if (destino->getTerreno() == TERRENO_LAGO ){
        peso = PESO_MISMO_ELEMENTO;
    }
    else if (destino->getTerreno() == TERRENO_VOLCAN){
        peso = PESO_ELEMENTO_OPUESTO;
    }
    else {
        peso = PESO_DISTINTO_ELEMENTO;
    }

    return peso;
}

int Grafo::calcularPesoFuego( Casillero *destino) {
    int peso;

    if (destino->getTerreno() == TERRENO_VOLCAN ){
        peso = PESO_MISMO_ELEMENTO;
    }
    else if (destino->getTerreno() == TERRENO_LAGO){
        peso = PESO_ELEMENTO_OPUESTO;
    }
    else {
        peso = PESO_DISTINTO_ELEMENTO;
    }

    return peso;
}

int Grafo::calcularPesoTierra( Casillero *destino) {
    int peso;

    if (destino->getTerreno() == TERRENO_MONTANIA ){
        peso = PESO_MISMO_ELEMENTO;
    }
    else if (destino->getTerreno() == TERRENO_PRECIPICIO){
        peso = PESO_ELEMENTO_OPUESTO;
    }
    else {
        peso = PESO_DISTINTO_ELEMENTO;
    }

    return peso;
}

int Grafo::calcularPesoElemento(Casillero *destino, string elementoPersonaje){
    int peso;

    if (ELEMENTO_AIRE  == elementoPersonaje) {

        peso = calcularPesoAire(destino);
    }
    else if (ELEMENTO_AGUA  == elementoPersonaje) {

        peso = calcularPesoAgua(destino);
    }
    else if (ELEMENTO_FUEGO  == elementoPersonaje) {

        peso = calcularPesoFuego(destino);
    }
    else
    {
        peso = calcularPesoTierra(destino);
    }

    return peso;
}


int Grafo::calcularPeso(Casillero *origen, Casillero *destino, string elementoPersonaje) {
    int peso;

    if (origen->distancia(destino) == 0 ){
        peso = 0;
    }
    else if (origen->distancia(destino)>1){
        peso = PESO_INFINITO;
    }
    else if (destino->getTerreno() == TERRENO_VACIO) {
        peso = PESO_VACIO;
    }
    else if (destino->getTerreno() == TERRENO_CAMINO) {
        peso = PESO_CAMINO;
    }
    else {
        peso = calcularPesoElemento(destino, elementoPersonaje);
    }

    return peso;
}


void Grafo::mostrarMatriz(int **vec) {
    for (int i = 0; i < largo; i++) {
        for (int j = 0; j < largo; j++) {
            cout << vec[i][j] << " ";
        }

        cout << endl;
        cout << i+1;
        cout << endl;
        cout << endl;

    }
}


void Grafo::algoritmoFloyd(int **matrizPesos, int **matrizCasilleros) {

    for (int k = 0; k < largo; k++){
        for (int i = 0; i < largo; i++){
            for (int j = 0; j < largo; j++){

                if ( i != k && j!=k) {
                    if (matrizPesos[k][j] + matrizPesos[i][k] < matrizPesos[i][j]) {
                        //cout << matrizPesos[i][j]<<endl;
                        matrizPesos[i][j] = matrizPesos[k][j] + matrizPesos[i][k];
                        matrizCasilleros[i][j] = matrizCasilleros[k][k];
                    }
                }
            }

        }
    }

}



int **Grafo::matrizCamino(string elementoPersonaje) {
    int **vector;

    if (elementoPersonaje == ELEMENTO_FUEGO){
        vector = matrizCaminoFuego;
    }
    else if (elementoPersonaje == ELEMENTO_AGUA){
        vector = matrizCaminoAgua;
    }
    else if (elementoPersonaje == ELEMENTO_AIRE){
        vector = matrizCaminoAire;
    }
    else{
        vector = matrizCaminoTierra;
    }
    return vector;
}
int **Grafo::matrizEnergia(string elementoPersonaje) {
    int **vector;

    if (elementoPersonaje == ELEMENTO_FUEGO){
        vector = matrizPesoFuego;
    }
    else if (elementoPersonaje == ELEMENTO_AGUA){
        vector = matrizPesoAgua;
    }
    else if (elementoPersonaje == ELEMENTO_AIRE){
        vector = matrizPesoAire;
    }
    else{
        vector = matrizPesoTierra;
    }
    return vector;
}


void Grafo::mostrarCamino(Lista<Vertice<int> *> *lista) {
    int numeroCasillero;
    cout << "(origen)"<<endl <<"--";
    for (int i=0; i<lista->obtenerLargo()-1; i++){
        numeroCasillero = lista->buscarNodo(i+1)->obtenerDato()->getValue();
        listaCasilleros->buscarNodo(numeroCasillero)->obtenerDato()->mostrar();

        cout << endl <<"->";

    }
    numeroCasillero = lista->buscarNodo(lista->obtenerLargo())->obtenerDato()->getValue();
    listaCasilleros->buscarNodo(numeroCasillero)->obtenerDato()->mostrar();
    cout <<endl<< "(destino)" <<endl;

}


int Grafo::energiaNecesaria(int origen, int destino, string elementoPersonaje) {

    int **matriz = matrizEnergia(elementoPersonaje);

    return matriz[origen-1][destino-1];
}



Grafo::~Grafo() {

    for (int i = 0; i<largo;i++){
        delete [] matrizPesoAire[i];
        delete [] matrizCaminoAire[i];

        delete [] matrizPesoFuego[i];
        delete [] matrizCaminoFuego[i];

        delete [] matrizPesoAgua[i];
        delete [] matrizCaminoAgua[i];

        delete [] matrizCaminoTierra[i];
        delete [] matrizPesoTierra[i];
    }

    delete [] matrizPesoAire;
    delete [] matrizCaminoAire;

    delete [] matrizPesoFuego;
    delete [] matrizCaminoFuego;

    delete [] matrizPesoAgua;
    delete [] matrizCaminoAgua;

    delete [] matrizCaminoTierra;
    delete [] matrizPesoTierra;

    if (raiz!= nullptr) {
        delete raiz;
    }
    delete listaCasilleros;
}

Lista<Vertice<int> *> *Grafo::obtenerCaminoMinimo(int origen, int destino, string elementoPersonaje) {

    int **matrizCasilleros = matrizCamino(elementoPersonaje);

    Lista<Vertice<int> *> *lista = new Lista<Vertice<int> *>();

    obtenerCaminoMinimo( origen,destino, matrizCasilleros, lista);

    lista->alta(new Vertice<int>(destino));

    return lista;
}

void Grafo::obtenerCaminoMinimo(int origen, int destino, int **matrizCasilleros, Lista<Vertice<int> *> *lista) {


    if (matrizCasilleros[origen-1][destino-1] == destino){
       lista->alta(new Vertice<int>(origen));
    }
    else{

        obtenerCaminoMinimo( origen,matrizCasilleros[origen-1][destino-1], matrizCasilleros, lista);
        obtenerCaminoMinimo( matrizCasilleros[origen-1][destino-1], destino, matrizCasilleros, lista);
    }

}


#include "grafo.h"
