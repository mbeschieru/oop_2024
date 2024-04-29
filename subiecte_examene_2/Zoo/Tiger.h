//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef ZOO_TIGER_H
#define ZOO_TIGER_H

#include "Feline.h"

class Tiger : public  Feline{
public:
    std::string GetName() override;

    bool IsAFish() override;

    bool IsABird() override;

    bool IsAMammal() override;

    int GetSpeed() override;
};


#endif //ZOO_TIGER_H
