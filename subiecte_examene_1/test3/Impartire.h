//
// Created by Marius Beschieru on 15.03.2024.
//

#ifndef TEST3_IMPARTIRE_H
#define TEST3_IMPARTIRE_H


#include "Operatie.h"

class Impartire : public Operatie {
public:
    Impartire();
    double getResult(double x, double y) override;
};


#endif //TEST3_IMPARTIRE_H
