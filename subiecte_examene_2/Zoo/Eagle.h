//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef ZOO_EAGLE_H
#define ZOO_EAGLE_H

#include "Animal.h"
class Eagle : public Animal{
public:
    std::string GetName() override;

    bool IsAFish() override;

    bool IsABird() override;

    bool IsAMammal() override;
};


#endif //ZOO_EAGLE_H
