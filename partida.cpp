//
// Created by milagros on 29/1/21.
//

#include "partida.h"

string Partida::pedirNombre(Diccionario<string, Personaje*> &diccPersonajes) {
    string nombre;
    cout << "PERSONAJES: " << endl;
    diccPersonajes.mostrarOrdenados();
    cout << "Ingrese el nombre del personaje que deseé: ";
    cin >> nombre;
    return nombre;
}

void Partida::buscarPersonaje(Diccionario<string, Personaje*> &diccPersonajes){
    string nombre = pedirNombre(diccPersonajes);
    Personaje* aux = diccPersonajes.traer(nombre);
    if(aux != nullptr)
        aux ->mostrarDatos();
    else
        cout << "El personaje no se encuentra." << endl;
}


void Partida::guardarPersonaje(Diccionario<string, Personaje*> &diccPersonajes, Diccionario<string, Personaje*> &jugador, string nombre){
    Personaje* encontrado = diccPersonajes.traer(nombre);
    jugador.agregarPersonaje(nombre,encontrado);
}

void Partida::seleccionarPersonaje(Diccionario<string, Personaje*> &diccPersonajes, Diccionario<string, Personaje*> &jugador, Lista<string> *repetidos ) {
    string nombre = pedirNombre(diccPersonajes);
    while(repetidos -> busqueda(nombre)){
        cout << "|| PERSONAJE NO DISPONIBLE ||" << endl;
        nombre = pedirNombre(diccPersonajes);
    }
    guardarPersonaje(diccPersonajes,jugador,nombre);
    repetidos -> insertar(nombre);
}
