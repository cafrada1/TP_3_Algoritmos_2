//
// Created by franco on 8/2/21.
//

#ifndef TP_3_ALGORITMOS_2_VERTICE_H
#define TP_3_ALGORITMOS_2_VERTICE_H

template <typename T1>
class Vertice{
private:
    T1 value;

public:

    /*
     *  PRE: -
     *  POST: No asigna ningun valor al atributo value.
     *  Descripcion:
     *      Constructor por default de Vertice.
     */
    Vertice() = default;

    /*
     *  PRE: -
     *  POST: -
     *  Descripcion:
     *      Constructor de vertice que setea el atributo value.
     */
    Vertice(T1 value);

    /*
     *  PRE: -
     *  POST: -
     *  Descripcion:
     *      Retorna el valor del atributo value.
     */
    T1 getValue();

    /*
     *  PRE: -
     *  POST: -
     *  Descripcion:
     *      Setea el atributo value al valor pasado como parametro.
     */
    void setValue(T1 value);

    /*
     *  PRE: -
     *  POST:
     *      No aplica delete al valor de value.
     *  Descripcion:
     *      Destructor por default de vertice.
     */
    ~Vertice() = default;
};

template <typename T1>
Vertice<T1>::Vertice(T1 value){
    this->value = value;
}

template <typename T1>
T1 Vertice<T1>::getValue(){
    return value;
};

template<typename T1>
void Vertice<T1>::setValue(T1 value) {
    this->value = value;
}

#endif //TP_3_ALGORITMOS_2_VERTICE_H
