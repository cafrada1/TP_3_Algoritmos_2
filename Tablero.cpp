#include <iostream>

#include "Tablero.h"
#include <string>
#include "Montana.h"
#include "Precipicio.h"
#include "Lago.h"
#include "Volcan.h"
#include "Camino.h"
#include "Vacio.h"


using namespace std;


void Tablero::cargar_casillero(int terreno, int fila, int columna ){

    if (terreno == 1){

        Casillero *p  = new Lago();
        tablero[fila][columna] = p;

    }else if (terreno == 2){
        Casillero *p  = new Volcan();
        tablero[fila][columna] = p;

    }else if (terreno == 3){
        Casillero *p  = new Precipicio();
        tablero[fila][columna] = p;

    }else if (terreno == 4){
        Casillero *p  = new Montana();
        tablero[fila][columna] = p;

    }else if (terreno == 5){
        Casillero *p  = new Camino();
        tablero[fila][columna] = p;

    }else if (terreno == 6){
        Casillero *p  = new Vacio();
        tablero[fila][columna] = p;


    }

}

void Tablero::cargar_tablero(){

    for (int fila=0; fila<8; fila++){
        for (int columna=0; columna<8; columna++){
            int terreno = TABLERO[fila][columna];
            cargar_casillero(terreno, fila, columna);
        }
    }
}

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

void Tablero::calculo_adyacentes(int fila, int columna){
    /*int casilleros_adyacentes[][];


    if ((fila != 0)&&(fila != 7)&&(columa != 0)&&(columna != 7){

           casilleros_adyacentes[][] = [fila - 1, columna], [fila + 1, columna], [fila, columna - 1], [fila, columna + 1]

    }else if (columna == 1){
        if (columna == 1){
            adyacentes[fila][columna] = [1,7]
        if (columna == 8){
            adyacentes[fila][columna] = [6,15]
        }else{
            adyacente_1 = fila - 1;
            adyacente_2 = fila + 1;
            adyacente_3 = fila + 8;
            adyacentes[fila][columna] = [adyacente_1, adyacente_2, adyacente_3]
        }
    }else if (fila == 1){
        if (columna == 1){
            adyacentes[fila][columna] = [2,9]
        }else{
            adyacente_1 = fila - 1;
            adyacente_2 = fila + 1;
            adyacente_3 = fila + 8;
            adyacentes[fila][columna] = [adyacente_1, adyacente_2, adyacente_3]
        }
    }

*/
}


bool tablero::consulta_ocupado(int fila, int columna){
    return tablero[fila][columna]->consulta_ocupado();
}

Personaje* tablero::consulta_personaje(int fila, int columna){
    return tablero[fila][columna]->consulta_personaje();
}


