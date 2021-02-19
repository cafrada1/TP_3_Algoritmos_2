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
    Vertice() = default;
    Vertice(T1 value);

    T1 getValue();

    void setValue(T1 value);

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
