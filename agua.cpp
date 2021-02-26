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


/*
void Agua::atacar(Tablero &tablero, int equipo){
   Personaje *personaje_atacado;
    bool ocupado = tablero.consulta_ocupado(fila, columna);

    if (ocupado == true){
        if (energia >= COSTO_ENERGIA_ATAQUE){
            energia -= COSTO_ENERGIA_ATAQUE;
            Personaje *personaje_atacado = tablero.consulta_personaje(fila,columna);
            string nombre_personaje_atacado = personaje_atacado->obtenerNombre();
            calculo_ataque(Personaje *personaje_atacado);
            calculo_ataque(personaje_atacado);
            vida_personaje_atacado = personaje_atacado->obtenerVida();
            if (vida_personaje_atacado <= 0){
                cout<<"Has atacado a "<< nombre_personaje_atacado << " y lo has matado!"

            }else{
                cout<<"Has atacado a "<< nombre_personaje_atacado << " y le quedan "<< vida_personaje_atacado <<" !"<<endl;
            }
        }else{
            cout<<"¡No tienes suficiente energía para atacar!"<<endl;
        }
    }else{
        cout<<"¡Has fallado! El casillero estaba vacío"<<endl;
    }*/



/*
void Agua::calculo_ataque(){

    int ataque = ATAQUE;
    string elemento_personaje_atacado = personaje_atacado->obtenerTipo();
    int defensa_personaje_atacado = personaje_atacado->obtenerDefensa();

    if (elemento_personaje_atacado == "fuego"){
        int ataque = FORTALEZA_FUEGO;
    }else if (elemento_personaje_atacado == "tierra"){
        int ataque = DEBILIDAD_TIERRA;
    }
    if (defensa_personaje_atacado == 1){
        ataque = (ataque*90)/100 // Saca 10% del ataque original
    }else if (defensa_personaje_atacado == 2){
        ataque = (ataque*80)/100  //Saca 20% del ataque original
    }else if (defensa_personaje_atacado >= 3){
        ataque = (ataque*20)/100   //Saca 80% del ataque original
    }

    personaje_atacado->cambiarVida(ataque);*/


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

    bool disponible = tablero.consulta_disponible(fila, columna);
    if (disponible == false){
        string personaje_atacado = tablero.consulta_personaje(fila,columna);
        objetivos[0] = personaje_atacado;
    }else{
        cout<<" ¡Has fallado! El casillero estaba vacío"<<endl;
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

