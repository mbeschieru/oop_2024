//
// Created by Marius Beschieru on 23.04.2024.
//

#include "StringData.h"

void StringData::Add(std::string toAdd) {
    value += toAdd;
}

bool StringData::Substract(int toSubstract) {
    if (value.size() < toSubstract) {
        std::cout << "StringData: len(" << value << ") < " << toSubstract << '\n';
        return false;
    }
    value.erase(value.end() - toSubstract, value.end());
    return true;
}

void StringData::Print() {
    std::cout << GetName() << " = " << value << " ; ";
}

StringData::StringData(std::string name, std::string value) : Entry(name) {
    this->value = value;
}
