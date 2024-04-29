//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef ZOO_LION_H
#define ZOO_LION_H

#include "Feline.h"

class Lion : public Feline {
public:
    std::string GetName() override;

    bool IsAFish() override;

    bool IsABird() override;

    bool IsAMammal() override;

    int GetSpeed() override;
};


#endif //ZOO_LION_H
