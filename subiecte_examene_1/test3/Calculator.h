//
// Created by Marius Beschieru on 15.03.2024.
//

#ifndef TEST3_CALCULATOR_H
#define TEST3_CALCULATOR_H

#include <iostream>
#include "Operatie.h"

class Calculator {
private:
    int size;
    static constexpr int MAX_SIZE = 4;

    static bool compareName(const char *nume1, const char *nume2);

    Operatie **operatii;
public:
    Calculator();

    ~Calculator();

    void operator+=(Operatie *operatie);

    void operator-=(const char *nume);

    bool operator[](const char *nume);

    explicit operator int();

    void Compute(double x, double y);


};


#endif //TEST3_CALCULATOR_H
