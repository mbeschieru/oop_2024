//
// Created by Marius Beschieru on 23.04.2024.
//

#include "IntegerData.h"

void IntegerData::Add(std::string toAdd) {
    value += std::stoi(toAdd);
}

bool IntegerData::Substract(int toSubstract) {
    if (value < toSubstract) {
        std::cout << "IntegerData:" << value << " < " << toSubstract << '\n';
        return false;
    }
    value-=toSubstract;
    return true;
}

void IntegerData::Print() {
    std::cout << GetName() << " = " << value << " ; ";
}

IntegerData::IntegerData(std::string name, std::string value) : Entry(name) {
    this->value = std::stoi(value);
}
