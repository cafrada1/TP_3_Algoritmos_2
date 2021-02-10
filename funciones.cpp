#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "diccionario.h"
#include "funciones.h"
#include "personaje.h"
#include "agua.h"
#include "fuego.h"
#include "tierra.h"
#include "aire.h"

const string PATH_ARCHIVO = "personajes.csv";   //"../personajes.csv" para la terminal o "personajes.csv" para un IDE

using namespace std;


void leer_archivo(Diccionario<string, Personaje *> &personajes){
	ifstream archivo;
	archivo.open(PATH_ARCHIVO);
	if(!archivo){
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
	else{
		string linea;

		while(getline(archivo,linea)){
			//cout << linea << endl;
			procesar_linea_archivo(linea, personajes);
		}
		archivo.close();
	}
}

void procesar_linea_archivo(string linea, Diccionario<string, Personaje *> &personajes){
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

	int energia = rand()% 20;

	cout << "punto 2" << endl;

	cargar_atributos_personaje(nuevo_personaje, vida_numero, nombre, escudo_numero, energia, tipo);

	cout << "punto 3" << endl;

	agregar_personaje_a_diccionario(personajes,nuevo_personaje);

	cout << "punto 4" << endl;

}


void agregar_personaje_a_diccionario(Diccionario<string, Personaje *> &personajes, Personaje* &nuevo_personaje){
	//int cantidad_personajes_en_lista = personajes.obtener_cantidad();
	string nombre_personaje;
	nombre_personaje = nuevo_personaje->obtenerNombre();
	personajes.agregarPersonaje(nombre_personaje,nuevo_personaje);
}



void cargar_atributos_personaje(Personaje* &nuevo_personaje,int vida,string nombre,int escudo,int energia,string tipo){
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

/*
void eliminar_diccionario(Diccionario<string, Personaje *> &personajes){


	for(int i = 1; i<= personajes.obtener_cantidad(); i++){  //Borrar la lista.
		Personaje* personaje = personajes.consulta(i);
		//cout << personaje->obtener_nombre() << endl;;      //Para ver que personajes se eliminan
		delete personaje;
	}
}
*/

