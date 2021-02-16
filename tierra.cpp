//
// Created by franco on 24/11/20.
//

#include "tierra.h"

const int ENERGIA_RECUPERADA = 10;

const string NOMBRE_ALIMENTO = "Hierbas";

Tierra::Tierra(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo, int posicion, Tablero tablero) : Personaje(
        vida, nombre,
        escudo, energia, tipo, posicion) {

}

void Tierra::alimentarse() {
    unsigned int energia_anterior = obtenerEnergia();

    cambiarEnergia(ENERGIA_RECUPERADA);

    if (energia_anterior < obtenerEnergia()) {
        cout << " \n\n" << obtenerNombre() << " se ha alimentado con " << NOMBRE_ALIMENTO << endl;
        cout << "Ha recuperado " << obtenerEnergia() - energia_anterior << " de energia\n" << endl;
    } else {
        cout << " \n\n" << obtenerNombre() << " ya esta lleno. No puede alimentarse mas\n" << endl;
    }
}

void tierra::atacar(int fila, int columna){

    bool ocupado = tablero.consulta_ocupado(fila, columna);
    int ataque;
    if (ocupado == true){
        if (energia >= COSTO_ENERGIA_ATAQUE){
            energia -= COSTO_ENERGIA_ATAQUE;
            personaje *personaje_atacado = tablero.consulta_personaje(fila,columna);
            string elemento_personaje_atacado = personaje_atacado->obtenerTipo();
            string nombre_personaje_atacado = personaje_atacado->obtenerNombre();

            if(((posicion[0]-2) < fila < (posicion[0]+2)) && ((posicion[1]-2) < columna < (posicion[1]+2))){
                ataque = ATAQUE_CERCANO;
            }else if(((posicion[0]-4) < fila < (posicion[0]+4)) && ((posicion[1]-4) < columna < (posicion[1]+4))){
                ataque = ATAQUE_MEDIANO;
            }else if(((posicion[0]-6) < fila < (posicion[0]+6)) && ((posicion[1]-6) < columna < (posicion[1]+6))){
                ataque = ATAQUE_LEJANO;
            }
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
            cout<<"¡No tienes suficiente energía para atacar!"<<endl;
        }
    }else{
        cout<<"¡Has fallado! El casillero estaba vacío"<<endl;
    }
}


void tierra::calculo_ataque(personaje *personaje_atacado, ataque){


    string elemento_personaje_atacado = personaje_atacado->obtenerTipo();
    int defensa_personaje_atacado = personaje_atacado->obtenerDefensa();

    if (elemento_personaje_atacado == "agua"){
        int ataque += FORTALEZA;
    }else if (elemento_personaje_atacado == "aire"){
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




void Tierra::defenderse(){
    if (energia >= MINIMO_ENERGIA_DEFENSA){
        cambiarVida(DEFENSA_PERSONAL);
        //FALTA PONER DEFENSA A EQUIPO !!!!!
    }


}
