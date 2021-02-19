//
// Created by franco on 8/2/21.
//

#ifndef TP_3_ALGORITMOS_2_CASILLERO_H
#define TP_3_ALGORITMOS_2_CASILLERO_H
#include <iostream>

using namespace std;

class Casillero {
private:
    int pos_x = 0;
    int pos_y = 0;
    string tipo_terreno;
    bool disponible = true;
    int numero = 0;
public:
    Casillero() = default;
    Casillero(int x, int y, string terreno, int numero_casillero);
    void setX( int x);
    void setY(int y);
    string getTerreno();

    void setTerreno(string tipo);
    void cambiarDisponible();
    bool getDisponible();
    int getX();
    int getY();
    int getNumero();
    int distancia(Casillero *casillero);
    void mostrar();
};


#endif //TP_3_ALGORITMOS_2_CASILLERO_H
