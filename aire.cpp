//
// Created by franco on 18/11/20.
//

#include "aire.h"

Aire::Aire(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo) : Personaje(vida,
                                                                                                                 nombre,
                                                                                                                 escudo,
                                                                                                                 energia,
                                                                                                                 tipo) {

}

void Aire::alimentarse() {
    cout << "\n\n" << obtenerNombre() << " no necesita alimentarse\n" << endl;
}



void Aire::defenderse(){
    cout<<"hola"<<endl;

}
bool Aire::validarEnergia(){
    bool valido = false;
    if (energia >= COSTO_ENERGIA_ATAQUE){
        energia -= COSTO_ENERGIA_ATAQUE;
        valido = true;
    }
    return valido;

}

void Aire::objetivos(Tablero &tablero, string objetivos[]){

    int fila_inicio = 0, fila_final = 8;

    int posicion_vector = 0;
    string personaje_atacado;
    for (int i = fila_inicio; i <= fila_final; i++){
        for (int j =0; i < 8; i++){
            bool disponible = tablero.consulta_disponible(i, j);
            if (disponible == false){
                int equipo_enemigo = tablero.consulta_equipo(i, j);
                if (equipo_enemigo != equipo){
                    string personaje_atacado = tablero.consulta_personaje(i,j);
                    objetivos[posicion_vector] = personaje_atacado;
                    posicion_vector++;
                }
            }
        }
    }


}

int Aire::calculo_ataque(int posicion, string elemento, int defensa) {
    int ataque = ATAQUE;

    if (elemento == elemento_fortaleza){
        ataque = FORTALEZA;
    }else if (elemento == elemento_debilidad){
        ataque = DEBILIDAD;
    }
    if (defensa == 1){
        ataque = (ataque*90)/100; // Saca 10% del ataque original
    }else if (defensa == 2){
        ataque = (ataque*80)/100;  //Saca 20% del ataque original
    }else if (defensa >= 3){
        ataque = (ataque*20)/100;   //Saca 80% del ataque original    }
    }
    return ataque;


}