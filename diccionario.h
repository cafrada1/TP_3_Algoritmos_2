//
// Created by franco on 31/1/21.
//

#ifndef TP_3_ALGORITMOS_2_DICCIONARIO_H
#define TP_3_ALGORITMOS_2_DICCIONARIO_H

#include "personaje.h"
#include "NodoABB.h"
#include <fstream>
#include <sstream>
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"

using namespace std;

const string PATH_ARCHIVO = "personajes.csv";   //"../personajes.csv" para la terminal o "personajes.csv" para un IDE

using namespace std;

template <typename T1, typename T2>

class Diccionario{

private:
    NodoABB<T1 , T2> *raiz;

    void leer_archivo();

    void procesar_linea_archivo(string linea);

    void cargar_atributos_personaje(Personaje* &nuevo_personaje,int vida,string nombre,int escudo,int energia,string tipo);

    void agregar_personaje_a_diccionario(Personaje* &nuevo_personaje);

public:
    Diccionario();

    NodoABB<T1 , T2> *getRaiz();

    NodoABB<T1 , T2> *agregarNodo(NodoABB<T1 , T2> *nodo_nuevo, T1 key, T2 personaje);

    void agregarPersonaje(T1 key, T2 personaje);

    void agregarPersonaje(Personaje* &nuevo_personaje,int vida,string nombre,int escudo,int energia,string tipo);

    NodoABB<T1 , T2> *buscar(NodoABB<T1 , T2> *nodo, T1 key);

    bool buscar(T1 key);

    //PRE:
    //POST: Devuelve el valor asociado a la clave o nullptr si la clave no se encuentra en el diccionario
    T2 traer(T1 key);

    //PRE:
    //POST: Muestra los nombres de los personajes en orden alfabetico
    void mostrarOrdenados(NodoABB<T1 , T2> *nodo);

    void mostrarOrdenados();

    //PRE:
    //POST: Encuentra el nodo con la clave inmediatamente menor a la que se encuentra dentro del nodo pasado por referencia
    NodoABB<T1 , T2> *encuentraMinimo(NodoABB<T1 , T2> *nodo);

    void quitarRaiz();

    void quitarNodo( NodoABB<T1 , T2> *nodo);

    void quitarNodo(T1 key);

    //PRE:
    //POST: quita un nodo que no tiene hijos
    void quitarHoja(NodoABB<T1 , T2> *nodo);
    
    //PRE:	El nodo padre no tiene hijo izquierdo
    //POST: Quita el nodo pasado por parametro que solo tiene hijo derecho
    void quitarNodoConHijoDerecho(NodoABB<T1 , T2> *nodo);
    
    //PRE: El nodo padre no tiene hijo derecho
    //POST: Quita el nodo pasado por parametro que solo tiene hijo izquierdo
    void quitarNodoConHijoIzquierdo(NodoABB<T1 , T2> *nodo);
    
    //PRE:
    //POST: Quita un nodo que tiene 2 hijos
    void quitarNodoConDosHijos(NodoABB<T1 , T2> *nodo);

    void limpiar();

    bool vacio();


    ~Diccionario();
};

//template<typename T1, typename T2>
//Diccionario<T1, T2>::Diccionario() {
//    raiz = nullptr;
//}

template<typename T1, typename T2>
Diccionario<T1, T2>::Diccionario(){
	raiz = nullptr;

	leer_archivo();

}

template<typename T1, typename T2>
NodoABB<T1 , T2> *Diccionario<T1, T2>::agregarNodo(NodoABB<T1 , T2> *nodo, T1 key, T2 personaje) {

    if (nodo == nullptr){
        nodo = new NodoABB<T1 , T2>(key,personaje);
        return nodo;
    }
    else if (nodo->getKey() > key){
        nodo->setIzquierdo(agregarNodo(nodo->getIzquierdo(), key, personaje));
        nodo->getIzquierdo()->setPadre(nodo);
    }
    else {
        nodo->setDerecho(agregarNodo(nodo->getDerecho(), key, personaje));
        nodo->getDerecho()->setPadre(nodo);
    }
    return nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::agregarPersonaje(T1 key, T2 personaje) {

    raiz = agregarNodo(raiz,key,personaje);

}

template<typename T1, typename T2>
void Diccionario<T1, T2>::agregarPersonaje(Personaje* &nuevo_personaje,int vida,string nombre,int escudo,int energia,string tipo) {

	cargar_atributos_personaje(nuevo_personaje,vida,nombre,escudo,energia,tipo);
	agregarPersonaje(nombre, nuevo_personaje);

}

template<typename T1, typename T2>
NodoABB<T1 , T2> *Diccionario<T1, T2>::buscar(NodoABB<T1 , T2> *nodo, T1 key){
    if (nodo == nullptr || key == nodo->getKey()){
        return nodo;
    }
    else if (nodo->getKey() > key){
        return buscar(nodo->getIzquierdo(),key);
    }
    return buscar(nodo->getDerecho(), key);
}

template<typename T1, typename T2>
bool Diccionario<T1, T2>::buscar(T1 key) {
    NodoABB<T1 , T2> *encontrado = buscar(raiz, key);

    return (encontrado != nullptr);
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::mostrarOrdenados(NodoABB<T1 , T2> *nodo) {
    if (nodo != nullptr){
        mostrarOrdenados(nodo->getIzquierdo());
        //nodo->getValue()->mostrarDatos();
        cout<<nodo->getKey()<<endl;
        mostrarOrdenados(nodo->getDerecho());
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::mostrarOrdenados() {
    mostrarOrdenados(raiz);
}

template<typename T1, typename T2>
NodoABB<T1 , T2> *Diccionario<T1, T2>::getRaiz() {
    return raiz;
}

template<typename T1, typename T2>
NodoABB<T1 , T2> *Diccionario<T1, T2>::encuentraMinimo(NodoABB<T1 , T2> *nodo) {
    if (nodo->getDerecho() != nullptr){
        return encuentraMinimo(nodo->getDerecho());
    }
    return nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarRaiz() {
    if (raiz->dosHijos()){
        quitarNodoConDosHijos(raiz);
    }
    else{
        NodoABB< T1 , T2> *aux = raiz;
        if (raiz->esHoja()){
            raiz = nullptr;
        }
        else if (raiz->hijoDerechoUnico()){
            raiz = raiz->getDerecho();
        }
        else if (raiz->hijoIzquierdoUnico()){
            raiz = raiz->getIzquierdo();
        }
        delete aux;
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarHoja(NodoABB<T1 , T2> *nodo){
    if (nodo == nodo->getPadre()->getIzquierdo()){
        nodo->getPadre()->setIzquierdo(nullptr);
    }
    else{
        nodo->getPadre()->setDerecho(nullptr);
    }
    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodoConHijoDerecho(NodoABB<T1 , T2> *nodo){

    nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getDerecho());
    nodo->getDerecho()->setPadre(nodo->getPadre());

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodoConHijoIzquierdo(NodoABB<T1 , T2> *nodo){

    nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getIzquierdo());
    nodo->getIzquierdo()->setPadre(nodo->getPadre());

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodoConDosHijos(NodoABB<T1 , T2> *nodo){
    NodoABB<T1 , T2> *nodo_predecesor = encuentraMinimo(nodo->getIzquierdo());
    T2 aux_value = nodo->getValue();
    T1 aux_key = nodo->getKey();

    nodo->setValue(nodo_predecesor->getValue());
    nodo->setKey(nodo_predecesor->getKey());

    if (!nodo_predecesor->esHoja()){  //El nodo predecesor tiene hijos
    	NodoABB<T1 , T2> *padre_nodo_predecesor = nodo_predecesor->getPadre();
    	NodoABB<T1 , T2> *hijo_nodo_predecesor = nodo_predecesor->getIzquierdo();
    	hijo_nodo_predecesor->quitarPadre(hijo_nodo_predecesor);

    	if (padre_nodo_predecesor->getIzquierdo() == nodo_predecesor){ //El predecesor es el hijo inmediato izquierdo del nodo
    	padre_nodo_predecesor->setIzquierdo(hijo_nodo_predecesor);  //Uno el abuelo con el hijo(izq) del hijo izquierdo
    	}
    	else{
    		padre_nodo_predecesor->setDerecho(hijo_nodo_predecesor); //Uno el abuelo con el hijo(izq) del hijo derecho
    	}
    	hijo_nodo_predecesor->setPadre(padre_nodo_predecesor);
    }

    else{  //El nodo predecesor es hoja
    	nodo_predecesor->quitarPadre(nodo_predecesor);
    }
    	nodo_predecesor->setValue(aux_value);
    	nodo_predecesor->setKey(aux_key);

    delete nodo_predecesor;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodo(NodoABB<T1 , T2> *nodo) {
    if (nodo == raiz){
        quitarRaiz();
    }
    else if (nodo->esHoja()) {
        quitarHoja(nodo);
    }

    else if (nodo->hijoDerechoUnico()){
        quitarNodoConHijoDerecho(nodo);
    }

    else if (nodo->hijoIzquierdoUnico()){
        quitarNodoConHijoIzquierdo(nodo);
    }

    else{
        quitarNodoConDosHijos(nodo);
    }
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodo(T1 key) {
    NodoABB<T1, T2> *nodo = buscar(raiz, key);
    quitarNodo(nodo);
}

template<typename T1, typename T2>
bool Diccionario<T1, T2>::vacio(){
    return (raiz == nullptr);
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::limpiar() {
    while (!vacio()){
        quitarRaiz();
    }
}

template<typename T1, typename T2>
Diccionario<T1, T2>::~Diccionario(){
    limpiar();
};

template<typename T1, typename T2>
T2 Diccionario<T1,T2>::traer(T1 key){
	if(buscar(key)){
		return buscar(raiz,key)->getValue();
	}
	return nullptr;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::leer_archivo(){
	ifstream archivo;
	archivo.open(PATH_ARCHIVO);
	if(!archivo){
		cout << "No se pudo abrir el archivo" << endl;
		//exit(1);
	}
	else{
		string linea;

		while(getline(archivo,linea)){
			//cout << linea << endl;
			procesar_linea_archivo(linea);
		}
		archivo.close();
	}
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::procesar_linea_archivo(string linea){
	stringstream ss(linea);
	string tipo;
	string nombre;
	string escudo;
	string vida;

	getline(ss, tipo, ',');
	getline(ss, nombre, ',');
	getline(ss, escudo, ',');
	int escudo_numero = stoi(escudo);  //Como era una cadena, lo paso a int

	getline(ss, vida, ',');
	int vida_numero = stoi(vida);  //Como era una cadena lo paso a int

	Personaje* nuevo_personaje;

	int energia = rand() % 20;

	agregarPersonaje(nuevo_personaje, vida_numero, nombre, escudo_numero, energia, tipo);
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::cargar_atributos_personaje(Personaje* &nuevo_personaje,int vida,string nombre,int escudo,int energia,string tipo){
	if(tipo == "agua"){
		nuevo_personaje = new Agua(vida, nombre, escudo, energia, tipo);
	}
	else if(tipo == "fuego"){
		nuevo_personaje = new Fuego(vida, nombre, escudo, energia, tipo);
	}
	else if(tipo == "tierra"){
		nuevo_personaje = new Tierra(vida, nombre, escudo, energia, tipo);
	}
	else if(tipo == "aire"){
		nuevo_personaje = new Aire(vida, nombre, escudo, energia, tipo);
	}
}


#endif //TP_3_ALGORITMOS_2_DICCIONARIO_H
