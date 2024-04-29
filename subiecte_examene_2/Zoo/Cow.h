//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef ZOO_COW_H
#define ZOO_COW_H

#include "Animal.h"

class Cow : public Animal{
public:
    std::string GetName() override;

    bool IsAFish() override;

    bool IsABird() override;

    bool IsAMammal() override;
};


#endif //ZOO_COW_H
