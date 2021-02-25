#include <iostream>
#include <typeinfo>
#include "Tablero.h"
#include <string>


using namespace std;


void Tablero::cargar_casillero(int terreno, int fila, int columna ){

    int numero_casillero = (fila-1)*8 + columna;
    string nombre_terreno;

    if (terreno == 1){
        nombre_terreno = "lago";

    }else if (terreno == 2){
        nombre_terreno = "volcan";

    }else if (terreno == 3){
        nombre_terreno = "precipicio";

    }else if (terreno == 4){
        nombre_terreno = "montana";

    }else if (terreno == 5){
        nombre_terreno = "camino";

    }else if (terreno == 6){
        nombre_terreno = "vacio";
    }
    Casillero *nuevo_casillero  = new Casillero(columna, fila, nombre_terreno, numero_casillero);
    tablero[fila][columna] = nuevo_casillero;
}


void Tablero::cargar_tablero(){

    for (int fila=0; fila<8; fila++){
        for (int columna=0; columna<8; columna++){
            int terreno = TABLERO[fila][columna];
            cargar_casillero(terreno, fila, columna);
        }
    }
}
/*
void Tablero::mostrar(){
    for (int fila=0; fila<8; fila++){
        for (int columna=0; columna<8; columna++){
            string simbolo = tablero[fila][columna]->obtener_simbolo();
            cout << simbolo<< "|";
        }
        cout << "\n" <<endl;
        cout<<"------------------------------\n";
    }
}
*/

bool Tablero::consulta_disponible(int fila, int columna){
    return tablero[fila][columna]->getDisponible();
}

string Tablero::consulta_personaje(int fila, int columna){
    return tablero[fila][columna]->getPersonaje();
}

void Tablero::ponerPersonaje(int fila, int columna, string personaje){
    tablero[fila][columna]->ponerPersonaje(personaje);
}