#include <iostream>

#include "Casillero.h"
#include "personaje.h"

using namespace std;

string Casillero::obtener_simbolo (){
    return "XX";
}


Personaje* Casillero::consulta_personaje(){
    return personaje;


}

bool Casillero::consulta_ocupado(){
    return ocupado;
}

void Casillero::modificar_ocupacion(bool nuevo_estado){
    ocupado = nuevo_estado;
}
