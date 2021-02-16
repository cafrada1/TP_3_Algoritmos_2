#ifndef CAMINO_H_INCLUDED
#define CAMINO_H_INCLUDED
#include <string>
#include "Casillero.h"

class Camino:public Casillero{

private:
    std::string simbolo = "Ca";
    std::string terreno = "Camino";


public:

    std::string obtener_simbolo();
};

#endif // CAMINO_H_INCLUDED

