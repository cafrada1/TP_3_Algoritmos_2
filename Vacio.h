#ifndef VACIO_H_INCLUDED
#define VACIO_H_INCLUDED
#include <string>
#include "Casillero.h"

class Vacio:public Casillero{

private:
    std::string simbolo = "Va";
    std::string terreno = "Vacio";


public:

    std::string obtener_simbolo();
};

#endif // VACIO_H_INCLUDED


