//
// Created by Marius Beschieru on 04.04.2024.
//

#include "Neg.h"

void Neg::print() {
    std::cout << "( - ";
    child->print();
    std::cout << " )";
}

Neg::Neg(Expression *c) {
    child = c;
}

int Neg::compute() {
    return (-1) * child->compute();
}

int Neg::get_children_count() {
    return 1;
}

Expression *Neg::get_child(int index) {
    if (index == 0)
        return child;
    return nullptr;
}

Neg::~Neg() {
    delete child;
}
