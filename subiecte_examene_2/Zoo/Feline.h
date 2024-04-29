//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef ZOO_FELINE_H
#define ZOO_FELINE_H

#include "Animal.h"

class Feline : public Animal {
public:
    virtual int GetSpeed() = 0;
};

#endif //ZOO_FELINE_H
