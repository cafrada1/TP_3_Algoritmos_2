//
// Created by milagros on 28/1/21.
//

#include "partida.h"

Partida::Partida(Diccionario<string,Personaje*> * d) {
    diccPersonajes = d;
}

void Partida::guardarPartida(Diccionario<string, Personaje*> * jugador, int num /*,int columna, int fila*/){
    ofstream archivo;
    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::app);

    NodoABB<string , Personaje*> * aux;
    archivo << num << endl;

    for(int i = 0; i < (diccPersonajes->obtenerCantidad() % 2); i++){
        aux = jugador -> encuentraMinimo();
        archivo << aux -> getValue() -> obtenerTipo() << "," << aux->getKey() << ",";
        archivo << aux -> getValue() -> obtenerEscudo() << ",";
        archivo << aux -> getValue() -> obtenerVida() << ",";
        archivo << aux -> getValue() -> obtenerEnergia() << "," << endl;
        //archivo << fila << "," << columna;
        jugador -> quitarNodo(aux -> getKey());
    }
    archivo.close();
}


string Partida::pedirNombre() {
    string nombre;
    diccPersonajes -> mostrarOrdenados();
    cout << "Ingrese el nombre del personaje que deseé: ";
    cin >> nombre;
    return nombre;
}

void Partida::buscarPersonaje(){
    string nombre = pedirNombre();
    if(diccPersonajes -> buscar(nombre))
        diccPersonajes -> buscarPersonaje(nombre)->mostrarDatos();
}

void Partida::mostrarNombres() {
    cout << "Listado de personajes:" << endl;
    diccPersonajes -> mostrarOrdenados();
}

void Partida::guardarPersonaje(Diccionario<string, Personaje*> * jugador, string nombre){
    Personaje* encontrado = diccPersonajes -> buscarPersonaje(nombre);
    jugador -> agregarPersonaje(nombre,encontrado);
}

void Partida::seleccionarPersonaje(Diccionario<string, Personaje*> * jugador, Lista<string>* repetidos ) {
    string nombre = pedirNombre();
    while(repetidos -> busqueda(nombre)){
        cout << "|| PERSONAJE NO DISPONIBLE ||" << endl;
        nombre = pedirNombre();
    }
    guardarPersonaje(jugador,nombre);
    repetidos -> insertar(nombre);
}


Partida::~Partida(){
    delete diccPersonajes;
}
