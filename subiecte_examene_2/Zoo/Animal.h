//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef ZOO_ANIMAL_H
#define ZOO_ANIMAL_H
#include <string>
class Animal {
public:
    virtual std::string GetName() = 0;
    virtual bool IsAFish() = 0;
    virtual bool IsABird() = 0;
    virtual bool IsAMammal() = 0;
};
#endif //ZOO_ANIMAL_H
