//
// Created by Marius Beschieru on 15.03.2024.
//

#ifndef TEST3_SCADERE_H
#define TEST3_SCADERE_H


#include "Operatie.h"

class Scadere : public Operatie{
public:
    Scadere();
    double getResult(double x, double y) override;
};


#endif //TEST3_SCADERE_H
