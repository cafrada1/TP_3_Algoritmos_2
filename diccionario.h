//
// Created by franco on 31/1/21.
//

#ifndef TP_3_ALGORITMOS_2_DICCIONARIO_H
#define TP_3_ALGORITMOS_2_DICCIONARIO_H

#include "Personaje.h"


template<typename Dato1, typename Dato2>
class Diccionario{
private:
    Dato1 clave;

    Dato2 valor;

public:
    Diccionario(Dato1 clave, Dato2 valor);

};

template<typename Dato1, typename Dato2>
Diccionario<Dato1,Dato2>::Diccionario(Dato1 clave, Dato2 valor){
    this->clave = clave;
    this->valor = valor;
}


#endif //TP_3_ALGORITMOS_2_DICCIONARIO_H
