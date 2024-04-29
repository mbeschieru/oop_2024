//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef ZOO_SHARK_H
#define ZOO_SHARK_H

#include "Animal.h"

class Shark : public Animal {
public:
    std::string GetName() override;

    bool IsAFish() override;

    bool IsABird() override;

    bool IsAMammal() override;
};


#endif //ZOO_SHARK_H
