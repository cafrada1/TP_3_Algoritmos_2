#include <iostream>
#include "diccionario.h"
#include "NodoABB.h"
#include "grafo.h"
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
    personajes = new Diccionario<string, Personaje *>();
    bienvenida();
    tablero.cargar_tablero();
    if(existePartida()){
        int contador = asignarTurno();
        cout<<"OK:61"<<endl;
        leerPartida();
        cout<<"OK:63"<<endl;
        comienzoJuego(contador);
    }
    else{
        elegir_opcion();
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


void Menu::elegir_opcion(){
    bool continuar = true;

    do{
        mostrar_menu();
        int opcion = ingresar_opcion();

        while(!validar_opcion(opcion,MINIMO_VALOR_MENU, MAXIMO_VALOR_MENU)){
            opcion = ingresar_opcion();
        }

        procesar_opcion(opcion,continuar);
        system("cls");

    }while(continuar);
}


void Menu::procesar_opcion(int opcion, bool &continuar){

    switch(opcion){
        case AGREGAR_PERSONAJE:
            agregar_nuevo_personaje();
            break;

        case ELIMINAR_PERSONAJE:
        {
            string nombre_eliminado;
            cout << "Ingrese el nombre del personaje que desea eliminar: ";
            cin >> nombre_eliminado;
            if (personajes->buscar(nombre_eliminado))
                eliminar_personaje(nombre_eliminado);
            else
                cout << "El nombre del personaje no es valido" << endl;
        }
            break;

        case MOSTRAR_PERSONAJES:
            personajes->mostrarOrdenados();
            break;

        case DETALLES_PERSONAJE:
        {
            string nombre;
            cout << "Ingrese el nombre del personaje para ver detalles: ";
            cin >> nombre;
            if (personajes->buscar(nombre))
                mostrar_datos_personaje(nombre);
            else
                cout << "El nombre del personaje no es válido" << endl;
        }
            break;

        case COMENZAR_JUEGO:
            comenzar_juego();
            break;

        case SALIR:
            continuar = false;
            break;
    }
    system("pause");
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


void Menu::agregar_nuevo_personaje(){
    Personaje* nuevo_personaje;
    string tipo, nombre;
    int escudo = rand()% 3;
    int vida = 10+ rand() % 91;
    int energia = rand() % 21;
    pedir_datos_personaje(tipo, nombre);
    validar_datos(tipo);
    personajes->agregarPersonaje(nuevo_personaje,vida,nombre,escudo,energia,tipo);

}


void Menu::eliminar_personaje(string nombre){
    personajes->quitarNodo(nombre);
}


void Menu::mostrar_datos_personaje(string nombre){
    Personaje *personaje = personajes->traer(nombre);
    personaje->mostrarDatos();
}


void Menu::alimentar_personaje(string nombre){
    Personaje *personaje = personajes->traer(nombre);
    personaje->alimentarse();
}

bool Menu::esta_en_el_diccionario(string nombre){
    return personajes->buscar(nombre);
}
string Menu::chequeaRepetido(string repetidos[] ) {
    string nombre = pedirNombre();
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

void Menu::comenzar_juego(){
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
                buscarPersonaje();

                break;

            case 2:
                personajes->mostrarOrdenados();
                break;

            case 3:
            {
                seleccionarPersonajes();
                int contador = asignarTurno();

                posicionarPersonajes(contador);
                comienzoJuego(contador);
                cout << "||GRACIAS POR JUGAR||" << endl;
                continuar = false;
            }
                break;
            case 4:
                continuar = false;
                break;
        }
        system("pause");

    }while(continuar);

}


void Menu::mostrar_menu_2(){
    cout << "\nMENU DE PARTIDA:" << endl;
    cout << "1) Buscar por nombre los detalles de un personaje en particular.\n"
            "2) Mostrar todos los nombres de los personajes.\n"
            "3) Seleccionar personaje\n"
            "4) Salir.\n";
}

string Menu::pedirNombre() {
    string nombre;
    cout << "PERSONAJES: " << endl;
    personajes->mostrarOrdenados();
    cout << "Ingrese el nombre del personaje que desee: ";
    cin >> nombre;
    return nombre;
}

void Menu::buscarPersonaje(){
    string nombre = pedirNombre();
    Personaje* aux = personajes->traer(nombre);
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

void Menu::seleccionarPersonajes() {
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
int Menu::asignarTurno(){
    int contador;
    int turno;
    turno = rand() % 2 + 1;
    if(turno == 1){
        contador = 0;
    }else{
        contador = 1;
    }
    return contador;
}
void Menu::comienzoJuego(int contador) {
    string guardar = "NO";

    int vidaJugador1 = contadorVida(jugador1);
    int vidaJugador2 = contadorVida(jugador2);

    cout << "\n||COMIENZO DE PARTIDA||" << endl;
    while((vidaJugador1 != 0 || vidaJugador2 != 0) && guardar != "SI"){
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
            system("pause");
            system("cls");
        }

        contador++;
        vidaJugador1 = contadorVida(jugador1);
        vidaJugador2 = contadorVida(jugador2);

        guardar = opcionGuardar();
        if(guardar == "SI"){
            guardarPartida(jugador1, 1);
            guardarPartida(jugador2, 2);
        }

    }

}

void Menu::primerasOpcInternas(string nombre) {
    string elemento = personajes->traer(nombre)->obtenerTipo();
    if (elemento == "aire")
        personajes->traer(nombre)->cambiarEnergia(5);
    if (elemento == "tierra"){
        personajes->traer(nombre)->defensaEspecial();
    }

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
            moverPersonaje(nombre);
            break;

        case 3:
            break;
    }
}


void Menu::segundasOpcInternas(string nombre,string jugador[]) {


    cout << "ELIJA QUE DESEA HACER CON SU PERSONAJE: " << endl;
    cout << "1) Defenderse.\n"
            "2) Atacar.\n"
            "3) Pasar opcion\n";

    int opcion = ingresar_opcion();

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

void Menu::posicionarPersonajes(int contador){

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

    tablero.mostrar_tablero();
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
    system("cls");
}

void Menu::atacar(string nombre){

    bool energia_valida = personajes->traer(nombre)->validarEnergiaAtaque();

    if (energia_valida == true){
        string vector_objetivos[3];
        for (int i = 0; i < 3; i++){
            vector_objetivos[i] = "Andy";
        }
        personajes->traer(nombre)->objetivos(tablero, vector_objetivos);
        for (int i = 0; i < 3; i++){
            cout<<"atacado: "<<vector_objetivos[i]<<endl;
            if (vector_objetivos[i] != "Andy"){
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


void Menu::guardarPartida(string jugador[], int num) {
    int fila;
    int columna;
    ofstream archivo;
    archivo.open(NOMBRE_ARCHIVO, ios::out | ios::app);
    Personaje* aux;

    archivo << num << endl;

    for(int i = 0; i < CANTIDAD_PERSONAJES; i++){
        aux = personajes->traer(jugador[i]);
        fila = ((aux->obtenerPosicion()) * 8)/64;
        columna = aux->obtenerPosicion() - (fila)*8;
        archivo << aux->obtenerTipo() << "," << aux->obtenerNombre() << ","
        << aux-> obtenerEscudo() << "," << aux-> obtenerVida() <<","
        << aux-> obtenerEnergia() << "," << fila
        << "," << columna << endl;
    }
    archivo.close();
}


string Menu::opcionGuardar(){
    string opcion;
    cout << "¿Desea guardar la partida? SI/NO: ";
    cin >> opcion;
    return opcion;
}


void Menu::modificarDatos(string nombre, int vida, int escudo, int energia, int numeroCasilla){
    cout<<"OK:579"<<endl;
    personajes->traer(nombre)->setVida(vida);
    personajes->traer(nombre)->setEnergia(energia);
    personajes->traer(nombre)->setEscudo(escudo);
    personajes->traer(nombre)->setPosicion(numeroCasilla);
}
string Menu::procesarLinea(string linea){
    stringstream ss(linea);
    string tipo;
    string nombre;
    string escudo;
    string vida;
    string fila;
    string columna;
    string energia;
    cout<<"OK:593"<<endl;
    getline(ss, tipo, ',');
    getline(ss, nombre, ',');
    getline(ss, escudo, ',');
    getline(ss, vida, ',');
    getline(ss, energia, ',');
    getline(ss, fila, ',');
    cout<<"OK:600"<<endl;
    getline(ss, columna, ',');
    int numeroCasilla = (stoi(fila) * 8) + stoi(columna);
    cout<<"OK:603"<<endl;
    modificarDatos(nombre,stoi(vida), stoi(escudo), stoi(energia), numeroCasilla);
    cout<<"OK:605"<<endl;
    return nombre;

}

void Menu::leerPartida(){
    ifstream archivo;
    archivo.open(NOMBRE_ARCHIVO, ios::in);
    string linea;
    string nombre;
    int jugador;
    int contadorPersonaje = 0;
    int contadorLinea = 0;

    while(getline(archivo,linea)){
         cout<<"OK:619"<<endl;
        if(contadorLinea != 0 && contadorLinea != (CANTIDAD_PERSONAJES+1)){
            cout<<"OK:620"<<endl;
            nombre = procesarLinea(linea);
            cout<<"OK:621"<<endl;
            if(jugador == 1)
                jugador1[contadorPersonaje] = nombre;
            else
                jugador2[contadorPersonaje] = nombre;
            contadorPersonaje++;
            cout<<"OK:628"<<endl;
        }

        else if(contadorLinea == 0){
            contadorPersonaje=0;
            jugador = stoi(linea);
            cout<<"OK:633"<<endl;
        }
        else{
            contadorPersonaje=0;
            jugador = stoi(linea);
            cout<<"OK:638"<<endl;
        }
        contadorLinea++;
    }
    cout<<"OK:637"<<endl;
    archivo.close();
    remove("../partida.csv");
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

void Menu::moverPersonaje(string nombre){

    int fila, columna;
    cout<<"Ingrese la fila y la columna donde quiere posicionar a "<<nombre<<endl;
    cout<<"Fila: ";
    cin >>fila;
    cout<<"Columna: ";
    cin>>columna;

    --fila;
    int destino = (fila*8)+columna;
    --columna;

    int origen = personajes->traer(nombre)->obtenerPosicion();
    int fila_origen = origen/8;
    int columna_origen = origen%8;
    string elemento = personajes->traer(nombre)->obtenerTipo();
    int equipo = personajes->traer(nombre)->getEquipo();
    int energia_personaje = personajes->traer(nombre)->obtenerEnergia();
    Grafo *grafo = new Grafo();
    int energia_gastada = grafo->energiaNecesaria(origen, destino,elemento);
    bool disponible = tablero.consulta_disponible(fila, columna);
    if (disponible == true){
        if (energia_personaje >= energia_gastada){
            personajes->traer(nombre)->cambiarEnergia(energia_gastada);
            tablero.ponerPersonaje(fila, columna, nombre);
            tablero.guardar_equipo(fila, columna, equipo);
            tablero.cambiarDisponible(fila, columna);
            tablero.cambiarDisponible(fila_origen, columna_origen);
            personajes->traer(nombre)->setPosicion(destino);
            Lista<Vertice<int> *> *lista = grafo->obtenerCaminoMinimo(origen,destino,elemento);
            tablero.mostrar_movimiento(lista);
        }else{
            cout<<nombre<<" no tiene suficiente energia."<<endl;
        }

    }else{
        cout<<"El casillero seleccionado esta ocupado, por favor seleccione otro"<<endl;
    }

  /*
    --fila;
    int destino = (fila*8)+columna;
    --columna;
    int origen = personajes->traer(nombre)->obtenerPosicion();
    string elemento = personajes->traer(nombre)->obtenerTipo();
    Grafo *grafo = new Grafo();
    ponerPersonaje(nombre,numeroJugador);


  cout<<"Ingrese la fila y la columna a la cual quiere moverse con "<<nombre<<endl;
    cout<<"Fila: ";
    cin >>fila;
    cout<<"Columna: ";
    cin>>columna;
    --fila;
    int destino = (fila*8)+columna;
    int origen = personajes->traer(nombre)->obtenerPosicion();
    string elemento = personajes->traer(nombre)->getElemento;
    int energia = grafo->energiaNecesaria(origen, destino);
    grafo->obtenerCaminoMinimo(origen,destino,)
    if (personajes->traer(nombre)->getEnergia <= energia) {
        personaje->setEnergia(personaje->getEnergia  - energia)

*/
}




Menu::~Menu() {
    delete personajes;
}
