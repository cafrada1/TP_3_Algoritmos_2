//
// Created by franco on 18/11/20.
//

#include "fuego.h"

const string NOMBRE_ALIMENTO = "Madera";

const int VIDA_RECUPERADA = 15;

Fuego::Fuego(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo, int posicion, Tablero tablero) : Personaje(vida,
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

void tierra::atacar(int fila, int columna){

    bool ocupado = tablero.consulta_ocupado(fila, columna);
    int ataque;
    if (ocupado == true){
        if (energia >= COSTO_ENERGIA_ATAQUE){
            if(((posicion[0]-1) < fila < (posicion[0]+1)){
                energia -= COSTO_ENERGIA_ATAQUE;
                personaje *personaje_atacado = tablero.consulta_personaje(fila,columna);
                string elemento_personaje_atacado = personaje_atacado->obtenerTipo();
                string nombre_personaje_atacado = personaje_atacado->obtenerNombre();



                calculo_ataque(personaje personaje_atacado, ataque);
                personaje_atacado->cambiarVida(ataque);
                vida_personaje_atacado = personaje_atacado->obtenerVida();
                if (vida_personaje_atacado <= 0){
                    cout<<"Has atacado a "<< nombre_personaje_atacado << " y lo has matado!"
                    tablero.
                }else{
                    cout<<"Has atacado a "<< nombre_personaje_atacado << " y le quedan "<< vida_personaje_atacado <<" !"<<endl;
                }
            }else{
                cout<<"¡La casilla seleccionada está fuera del rango de tu ataque!"<<endl;
            }
        }else{
            cout<<"¡No tienes suficiente energía para atacar!"<<endl;
        }
    }else{
        cout<<"¡Has fallado! El casillero estaba vacío"<<endl;
    }
}



void Fuego::calculo_ataque(personaje *personaje_atacado){

    int ataque = ATAQUE;
    string elemento_personaje_atacado = personaje_atacado->obtenerTipo();
    int defensa_personaje_atacado = personaje_atacado->obtenerDefensa();

    if (elemento_personaje_atacado == "aire"){
        int ataque = FORTALEZA;
    }else if (elemento_personaje_atacado == "agua"){
        int ataque = DEBILIDAD;
    }
    if (defensa_personaje_atacado == 1){
        ataque = (ataque*90)/100 // Saca 10% del ataque original
    }else if (defensa_personaje_atacado == 2){
        ataque = (ataque*80)/100  //Saca 20% del ataque original
    }else if (defensa_personaje_atacado >= 3){
        ataque = (ataque*20)/100   //Saca 80% del ataque original
    }

    personaje_atacado->cambiarVida(ataque);
}


void Fuego::defenderse(){
    if (energia >= COSTO_ENERGIA_DEFENSA){
        cambiarVida(DEFENSA_PERSONAL);
    }


}
