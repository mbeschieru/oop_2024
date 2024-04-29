//
// Created by Marius Beschieru on 23.04.2024.
//

#include "Entry.h"

Entry::Entry(std::string name) {
    this->name = name;
}

std::string Entry::GetName() {
    return name;
}
