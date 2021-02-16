#ifndef MONTANA_H_INCLUDED
#define MONTANA_H_INCLUDED
#include <string>
#include "Casillero.h"

class Montana:public Casillero{

private:
    std::string simbolo = "Mo";
    std::string terreno = "Montana";


public:

    std::string obtener_simbolo();
};

#endif // MONTANA_H_INCLUDED


