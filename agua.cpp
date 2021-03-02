//
// Created by franco on 24/11/20.
//

#include "agua.h"

const int ENERGIA_RECUPERADA = 10;
const int MAXIMO_ALIMENTOS = 3;

const string NOMBRE_ALIMENTO = "Plancton";

Agua::Agua(unsigned int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo) : Personaje(vida,
                                                                                                                 nombre,
                                                                                                                 escudo,
                                                                                                                 energia,
                                                                                                                 tipo) {

}

void Agua::alimentarse() {
    unsigned int energia_anterior = obtenerEnergia();

    if (cantidad_alimentado < MAXIMO_ALIMENTOS) {
        cambiarEnergia(ENERGIA_RECUPERADA);

        if (energia_anterior < obtenerEnergia()) {
            cout << "\n\n" << obtenerNombre() << " se ha alimentado con " << NOMBRE_ALIMENTO << endl;
            cout << "Ha recuperado " << obtenerEnergia() - energia_anterior << " de energia\n" << endl;
            cantidad_alimentado++;
        }
    } else {
        cout << "\n\n" << obtenerNombre() << " ya esta lleno. No puede alimentarse mas\n" << endl;
    }
}


bool Agua::validarEnergiaAtaque(){
    bool valido = false;
    if (energia >= COSTO_ENERGIA_ATAQUE){
        energia -= COSTO_ENERGIA_ATAQUE;
        valido = true;
    }
    return valido;
}

bool Agua::validarEnergiaDefensa(){
    bool valido = false;
    if (energia >= COSTO_ENERGIA_DEFENSA){
        energia -= COSTO_ENERGIA_DEFENSA;
        valido = true;
    }
    return valido;

}



void Agua::objetivos(Tablero &tablero, string objetivos[]){
    int fila, columna;
    cout<<"Ingrese la fila y la columna donde quiere atacar con "<<nombre<<endl;
    cout<<"Fila: ";
    cin >>fila;
    cout<<"Columna: ";
    cin>>columna;
    --fila;
    --columna;
    bool disponible = tablero.consulta_disponible(fila, columna);
    if (disponible == false){
        int equipo_enemigo = tablero.consulta_equipo(fila, columna);
        if (equipo_enemigo != equipo){
            string personaje_atacado = tablero.consulta_personaje(fila,columna);
            objetivos[0] = personaje_atacado;
        }else{
            cout<<" No puedes atacar a alguien de tu equipo!"<<endl;
        }

    }else{
        cout<<" �Has fallado! El casillero estaba vac�o"<<endl;
    }
}

int Agua::calculo_ataque(int posicion, string elemento, int defensa) {


    int ataque = ATAQUE;
    if (elemento == elemento_fortaleza){
        ataque = FORTALEZA_FUEGO;
    }else if (elemento == elemento_debilidad){
        ataque = DEBILIDAD_TIERRA;
    }
    if (defensa == 1){
        ataque = (ataque*90)/100; // Saca 10% del ataque original
    }else if (defensa == 2){
        ataque = (ataque*80)/100; //Saca 20% del ataque original
    }else if (defensa >= 3){
        ataque = (ataque*20)/100;   //Saca 80% del ataque original
    }
    return ataque;
}

void Agua::defenderse(Tablero &tablero){
    if (energia >= COSTO_ENERGIA_DEFENSA){
        cambiarVida(DEFENSA_PERSONAL);
    }


}

