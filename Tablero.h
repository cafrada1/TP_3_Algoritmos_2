#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Casillero.h"
#include "Personaje.h"


class Tablero{

    protected:

        const int TABLERO[8][8] = { {1,1,3,3,3,6,2,2},
                                    {1,1,3,6,2,2,2,2},
                                    {3,2,2,2,2,3,3,3},
                                    {2,5,5,5,1,6,5,5},
                                    {5,5,6,5,5,5,5,3},
                                    {5,5,5,6,4,4,4,3},
                                    {3,4,4,4,4,1,1,1},
                                    {3,3,4,3,6,1,1,1}};

        Casillero *tablero[8][8];



    public:

        void cargar_casillero(int terreno, int fila, int columna );

        void mostrar();

        void cargar_tablero();

        void calculo_adyacentes(int fila, int columna);

        bool consulta_ocupado(int fila, int columna);

        Personaje consulta_personaje(int fila, int columna);
};

#endif // TABLERO_H_INCLUDED
