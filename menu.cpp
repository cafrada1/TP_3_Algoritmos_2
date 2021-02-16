#include <iostream>
#include "diccionario.h"
#include "NodoABB.h"
#include "menu.h"
#include "funciones.h"
#include <string>
#include "partida.h"

using namespace std;

const int MINIMO_VALOR_MENU = 1, MAXIMO_VALOR_MENU = 6;

enum opciones { AGREGAR_PERSONAJE = 1,
    ELIMINAR_PERSONAJE = 2,
    MOSTRAR_PERSONAJES = 3,
    DETALLES_PERSONAJE = 4,
    COMENZAR_JUEGO = 5,
    SALIR = 6 };


void Menu::mostrar_menu(){
    cout << "\nMENÚ" << endl;
    cout << "1) Agregar un nuevo personaje.\n2) Eliminar un personaje.\n3) Mostrar todos los nombres de los personajes.\n"
            "4) Buscar por nombre los detalles de un personaje en particular.\n5) Comenzar juego.\n6) Salir.\n";
}


bool Menu::validar_opcion(int opcion, int minimo, int maximo){
    if (opcion >= minimo && opcion <= maximo)
        return true;
    return false;
}


int Menu::ingresar_opcion(){
    int opcion;
    cout << "Ingrese una opcion: ";
    cin >> opcion;
    return opcion;
}


void Menu::elegir_opcion(Diccionario<string, Personaje *> &personajes){
    bool continuar = true;

    do{
        mostrar_menu();
        int opcion = ingresar_opcion();

        while(!validar_opcion(opcion,MINIMO_VALOR_MENU, MAXIMO_VALOR_MENU)){
            opcion = ingresar_opcion();
        }

        procesar_opcion(opcion,continuar,personajes);

    }while(continuar);
}


void Menu::procesar_opcion(int opcion, bool &continuar,Diccionario<string, Personaje *> &personajes){

    switch(opcion){
        case AGREGAR_PERSONAJE:
            agregar_nuevo_personaje(personajes);
            break;

        case ELIMINAR_PERSONAJE:
        {
            string nombre_eliminado;
            cout << "Ingrese el nombre del personaje que desea eliminar: ";
            cin >> nombre_eliminado;
            if (personajes.buscar(nombre_eliminado))
                eliminar_personaje(personajes, nombre_eliminado);
            else
                cout << "El nombre del personaje no es válido" << endl;
        }
            break;

        case MOSTRAR_PERSONAJES:
            personajes.mostrarOrdenados();
            break;

        case DETALLES_PERSONAJE:
        {
            string nombre;
            cout << "Ingrese el nombre del personaje para ver detalles: ";
            cin >> nombre;
            if (personajes.buscar(nombre))
                mostrar_datos_personaje(personajes, nombre);
            else
                cout << "El nombre del personaje no es válido" << endl;
        }
            break;

/*
		case ALIMENTAR_PERSONAJE:
			{
			string nombre;
			cout << "Ingrese el nombre del personaje al que desea alimentar: ";
			cin >> nombre;
			if (personajes.buscar(nombre))
				alimentar_personaje(personajes, nombre);
			else
				cout << "El nombre del personaje no es válido" << endl;
			}
			break;
*/
        case COMENZAR_JUEGO:
            comenzar_juego(personajes);
            break;

        case SALIR:
            continuar = false;
            break;
    }
}

void Menu::validar_elemento(string &elemento){
    while (elemento != "agua" && elemento != "fuego" && elemento != "tierra" && elemento != "aire"){
        cout << "Ingrese un elemento válido (agua,fuego,tierra o aire)" << endl;
        cin >> elemento;
    }
}


void Menu::validar_datos(string &elemento){
    validar_elemento(elemento);
}


void Menu::pedir_datos_personaje(string &elemento, string &nombre){
    cout << "Ingrese el elemento: ";
    cin >> elemento;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    validar_datos(elemento);
}


void Menu::agregar_nuevo_personaje(Diccionario<string, Personaje *> &personajes){
    Personaje* nuevo_personaje;
    string tipo, nombre;
    int escudo = rand()% 3;
    int vida = 10+ rand() % 91;
    int energia = rand() % 21;
    pedir_datos_personaje(tipo, nombre);
    validar_datos(tipo);
    cargar_atributos_personaje(nuevo_personaje,vida,nombre,escudo,energia,tipo);
    agregar_personaje_a_diccionario(personajes, nuevo_personaje);

}


void Menu::eliminar_personaje(Diccionario<string, Personaje *> &personajes, string nombre){
    personajes.quitarNodo(nombre);
}


void Menu::mostrar_datos_personaje(Diccionario<string, Personaje *> &personajes, string nombre){
    Personaje *personaje = personajes.traer(nombre);
    personaje->mostrarDatos();
    //cout << "Nombre: " << personaje->obtenerNombre() << endl;
    //cout << "Elemento: " << personaje->obtenerTipo() << endl;
    //cout << "Vida: " << personaje->obtenerVida() << endl;
    //cout << "Escudo: " << personaje->obtenerEscudo() << endl;
    //cout << "Energía: " << personaje->obtenerEnergia() << endl;
}


void Menu::alimentar_personaje(Diccionario<string, Personaje *> &personajes, string nombre){
    Personaje *personaje = personajes.traer(nombre);
    personaje->alimentarse();
}

bool Menu::esta_en_el_diccionario(Diccionario<string, Personaje *> &personajes, string nombre){
    return personajes.buscar(nombre);
}

void Menu::comenzar_juego(Diccionario<string, Personaje *> &personajes){
    bool continuar = true;

    Diccionario<string,Personaje*> * jugador1 = new Diccionario<string,Personaje*>();
    Diccionario<string,Personaje*> * jugador2 = new Diccionario<string,Personaje*>();

    do{
        mostrar_menu_2();
        Partida nueva;

        int opcion = ingresar_opcion();

        while(!validar_opcion(opcion,1,4)){
            opcion = ingresar_opcion();
        }

        switch(opcion){
            case 1:
            {
                nueva.buscarPersonaje(personajes);
            }
                break;

            case 2:
                personajes.mostrarOrdenados();
                break;

            case 3:
            {
                Lista<string> repetidos;
                for(int i = 0; i < CANTIDAD_PERSONAJES; i ++) {
                    if (i % 2 == 0) {
                        cout<<"\nTURNO DEL JUGADOR 1"<<endl;
                        nueva.seleccionarPersonaje(personajes,*jugador1, &repetidos);
                    }
                    else {
                        cout<<"\nTURNO DEL JUGADOR 2"<<endl;
                        nueva.seleccionarPersonaje(personajes,*jugador2, &repetidos);
                    }
                }

            }
                break;
            case 4:
                continuar = false;
                break;
        }

    }while(continuar);
    delete jugador1;
    delete jugador2;

}


void Menu::mostrar_menu_2(){
    cout << "\nELECCIÓN DE PEROSNAJES" << endl;
    cout << "1) Buscar por nombre los detalles de un personaje en particular.\n"
            "2) Mostrar todos los nombres de los personajes.\n"
            "3) Seleccionar personaje\n"
            "4) Salir.\n";
}

void Menu::guardarPartida(Diccionario<string, Personaje*> &jugador, int num/*,int columna, int fila*/){
    ofstream archivo;
    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::app);

    NodoABB<string , Personaje*> * aux;
    archivo << num << endl;

    for(int i = 0; i < (CANTIDAD_PERSONAJES % 2); i++){
        aux = jugador.encuentraMinimo();
        archivo << aux -> getValue() -> obtenerTipo() << "," << aux->getKey() << ",";
        archivo << aux -> getValue() -> obtenerEscudo() << ",";
        archivo << aux -> getValue() -> obtenerVida() << ",";
        archivo << aux -> getValue() -> obtenerEnergia() << "," << endl;
        //archivo << fila << "," << columna;
        jugador.quitarNodo(aux -> getKey());
    }
    archivo.close();
}
