//
// Created by Marius Beschieru on 15.03.2024.
//

#include "Calculator.h"

Calculator::Calculator() {
    this->size = 0;
    operatii = new Operatie *[4];
}

void Calculator::operator+=(Operatie *operatie) {
    if (size == MAX_SIZE)
        return;
    for (int i = 0; i < size; i++)
        if (compareName(operatii[i]->getName(), operatie->getName()))
            return;
    operatii[size++] = operatie;
}

bool Calculator::compareName(const char *nume1, const char *nume2) {
    int size1 = Operatie::getSize(nume1);
    int size2 = Operatie::getSize(nume2);
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++)
        if (nume1[i] != nume2[i])
            return false;
    return true;
}

void Calculator::Compute(double x, double y) {
    for (int i = 0; i < size; i++)
        std::cout << operatii[i]->getName() << "(" << x << "," << y << ") = " << operatii[i]->getResult(x, y) << '\n';
}

void Calculator::operator-=(const char *nume) {
    if (size == 0)
        return;
    for (int i = 0; i < size; i++)
        if (compareName(operatii[i]->getName(), nume)) {
            for (int j = i; j < size - 1; j++) {
                operatii[j] = operatii[j + 1];
            }
            operatii[size - 1] = nullptr;
            size--;
            break;
        }
}

bool Calculator::operator[](const char *nume) {
    for (int i = 0; i < size; i++)
        if (compareName(operatii[i]->getName(), nume))
            return true;
    return false;
}

Calculator::operator int() {
    return size;
}

Calculator::~Calculator() {
    delete[] operatii;
    size = 0;
}
