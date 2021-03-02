//
// Created by franco on 24/11/20.
//

#include "tierra.h"

const int ENERGIA_RECUPERADA = 10;

const string NOMBRE_ALIMENTO = "Hierbas";

Tierra::Tierra(int vida, string nombre, unsigned int escudo, unsigned int energia, string tipo) : Personaje(
        vida, nombre,
        escudo, energia, tipo) {

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





void Tierra::defenderse(Tablero &tablero){
    if (energia >= COSTO_ENERGIA_DEFENSA){
        cambiarEscudo(ESCUDO_EXTRA);
        defensa_especial = true;
        cout<<"Por un turno "<<nombre<<" tendra "<<escudo<<" puntos de escudo"<<endl;
    }
}
bool Tierra::validarEnergiaAtaque(){
    bool valido = false;
    if (energia >= COSTO_ENERGIA_ATAQUE){
        energia -= COSTO_ENERGIA_ATAQUE;
        valido = true;
    }
    return valido;
}

bool Tierra::validarEnergiaDefensa(){
    bool valido = false;
    if (energia >= COSTO_ENERGIA_DEFENSA){
        energia -= COSTO_ENERGIA_DEFENSA;
        valido = true;
    }
    return valido;
}

void Tierra::objetivos(Tablero &tablero, string objetivos[]){
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
            string personaje_atacado = tablero.consulta_personaje(fila-1,columna-1);
            objetivos[0] = personaje_atacado;
        }else{
            cout<<" No puedes atacar a alguien de tu equipo!"<<endl;
        }
    }else{
        cout<<" ¡Has fallado! El casillero estaba vacío"<<endl;
    }
}




int Tierra::calculo_ataque(int posicion_enemigo, string elemento, int defensa) {
    int fila = (posicion-1)/8;
    int columna = (posicion-1)%8;
    int fila_enemigo = (posicion_enemigo-1)/8;
    int columna_enemigo = (posicion_enemigo-1)%8;
    int ataque;
    if(((fila_enemigo-2) < fila < (fila_enemigo+2)) && ((columna_enemigo-2) < columna < (columna_enemigo+2))){
        ataque = ATAQUE_CERCANO;
    }else if(((fila_enemigo-4) < fila < (fila_enemigo+4)) && ((columna_enemigo-4) < columna < (columna_enemigo+4))){
        ataque = ATAQUE_MEDIANO;
    }else if(((fila_enemigo-6) < fila < (fila_enemigo+6)) && ((columna_enemigo-6) < columna < (columna_enemigo+6))){
        ataque = ATAQUE_LEJANO;
    }
    if (elemento == elemento_fortaleza){
        ataque += FORTALEZA;
    }else if (elemento == elemento_debilidad){
        ataque = DEBILIDAD;
    }
    if (defensa == 1){
        ataque = (ataque*90)/100; // Saca 10% del ataque original
    }else if (defensa == 2){
        ataque = (ataque*80)/100;  //Saca 20% del ataque original
    }else if (defensa >= 3){
        ataque = (ataque*20)/100;  //Saca 80% del ataque original
    }
    return ataque;


}


