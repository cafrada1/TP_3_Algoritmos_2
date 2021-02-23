#include <iostream>
#include "diccionario.h"
#include "NodoABB.h"
#include "menu.h"
#include "funciones.h"
#include <string>

using namespace std;

const int MINIMO_VALOR_MENU = 1, MAXIMO_VALOR_MENU = 6;

enum opciones { AGREGAR_PERSONAJE = 1,
    ELIMINAR_PERSONAJE = 2,
    MOSTRAR_PERSONAJES = 3,
    DETALLES_PERSONAJE = 4,
    COMENZAR_JUEGO = 5,
    SALIR = 6 };

Menu::Menu(){
    if(existePartida()){
        cout<<"x";
    }
    else{
        personajes = new Diccionario<string, Personaje *>();
        leer_archivo(*personajes);
        elegir_opcion(*personajes);
    }
}
bool Menu::existePartida(){
    ifstream archivoPartida;
    archivoPartida.open(NOMBRE_ARCHIVO);
    if( ! archivoPartida)
        return false;
    return true;
}
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
string Menu::chequeaRepetido(Lista<string> *repetidos ) {
    string nombre = pedirNombre(*personajes);
    while(repetidos -> chequeo(nombre)){
        cout << "|| PERSONAJE NO DISPONIBLE ||" << endl;
        nombre = pedirNombre(*personajes);
    }

    repetidos -> alta(nombre);

    return nombre;
}


void Menu::comenzar_juego(Diccionario<string, Personaje *> &personajes){
    bool continuar = true;

    do{
        mostrar_menu_2();

        int opcion = ingresar_opcion();

        while(!validar_opcion(opcion,1,4)){
            opcion = ingresar_opcion();
        }

        switch(opcion){
            case 1:
                buscarPersonaje(personajes);
                break;

            case 2:
                personajes.mostrarOrdenados();
                break;

            case 3:
            {
                comienzoJuego();
            }
                break;
            case 4:
                continuar = false;
                break;
        }

    }while(continuar);

}


void Menu::mostrar_menu_2(){
    cout << "\nMENÚ DE PARTIDA:" << endl;
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

    for(int i = 0; i < CANTIDAD_PERSONAJES; i++){
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


string Menu::pedirNombre(Diccionario<string, Personaje*> &diccPersonajes) {
    string nombre;
    cout << "PERSONAJES: " << endl;
    diccPersonajes.mostrarOrdenados();
    cout << "Ingrese el nombre del personaje que deseé: ";
    cin >> nombre;
    return nombre;
}

void Menu::buscarPersonaje(Diccionario<string, Personaje*> &diccPersonajes){
    string nombre = pedirNombre(diccPersonajes);
    Personaje* aux = diccPersonajes.traer(nombre);
    if(aux != nullptr)
        aux ->mostrarDatos();
    else
        cout << "El personaje no se encuentra." << endl;
}



int Menu::contadorVida(string jugador[]) {
    int suma = 0;
    for(int i = 0; i < CANTIDAD_PERSONAJES; i++){
        suma += personajes -> traer(jugador[i]) ->obtenerVida();
    }
    return suma;
}

void Menu::imprimirTurno(int num){
    if(num % 2 == 0)
        cout << "\n|| TURNO DEL JUGADOR 1 || " << endl;
    else
        cout << "\n||TURNO DEL JUGADOR 2||" << endl;
}

void Menu::seleccionarPersonajes(string jugador1[], string jugador2[]) {
    Lista<string>* repetidos = new Lista<string>;

    for(int i = 0; i < CANTIDAD_PERSONAJES; i++){
        for(int j = 0; j < CANTIDAD_JUGADORES; j++){
            if(j%2==0){
                imprimirTurno(j);
                jugador1[i] = chequeaRepetido(repetidos);
            }
            else{
                imprimirTurno(j);
                jugador2[i] = chequeaRepetido(repetidos);
            }
        }
    }
    delete repetidos;
}

void Menu::comienzoJuego() {
    int turno;
    int contador;

    string jugador1[CANTIDAD_PERSONAJES];
    string jugador2[CANTIDAD_PERSONAJES];
    seleccionarPersonajes(jugador1, jugador2);

    int vidaJugador1 = contadorVida(jugador1);
    int vidaJugador2 = contadorVida(jugador2);
    cout << "VIDA1: " << vidaJugador1 <<" y vida2: " << vidaJugador2<<endl;

    turno = rand() % 2 + 1;
    cout << turno << endl;
    if(turno == 1)
        contador = 0;
    else
        contador = 1;
    cout << "CONT:"<<contador << endl;

    cout << "\n||COMIENZO DE PARTIDA||" << endl;

    while(vidaJugador1 != 0 && vidaJugador2){
        imprimirTurno(contador);
        if(contador % 2 == 0){
            primerasOpcInternas(jugador1);
            segundasOpcInternas(jugador1);
        }
        else{
            primerasOpcInternas(jugador2);
            segundasOpcInternas(jugador2);
        }
        contador++;
        if(contador == 3){
            vidaJugador1 = 0;
        }

    }
}

string Menu::eleccionPersonaje(string jugador[]) {
    cout << "ELIJA EL PERSONAJE CON EL QUE DESEÉ REALIZAR ESTA ACCIÓN: " << endl;
    for (int i = 0; i < CANTIDAD_PERSONAJES; i++)
        cout << (i + 1) << ")" << jugador[i] << endl;
    int opcion = ingresar_opcion();

    return jugador[opcion - 1];

}

void Menu::primerasOpcInternas(string jugador[]) {
    string nombre;

    cout << "ELIJA QUE DESEA HACER CON SUS PERSONAJES: " << endl;
    cout << "1) Alimentar.\n"
            "2) Moverse.\n"
            "3) Pasar opción\n";

    int opcion = ingresar_opcion();

    switch(opcion){
        case 1:
        {
            nombre = eleccionPersonaje(jugador);
            personajes->traer(nombre)->alimentarse();
        }
            break;

        case 2:
        {
            nombre = eleccionPersonaje(jugador);
            //ACA VA LO DE MOVER AL PERSONAJE CON LO DE TABLERO
        }
            break;

        case 3:
            break;
    }
}


void Menu::segundasOpcInternas(string jugador[]) {
    string nombre;

    cout << "ELIJA QUE DESEA HACER CON SUS PERSONAJES: " << endl;
    cout << "1) Defenderse.\n"
            "2) Atacar.\n"
            "3) Pasar opción\n";

    int opcion = ingresar_opcion();

 /*ACA VA LO DE TABLERO ATAQUE y DEFENSA
    switch(opcion){
        case 1:
        {
            nombre = eleccionPersonaje(jugador);
            //ATAQUE
        }
            break;

        case 2:
        {
            nombre = eleccionPersonaje(jugador);
            //DEFENSA
        }
            break;

        case 3:
            break;
    }
*/
}



Menu::~Menu() {
    delete personajes;
}