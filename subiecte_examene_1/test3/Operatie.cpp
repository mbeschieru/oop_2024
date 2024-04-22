//
// Created by Marius Beschieru on 15.03.2024.
//

#include "Operatie.h"

char *Operatie::getName() {
    return name;
}

int Operatie::getSize(const char *value) {
    int i = 0;
    while (value[i] != '\0')
        i++;
    return i;
}

void Operatie::setName(const char *value) {
    int size = getSize(value);
    this->name = new char[size];
    for (int i = 0; i < size; i++)
        this->name[i] = value[i];
    this->name[size] = '\0';
}
