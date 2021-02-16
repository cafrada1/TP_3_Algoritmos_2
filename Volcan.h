#ifndef VOLCAN_H_INCLUDED
#define VOLCAN_H_INCLUDED
#include <string>
#include "Casillero.h"

class Volcan:public Casillero{

private:
    std::string simbolo = "Vo";
    std::string terreno = "Volcan";


public:

    std::string obtener_simbolo();
};

#endif // VOLCAN_H_INCLUDED


