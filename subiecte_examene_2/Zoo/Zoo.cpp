//
// Created by Marius Beschieru on 23.04.2024.
//

#include "Zoo.h"

void Zoo::operator+=(Animal *newAnimal) {
    animals.push_back(newAnimal);
}

bool Zoo::operator()(const std::string &name) {
    for (auto animal: animals) {
        if (animal->GetName() == name)
            return true;
    }
    return false;
}

int Zoo::GetTotalAnimals() {
    return animals.size();
}

std::vector<Animal *> Zoo::GetFishes() {
    std::vector<Animal *> fishVector ;
    for (auto animal : animals) {
        if (animal->IsAFish())
            fishVector.push_back(animal);
    }
    return fishVector;
}

std::vector<Animal *> Zoo::GetBirds() {
    std::vector<Animal*> birdsVector ;
    for (auto animal: animals ) {
        if (animal->IsABird())
            birdsVector.push_back(animal);
    }
    return birdsVector;
}

std::vector<Animal *> Zoo::GetMammals() {
    std::vector<Animal*> mammalsVector;
    for (auto animal : animals) {
        if (animal ->IsAMammal())
            mammalsVector.push_back(animal);
    }
    return mammalsVector;
}

std::vector<Feline *> Zoo::GetFelines() {
    std::vector<Feline*> felinesVector;
    for (auto animal : animals) {
        auto checkFeline = dynamic_cast<Feline*>(animal);
        if (checkFeline != nullptr) {
            felinesVector.push_back(checkFeline);
        }
    }
    return felinesVector;
}
