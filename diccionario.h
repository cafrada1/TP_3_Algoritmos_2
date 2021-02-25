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

    /*
     *  PRE:
     *      nodo : direccion de memoria valida.
     *      key : valor no existente como key de otro nodo.
     *
     *  POST:
     *      Si el diccionario no esta vacio setea el padre del nodo agregado.
     *
     *  Descripcion:
     *      Inserta al diccionario un nuevo nodo con los valores pasados por parametro.
     */
    NodoABB<T1 , T2> *agregarNodo(NodoABB<T1 , T2> *nodo_nuevo, T1 key, T2 personaje);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna la direccion del nodo con la misma key que la pasada por parametro
     *      si esta se encuentra en el diccionario.
     *      Retorna nullptr si el elemento no se encuentra en el diccionario.
     */
    NodoABB<T1 , T2> *buscar(NodoABB<T1 , T2> *nodo, T1 key);

    /*
     *  PRE: -
     *
     *  POST:
     *      Realiza un salto de linea al mostrar una key.
     *
     *  Descripcion:
     *      Si nodo no es nulltpr:
     *        1) Se llama recursivamente pasando como parametro a su hijo izquierdo.
     *        2) Muestra por pantalla la key del nodo.
     *        3) Se llama recursivamente pasando como parametro a su hijo derecho
     */
    void mostrarOrdenados(NodoABB<T1 , T2> *nodo);


    /*
     *  PRE:
     *      *nodo : debe ser una direccion de memoria valida.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Llama a la funcion correspondiente para eliminar el nodo
     *      dependiendo del tipo de nodo.
     */
    void quitarNodo( NodoABB<T1 , T2> *nodo);

    /*      *nodo debe contener un *padre con direccion de memoria valida.
      *      *nodo debe contener un *izquierdo con direccion de memoria valida.
      *
      *  POST:
      *      Libera la memoria ocupada por *nodo.
      *
      *  Descripcion:
      *      Elimina el nodo pasado como parametro.
      *      Conecta al nodo padre de nodo con su nodo hijo izquierdo.
      */
    void quitarHijoIzquierdo(NodoABB<T1 , T2> *nodo);


    /*
     *  PRE:
     *      *nodo debe contener un *padre con direccion de memoria valida.
     *      *nodo debe contener un *derecho con direccion de memoria valida.
     *
     *  POST:
     *      Libera la memoria ocupada por *nodo.
     *
     *  Descripcion:
     *      Conecta al nodo padre de nodo con su nodo hijo derecho.
     */
     void quitarHijoDerecho(NodoABB<T1 , T2> *nodo);


     /*
      *  PRE:
      *      *nodo debe contener un *padre con direccion de memoria valida.
      *
      *  POST:
      *      Libera la memoria ocupada por *nodo.
      *
      *  Descripcion:
      *      Elimina el nodo pasado como parametro.
      *      Coloca en nullptr al atributo *izquierdo o *derecho del padre del nodo
      *      dependiendo de si este es hijo izquierdo o derecho respectivamente.
      */
     void quitarHoja(NodoABB<T1 , T2> *nodo);


     /*
      *  PRE:
      *      *nodo debe contener un *padre con direccion de memoria valida.
      *      *nodo debe contener un *izquierdo con direccion de memoria valida.
      *      *nodo debe contener un *derecho con direccion de memoria valida.
      *
      *  POST:
      *      Libera la memoria ocupada por *nodo.
      *
      *  Descripcion:
      *      Elimina el nodo pasado como parametro.
      *      Conecta al nodo padre con el nodo sucesor.
      */
     void quitarNodoConDosHijos(NodoABB<T1 , T2> *nodo);

     /*
      *  PRE: -
      *
      *  POST:
      *      Libera la memoria ocupada por la raiz.
      *      Setea raiz a nullptr.
      *
      *  Descripcion:
      *      Elimina la raiz del diccionario.
      */
     void quitarRaiz();


     /*
      *  PRE:
      *      *nodo : debe ser una direccion de memoria valida.
      *
      *  POST: -
      *
      *  Descripcion:
      *      Retorna el predecesor del nodo.
      */
     NodoABB<T1 , T2> *encuentraMinimo(NodoABB<T1 , T2> *nodo);


     /*
      *  PRE: -
      *
      *  POST:
      *      Libera la memoria de los nodos del diccionario.
      *      Setea raiz en nullptr.
      *
      *  Descripcion:
      *      Elimina todos los nodos del diccionario.
      */
     void limpiar();

public:

     /*
      *  PRE: -
      *
      *  POST: Setea raiz en nullptr.
      *
      *  Descripcion:
      *      Constructor de diccionario.
      */
    Diccionario();


    /*
     *  PRE:
     *      key no debe estar en el diccionario.
     *
     *  POST: -
     *
     *  Descripcion:
     *      Agrega un nodo al diccionario con key como key y personaje como value.
     */
    void agregarPersonaje(T1 key, T2 personaje);

    void agregarPersonaje(Personaje* &nuevo_personaje,int vida,string nombre,int escudo,int energia,string tipo);


    /*
      *  PRE: -
      *
      *  POST: -
      *
      *  Descripcion:
      *      Retorna true si la key se encuentra en el diccionario.
      *      Retorna false si la key no se encuentra en el diccionario
      */
    bool buscar(T1 key);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna el valor de value si la key se encuentra en el diccionario.
     *      Retorna nullptr si la key no se encuentra.
     */
    T2 traer(T1 key);

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Muestra de menor a mayor las key del diccionario.
     */
    void mostrarOrdenados();



    /*
     *  PRE: -
     *
     *  POST:
     *      No libera la memoria de nodo.
     *
     *  Descripcion:
     *      Elimina el nodo que contenga la key pasada como parametros si esta
     *      se encuentra en el diccionario.
     */
    void quitarNodo(T1 key);
    

    /*
     *  PRE: -
     *
     *  POST: -
     *
     *  Descripcion:
     *      Retorna true si raiz es nullptr.
     *      Retorna false si raiz es distinta de nullptr.
     */
    bool vacio();

    /*
     *  PRE: -
     *
     *  POST:
     *      Libera la memoria de los nodos del diccionario.
     *
     *  Descripcion:
     *      Destructor de diccionario.
     *      ELimina todos los nodos .
     */
    ~Diccionario();
};

//template<typename T1, typename T2>
//Diccionario<T1, T2>::Diccionario() {
//    raiz = nullptr;
//}

template<typename T1, typename T2>
Diccionario<T1, T2>::Diccionario(){
	raiz = nullptr;

	leer_archivo();  //si existe un archivo con los personajes, los carga al diccionario, sino crea un diccionario vacio

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
void Diccionario<T1, T2>::quitarHijoDerecho(NodoABB<T1 , T2> *nodo){

    nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getDerecho());
    nodo->getDerecho()->setPadre(nodo->getPadre());

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarHijoIzquierdo(NodoABB<T1 , T2> *nodo){

    nodo->getPadre()->setHijoNuevo(nodo->getPadre(), nodo->getDerecho());
    nodo->getIzquierdo()->setPadre(nodo->getPadre());

    delete nodo;
}

template<typename T1, typename T2>
void Diccionario<T1, T2>::quitarNodoConDosHijos(NodoABB<T1 , T2> *nodo){
    NodoABB<T1, T2> *nodo_predecesor = encuentraMinimo(nodo->getIzquierdo());
    T2 aux_value = nodo->getValue();
    T1 aux_key = nodo->getKey();

    nodo->setValue(nodo_predecesor->getValue());
    nodo->setKey(nodo_predecesor->getKey());

    nodo_predecesor->setValue(aux_value);
    nodo_predecesor->setKey(aux_key);

    if (nodo_predecesor->getIzquierdo() != nullptr) {

        nodo_predecesor->getPadre()->setHijoNuevo(nodo_predecesor->getPadre(), nodo_predecesor->getIzquierdo());
        nodo_predecesor->getIzquierdo()->setPadre(nodo_predecesor->getPadre());
    } else {
        nodo_predecesor->quitarPadre(nodo_predecesor);

    }

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
        quitarHijoDerecho(nodo);
    }

    else if (nodo->hijoIzquierdoUnico()){
        quitarHijoIzquierdo(nodo);
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
