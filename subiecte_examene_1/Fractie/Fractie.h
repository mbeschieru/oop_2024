//
// Created by Marius Beschieru on 04.04.2024.
//

#ifndef FRACTIE_FRACTIE_H
#define FRACTIE_FRACTIE_H

#include <iostream>
#include "utils.h"

class Fractie {
private:
    int up, down;
public:
    Fractie(int up, int down);

    Fractie(const char *string);

    void print();

    Fractie operator+(const Fractie &other) const;

    Fractie operator-(const Fractie &other) const;

    Fractie operator*(const Fractie &other) const;

    Fractie simplify() const;

    bool operator==(const Fractie &other);

    int operator[](const char *string) const;

};


#endif //FRACTIE_FRACTIE_H
