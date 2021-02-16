#ifndef LAGO_H_INCLUDED
#define LAGO_H_INCLUDED
#include <string>
#include "Casillero.h"

class Lago:public Casillero{

private:
    std::string simbolo = "La";
    std::string terreno = "Lago";


public:

    std::string obtener_simbolo();
};

#endif // LAGO_H_INCLUDED

