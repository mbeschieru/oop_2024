//
// Created by Marius Beschieru on 15.03.2024.
//

#ifndef TEST3_INMULTIRE_H
#define TEST3_INMULTIRE_H


#include "Operatie.h"

class Inmultire : public Operatie{
public:
    Inmultire();
    double getResult(double x, double y) override;
};


#endif //TEST3_INMULTIRE_H
