//
// Created by Marius Beschieru on 15.03.2024.
//

#ifndef TEST3_ADUNARE_H
#define TEST3_ADUNARE_H


#include "Operatie.h"

class Adunare : public Operatie{
public:
    Adunare();
    double getResult(double x, double y) override;
};


#endif //TEST3_ADUNARE_H
