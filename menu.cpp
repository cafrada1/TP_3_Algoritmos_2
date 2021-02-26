#include <iostream>
#include "diccionario.h"
#include "NodoABB.h"
#include "menu.h"
#include <string>

using namespace std;

const int MINIMO_VALOR_MENU = 1, MAXIMO_VALOR_MENU = 6;

void Menu::bienvenida(){
    //Aunque parezca corrido está bien, NO TOCAR
    cout << " -----------------------------------------------------------------------------\n";
    cout << " |           _                  ______          _          _  _              |\n";
    cout << " |          | |                 | ___ \\        | |        | || |             |\n";
    cout << " |          | |      __ _       | |_/ /   __ _ | |_  __ _ | || |  __ _       |\n";
    cout << " |          | |     / _` |      | ___ \\  / _` || __|/ _` || || | / _` |      |\n";
    cout << " |          | |____| (_| |      | |_/ / | (_| || |_| (_| || || || (_| |      |\n";
    cout << " |          \\_____/ \\__,_|      \\____/   \\__,_| \\__|\\__,_||_||_| \\__,_|      |\n";
    cout << " |                     _                  _                                  |\n";
    cout << " |                    | |                | |                                 |\n";
    cout << " |                  __| |  ___           | |  ___   ___                      |\n";
    cout << " |                 / _` | / _ \\          | | / _ \\ / __|                     |\n";
    cout << " |                | (_| ||  __/          | || (_) |\\__ \\                     |\n";
    cout << " |                 \\__,_| \\___|          |_| \\___/ |___/                     |\n";
    cout << " |           _____  _                                _                       |\n";
    cout << " |          |  ___|| |                              | |                      |\n";
    cout << " |          | |__  | |  ___  _ __ ___    ___  _ __  | |_  ___   ___          |\n";
    cout << " |          |  __| | | / _ \\| '_ ` _ \\  / _ \\| '_ \\ | __|/ _ \\ / __|         |\n";
    cout << " |          | |___ | ||  __/| | | | | ||  __/| | | || |_| (_) |\\__ \\         |\n";
    cout << " |          \\____/ |_| \\___||_| |_| |_| \\___||_| |_| \\__|\\___/ |___/         |\n";
    cout << " |                                                                           |\n";
    cout << " |                                CREADO POR:                                |\n";
    cout << " |                             Closter Milagros                              |\n";
    cout << " |                                Sicca Fabio                                |\n";
    cout << " |                               Antonel Lucas                               |\n";
    cout << " |                               Capra Franco                                |\n";
    cout << " |                                                                           |\n";
    cout << " -----------------------------------------------------------------------------\n";

    system("pause");
    system("cls");

}


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
        Menu::bienvenida();
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
    cout << "\nMENU" << endl;
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
        system("cls");

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
                cout << "El nombre del personaje no es valido" << endl;
            system("pause");
        }
            break;

        case MOSTRAR_PERSONAJES:
            personajes.mostrarOrdenados();
            system("pause");
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
            system("pause");
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
    personajes.agregarPersonaje(nuevo_personaje,vida,nombre,escudo,energia,tipo);

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
string Menu::chequeaRepetido(string repetidos[] ) {
    string nombre = pedirNombre(*personajes);
    while (estaRepetido(nombre, repetidos) == true) {
        cout << "|| PERSONAJE NO DISPONIBLE ||" << endl;
        cout<<"INGRESE:";
        cin >> nombre;
    }
    return nombre;
}

bool Menu::estaRepetido(std::string nombre, std::string repetidos[]){
    for(int i = 0; i < 6; i++){
        if(nombre == repetidos[i])
            return true;
    }
    return false;
}

void Menu::comenzar_juego(Diccionario<string, Personaje *> &personajes){
    bool continuar = true;

    do{
        system("cls");
        mostrar_menu_2();

        int opcion = ingresar_opcion();

        while(!validar_opcion(opcion,1,4)){
            opcion = ingresar_opcion();
        }

        switch(opcion){
            case 1:
                buscarPersonaje(personajes);
                system("pause");
                break;

            case 2:
                personajes.mostrarOrdenados();
                system("pause");
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
    cout << "\nMENU DE PARTIDA:" << endl;
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

   /* for(int i = 0; i < CANTIDAD_PERSONAJES; i++){
        aux = jugador.encuentraMinimo();
        archivo << aux -> getValue() -> obtenerTipo() << "," << aux->getKey() << ",";
        archivo << aux -> getValue() -> obtenerEscudo() << ",";
        archivo << aux -> getValue() -> obtenerVida() << ",";
        archivo << aux -> getValue() -> obtenerEnergia() << "," << endl;
        //archivo << fila << "," << columna;
        jugador.quitarNodo(aux -> getKey());
    }*/
    archivo.close();
}


string Menu::pedirNombre(Diccionario<string, Personaje*> &diccPersonajes) {
    string nombre;
    cout << "PERSONAJES: " << endl;
    diccPersonajes.mostrarOrdenados();
    cout << "Ingrese el nombre del personaje que desee: ";
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
    int cont = 0;
    string nombre;
    string personajesUsados[CANTIDAD_PERSONAJES*2];
    for(int i = 0; i < CANTIDAD_PERSONAJES; i++){
        for(int j = 0; j < CANTIDAD_JUGADORES; j++){
            imprimirTurno(j);
            nombre = chequeaRepetido(personajesUsados);
            if(j%2==0){
                jugador1[i] = nombre;
                personajes->traer(nombre)->setEquipo(1);
            }
            else{
                jugador2[i] = nombre;
                personajes->traer(nombre)->setEquipo(2);
            }

            if(j!=0 || i!=0){
                cont+=  1;
            }
            personajesUsados[cont] = nombre;
            system("cls");
        }
    }
}

void Menu::comienzoJuego() {
    int turno;
    int contador;

    string jugador1[CANTIDAD_PERSONAJES];
    string jugador2[CANTIDAD_PERSONAJES];
    seleccionarPersonajes(jugador1, jugador2);

    int vidaJugador1 = contadorVida(jugador1);
    int vidaJugador2 = contadorVida(jugador2);

    turno = rand() % 2 + 1;
    if(turno == 1){
        contador = 0;
    }else{
        contador = 1;
    }
    tablero.cargar_tablero();
    tablero.mostrar_tablero();
    posicionarPersonajes(contador, jugador1, jugador2);

    cout << "\n||COMIENZO DE PARTIDA||" << endl;

    while(vidaJugador1 != 0 || vidaJugador2 != 0){
        imprimirTurno(contador);
        for (int i = 0; i < CANTIDAD_PERSONAJES; i++){
            tablero.mostrar_tablero();
            if(contador % 2 == 0){
                if (personajes->traer(jugador1[i])->obtenerVida()!=0){
                    primerasOpcInternas(jugador1[i]);
                    segundasOpcInternas(jugador1[i],jugador1);
                }
            }
            else{
                if (personajes->traer(jugador2[i])->obtenerVida()!=0){
                    primerasOpcInternas(jugador2[i]);
                    segundasOpcInternas(jugador2[i],jugador2);
                }
            }
        }

        contador++;
        vidaJugador1 = contadorVida(jugador1);
        vidaJugador2 = contadorVida(jugador2);
        system("pause");
        system("cls");

    }
}

string Menu::eleccionPersonaje(string jugador[]) {
    cout << "ELIJA EL PERSONAJE CON EL QUE DESEÉ REALIZAR ESTA ACCION: " << endl;
    for (int i = 0; i < CANTIDAD_PERSONAJES; i++)
        cout << (i + 1) << ")" << jugador[i] << endl;
    int opcion = ingresar_opcion();

    return jugador[opcion - 1];

}

void Menu::primerasOpcInternas(string nombre) {
    string elemento = personajes->traer(nombre)->obtenerTipo();
    if (elemento == "aire")
        personajes->traer(nombre)->cambiarEnergia(5);

    personajes->traer(nombre)->mostrarDatos();

    cout << "ELIJA QUE DESEA HACER CON SU PERSONAJE: "<<nombre << endl;
    cout << "1) Alimentar.\n"
            "2) Moverse.\n"
            "3) Pasar opcion\n";

    int opcion = ingresar_opcion();

    switch(opcion){
        case 1:

            personajes->traer(nombre)->alimentarse();
            break;

        case 2:

            //LLAMADA MOVERSE
            break;

        case 3:
            break;
    }
}


void Menu::segundasOpcInternas(string nombre, string jugador[]) {


    cout << "ELIJA QUE DESEA HACER CON SU PERSONAJE: " << endl;
    cout << "1) Defenderse.\n"
            "2) Atacar.\n"
            "3) Pasar opción\n";

    int opcion = ingresar_opcion();

 /*ACA VA LO DE TABLERO ATAQUE y DEFENSA*/
    switch(opcion){
        case 1:

            defenderse(nombre, jugador);
            break;

        case 2:
            atacar(nombre);
            break;

        case 3:
            break;
    }

}

void Menu::posicionarPersonajes(int contador, string jugador1[], string jugador2[]){

    for (int i = 0; i < CANTIDAD_PERSONAJES; i++){
        if(contador % 2 == 0){
            ponerPersonaje(jugador1[i], 1);
            ponerPersonaje(jugador2[i], 2);
        }
        else{
            ponerPersonaje(jugador2[i], 2);
            ponerPersonaje(jugador1[i], 1);
        }
    }
}




void Menu::ponerPersonaje(string nombre, int numeroJugador) {
    cout<< "TURNO JUGADOR "<<numeroJugador<<endl;


    int fila, columna;

    bool cargado = false;
    while (cargado==false ){
        cout<<"Ingrese la fila y la columna donde quiere posicionar a "<<nombre<<endl;
        cout<<"Fila: ";
        cin >>fila;
        cout<<"Columna: ";
        cin>>columna;


        --fila;
        int numero_casilla = (fila*8)+columna;
        --columna;

        bool disponible = tablero.consulta_disponible(fila, columna);
        if (disponible == true){
            tablero.ponerPersonaje(fila, columna, nombre);
            tablero.guardar_equipo(fila, columna, numeroJugador);
            tablero.cambiarDisponible(fila, columna);
            if (tablero.consulta_disponible(fila, columna)==false){
                cout<<"El casillero  "<< fila<<","<<columna<<"ahora esta ocupado por "<<nombre <<endl;
            }
            personajes->traer(nombre)->setPosicion(numero_casilla);
            cargado = true;

        }else{
            cout<<"El casillero seleccionado esta ocupado, por favor seleccione otro"<<endl;
        }


    }
}

void Menu::atacar(string nombre){

    bool energia_valida = personajes->traer(nombre)->validarEnergiaAtaque();

    if (energia_valida == true){
        string vector_objetivos[3];
        for (int i = 0; i < 3; i++){
            vector_objetivos[i] = "andy";
        }
        personajes->traer(nombre)->objetivos(tablero, vector_objetivos);
        for (int i = 0; i < 3; i++){
            cout<<"atacado: "<<vector_objetivos[i]<<endl;
            if (vector_objetivos[i] != "andy"){
                int posicion = personajes->traer(vector_objetivos[i])->obtenerPosicion();
                cout<<"posicion: "<<posicion<<endl;
                string elemento = personajes->traer(vector_objetivos[i])->obtenerTipo();
                cout<<"ELEMENTO: "<<elemento<<endl;
                int defensa = personajes->traer(vector_objetivos[i])->obtenerEscudo();
                cout<<"DEFENSA: "<<defensa<<endl;
                int ataque = personajes->traer(nombre)->calculo_ataque(posicion, elemento, defensa);
                cout<<"ATAQUE: "<<ataque<<endl;
                personajes->traer(vector_objetivos[i])->cambiarVida(ataque);
            }
        }
    }else{
        cout<<nombre<< " no cuenta con suficiente energia para realizar el ataque."<<endl;
    }

}
void Menu::defenderse(string nombre, string jugador[]){
    bool energia_valida = personajes->traer(nombre)->validarEnergiaDefensa();
    string elemento = personajes->traer(nombre)->obtenerTipo();
    if (energia_valida == true){
        if (elemento == "agua"){
            for(int i = 0; i<CANTIDAD_PERSONAJES; i++){
                if (nombre != jugador[i]){
                    personajes->traer(jugador[i])->cambiarVida(10);
                }
            }
        }
        personajes->traer(nombre)->defenderse(tablero);

    }else{
        cout<<nombre<< " no cuenta con suficiente energia para defenderse"<<endl;
    }







}

Menu::~Menu() {
    //delete personajes;
}
