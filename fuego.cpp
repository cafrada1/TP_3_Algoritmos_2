//
// Created by franco on 18/11/20.
//

#include "fuego.h"

const string NOMBRE_ALIMENTO = "Madera";

const int VIDA_RECUPERADA = 15;

Fuego::Fuego(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo) : Personaje(vida,
                                                                                                                   nombre,
                                                                                                                   escudo,
                                                                                                                   energia,
                                                                                                                   tipo) {

}

void Fuego::alimentarse() {

    unsigned int vida_anterior = obtenerVida();

    cambiarVida(VIDA_RECUPERADA);

    if (vida_anterior < obtenerVida()) {
        cout << " \n\n" << obtenerNombre() << " se ha alimentado con " << NOMBRE_ALIMENTO << endl;
        cout << "Ha recuperado " << obtenerVida() - vida_anterior << " de vida\n" << endl;
    } else {
        cout << " \n\n" << obtenerNombre() << " ya esta sano. No puede alimentarse mas\n" << endl;
    }

}

void Fuego::defenderse(){
    if (energia >= COSTO_ENERGIA_DEFENSA){
        cambiarVida(DEFENSA_PERSONAL);
    }


}
bool Fuego::validarEnergia(){
    bool valido = false;
    if (energia >= COSTO_ENERGIA_ATAQUE){
        energia -= COSTO_ENERGIA_ATAQUE;
        valido = true;
    }
    return valido;



}

void Fuego::objetivos(Tablero &tablero, string objetivos[]){
    int fila = posicion/8;
    int fila_inicio = fila-1, fila_final = fila+1;
    if (fila-1 < 0){
        fila_inicio = 0;
    }else if (fila+1 > 7){
        fila_final = 7;
    }

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

int Fuego::calculo_ataque(int posicion, string elemento, int defensa) {
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
        ataque = (ataque*20)/100;   //Saca 80% del ataque original
    }

    return ataque;


}


