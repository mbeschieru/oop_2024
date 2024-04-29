//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef ZOO_ZOO_H
#define ZOO_ZOO_H

#include <vector>
#include "Animal.h"
#include "Feline.h"

class Zoo {
private:
    std::vector<Animal*> animals;
public:
    Zoo() = default;
    void operator +=(Animal* newAnimal);
    bool operator()(const std::string& name);
    int GetTotalAnimals();
    std::vector<Animal*> GetFishes();
    std::vector<Animal*>GetBirds();
    std::vector<Animal*>GetMammals();
    std::vector<Feline*>GetFelines();
};


#endif //ZOO_ZOO_H
