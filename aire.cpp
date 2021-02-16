//
// Created by franco on 18/11/20.
//

#include "aire.h"

Aire::Aire(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo, int posicion, Tablero tablero ) : Personaje(vida,
                                                                                                                 nombre,
                                                                                                                 escudo,
                                                                                                                 energia,
                                                                                                                 tipo,
                                                                                                                 posicion,
                                                                                                                 tablero) {

}

void Aire::alimentarse() {
    cout << "\n\n" << obtenerNombre() << " no necesita alimentarse\n" << endl;
}



void Aire::atacar(){


}





void Aire::calculo_ataque(Personaje *personaje_atacado){

    int ataque = ATAQUE;
    string elemento_personaje_atacado = personaje_atacado->obtenerTipo();
    int defensa_personaje_atacado = personaje_atacado->obtenerDefensa();

    if (elemento_personaje_atacado == "agua"){
        int ataque = FORTALEZA;
    }else if (elemento_personaje_atacado == "aire"){
        int ataque = DEBILIDAD;
    }
    if (defensa_personaje_atacado == 1){
        ataque = (ataque*90)/100; // Saca 10% del ataque original
    }else if (defensa_personaje_atacado == 2){
        ataque = (ataque*80)/100;  //Saca 20% del ataque original
    }else if (defensa_personaje_atacado >= 3){
        ataque = (ataque*20)/100;   //Saca 80% del ataque original
    }

    personaje_atacado->cambiarVida(ataque);
}




void Aire::defenderse(){
    if (energia >= MINIMO_ENERGIA_DEFENSA){
        cambiarVida(DEFENSA_PERSONAL);
        //FALTA PONER DEFENSA A EQUIPO !!!!!
    }


}
