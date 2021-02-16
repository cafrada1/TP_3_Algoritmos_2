#ifndef CASILLERO_H_INCLUDED
#define CASILLERO_H_INCLUDED

#include "Personaje.h"
#include "Agua.h"
#include "Fuego.h"
#include "Aire.h"
#include "Tierra.h"


class Casillero{

protected:
    bool ocupado = false;
    Personaje *personaje;
    std::string simbolo = "X";

public:
    virtual std::string obtener_simbolo();

    Personaje* consulta_personaje();

    bool consulta_ocupado();

    void modificar_ocupacion(bool nuevo_estado);




};
#endif // CASILLERO_H_INCLUDED

