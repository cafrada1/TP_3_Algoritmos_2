#include <iostream>
#include <typeinfo>
#include "Tablero.h"
#include <string>
#include <unistd.h>

using namespace std;
const int DELAY = 2;
const int MICRO = 1000000;
const string ROJO="255;0;0";
const string VERDE="0;255;0";
const string AZUL="0;0;255";

const string VIOLETA = "100;5;138";
const string CELESTE = "0;249;252";
const string MARRON_CLARO = "219;186;75";
const string MARRON_OSCURO = "100;86;35";

const string NEGRO="0;0;0";
const string BLANCO = "255;255;255";

const string PREFIJO_COLOR_LETRA = "\033[38;2;";
const string PREFIJO_COLOR_FONDO = "\033[48;2;";

const string SUFIJO_COLOR = "m";
const string SUFIJO = "\033[0m";

const char LETRA_ROJO = 'r';
const char LETRA_AZUL = 'a';
const char LETRA_VIOLETA = 'v';
const char LETRA_NEGRO = 'n';
const char LETRA_BLANCO = 'w';
const char LETRA_MARRON_CLARO = 's';
const char LETRA_MARRON_OSCURO = 'b';
const char LETRA_CELESTE = 'c';


const int PERSONAJES_MAXIMO = 6;


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
        nombre_terreno = "montaña";

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
string Tablero::sacarPersonaje(int fila, int columna){
    string personaje = tablero[fila][columna]->getPersonaje();
    tablero[fila][columna]->ponerPersonaje(" ");
    tablero[fila][columna]->cambiarDisponible();
    return personaje;
}



string Tablero::colorIndice(char color){
    string final;

    switch (color){
        case LETRA_ROJO:
            final = ROJO;
            break;
        case LETRA_AZUL:
            final = AZUL;
            break;
        case LETRA_BLANCO:
            final = BLANCO;
            break;
        case LETRA_NEGRO:
            final = NEGRO;
            break;
        case LETRA_CELESTE:
            final = CELESTE;
            break;
        case LETRA_VIOLETA:
            final = VIOLETA;
            break;
        case LETRA_MARRON_OSCURO:
            final = MARRON_OSCURO;
            break;
        case LETRA_MARRON_CLARO:
            final = MARRON_CLARO;
            break;
        default:
            final=NEGRO;
            break;
    }
    return final;
}

string Tablero::inicioColor(char colorLetra, char colorFondo){

    string final = PREFIJO_COLOR_LETRA;

    final += colorIndice(colorLetra);

    final += SUFIJO_COLOR+PREFIJO_COLOR_FONDO;

    final += colorIndice(colorFondo);

    final += SUFIJO_COLOR;

    return final;
}

void Tablero::print(string palabra, char colorFondo, char colorLetra){
    cout << inicioColor(colorLetra, colorFondo) << palabra << SUFIJO;

}

char Tablero::elegir_color_fondo(string terreno){
    char color;

    if (terreno == TERRENO_LAGO){
        color = LETRA_CELESTE;
    }
    else if (terreno == TERRENO_VOLCAN){
        color = LETRA_ROJO;
    }

    else if (terreno == TERRENO_PRECIPICIO){
        color = LETRA_BLANCO;
    }

    else if (terreno == TERRENO_MONTANIA){
        color = LETRA_MARRON_OSCURO;
    }
    else if (terreno == TERRENO_CAMINO){
        color = LETRA_MARRON_CLARO;
    }
    else if (terreno == TERRENO_VACIO){
        color = LETRA_VIOLETA;
    }
    else{
        color = LETRA_NEGRO;
    }
    return color;
}

void Tablero::mostrar_casillero( char color_fondo, char color_letra, string personaje="   "){

    print("  ",LETRA_NEGRO,LETRA_BLANCO);
    print(" "+personaje+" ",color_fondo, color_letra);

}

void Tablero::mostrar_vacio(int i){
    mostrar_casillero(LETRA_NEGRO,LETRA_BLANCO,  " ");

    for (int j = 0; j < MAX_COLUMNA; j++) {
        string terreno=tablero[i][j]->getTerreno();


        if (tablero[i][j]->getDisponible()){
            mostrar_casillero(elegir_color_fondo(terreno),LETRA_NEGRO, "   ");
        }
        else{

            mostrar_casillero(elegir_color_fondo(terreno),LETRA_NEGRO, "   ");
        }
    }
    mostrar_casillero(LETRA_NEGRO,LETRA_BLANCO, "   ");
    cout << endl;

}

void Tablero::espacio(){
    for (int j = 0; j < MAX_COLUMNA+1; j++) {

        mostrar_casillero(LETRA_NEGRO,LETRA_BLANCO,"   ");
    }
    mostrar_casillero(LETRA_NEGRO, LETRA_BLANCO," ");
    cout << endl;
}

void Tablero::mostrar_indice_fila(){
    mostrar_casillero(LETRA_NEGRO,LETRA_BLANCO, " ");

    for (int j = 0; j < MAX_COLUMNA; j++) {

        mostrar_casillero(LETRA_NEGRO,LETRA_BLANCO," "+to_string(j+1)+" ");
    }
    mostrar_casillero(LETRA_NEGRO, LETRA_BLANCO, "   ");
    cout << endl;

}

void Tablero::mostrar_tablero(){
    int contador = 0;
    string nombre;
    string lista[PERSONAJES_MAXIMO];
    espacio();
    mostrar_indice_fila();
    espacio();
    for (int i = 0; i<MAX_FILA; i++){


        mostrar_casillero(LETRA_NEGRO,LETRA_BLANCO,to_string(i+1));

        for (int j = 0; j < MAX_COLUMNA; j++) {
            string terreno=tablero[i][j]->getTerreno();

            if (tablero[i][j]->getDisponible()){
                mostrar_casillero(elegir_color_fondo(terreno),LETRA_NEGRO);
            }
            else {

                nombre = tablero[i][j]->getPersonaje();
                lista[contador] = nombre;
                contador++;
                mostrar_casillero(elegir_color_fondo(terreno),LETRA_NEGRO,nombre.substr(0,3));
            }
        }
        mostrar_casillero(LETRA_NEGRO, LETRA_BLANCO);
        cout << endl;

        mostrar_vacio(i);

        espacio();
    }
    espacio();
    espacio();
    cout<<endl;

    cout<< "Indice de personajes: "<<endl;
    for (int i=0; i<contador; i++){
        cout <<"\t"<< i+1<<": " <<lista[i]<<endl;
    }
    cout << endl;
}

void Tablero::mostrar_movimiento(Lista<Vertice<int>*> *lista){
    int numero_casillero;
    int numero_casillero_siguiente;
    string personaje;
    int fila;
    int columna;
    int fila_siguiente;
    int columna_siguiente;
    bool sacar = true;

    for (int i=0; i<lista->obtenerLargo()-1; i++){
        system("clear");
        mostrar_tablero();

        usleep(DELAY*MICRO);

        numero_casillero = lista->buscarNodo(i+1)->obtenerDato()->getValue();
        fila = (numero_casillero-1)/8;
        columna = (numero_casillero-1)%8;

        numero_casillero_siguiente = lista->buscarNodo(i+2)->obtenerDato()->getValue();
        fila_siguiente = (numero_casillero_siguiente-1)/8;
        columna_siguiente = (numero_casillero_siguiente-1)%8;

        if (sacar){
            personaje= sacarPersonaje(fila, columna);
            sacar = false;
        }
        else{
            sacar = false;
        }
        if(tablero[fila_siguiente][columna_siguiente]->getDisponible())
        {
            ponerPersonaje(fila_siguiente, columna_siguiente, personaje);
            tablero[fila_siguiente][columna_siguiente]->cambiarDisponible();
            sacar= true;
        }

    }
    system("clear");
    mostrar_tablero();
}

Tablero::~Tablero() {
/*    for (int i=0; i<MAX_FILA; i++){
        for (int j=0; j<MAX_COLUMNA; j++){
            delete tablero[i][j];
        }
    }*/
}
