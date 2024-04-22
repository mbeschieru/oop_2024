//
// Created by Marius Beschieru on 04.04.2024.
//

#ifndef PROPOZITIE_PROPOZITIE_H
#define PROPOZITIE_PROPOZITIE_H

#include "Utils.h"

class Propozitie {
private:
    char **cuvinte;
    int cuvinte_count, caractere_count, vowals_count, number_count;
    static constexpr int MAX_SIZE = 64;

    void GetNumberCount();

    void computeAll(const char *string);

public:
    Propozitie(const char *string);

    ~Propozitie();

    int operator[](const char *string);

    char *operator[](int index);

    void Set(const char *string);

    int operator()(int index);

};


#endif //PROPOZITIE_PROPOZITIE_H
