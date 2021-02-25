#include "diccionario.h"
#include <string>

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//PRE: El archivo existe y contiene al menos un personaje.
//POS: Lee el archivo, línea por línea
void leer_archivo(Diccionario<string, Personaje *> &personajes);


//PRE: Recibe una línea conformada por 4 palabras separadas por comas, en donde los 2 ultimos valores son numeros enteros.
//POS: Separa los valores y convierte los ultimos 2 a enteros.
void procesar_linea_archivo(string linea, Diccionario<string, Personaje *> &personajes);


//PRE:
//POS: Carga los atributos al personaje.
void cargar_atributos_personaje(Personaje* &nuevo_personaje,int vida,string nombre,int escudo,int energia,string tipo);


//PRE: El dato de la lista debe ser de tipo Personaje*
//POS: Agrega el personaje a la lista en la próxima posición de donde estaba el último.
void agregar_personaje_a_diccionario(Diccionario<string, Personaje *> &personajes, Personaje* &nuevo_personaje);




#endif /* FUNCIONES_H_ */
