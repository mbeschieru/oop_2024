//
// Created by Marius Beschieru on 04.04.2024.
//

#include "Sub.h"


void Sub::print() {
    std::cout << "(";
    left->print();
    std::cout << " - ";
    right->print();
    std::cout << " )";
}

Sub::Sub(Expression *l, Expression *r) {
    left = l;
    right = r;
}

int Sub::compute() {
    return left->compute() - right->compute();
}

int Sub::get_children_count() {
    return 2;
}

Expression *Sub::get_child(int index) {
    if (index == 0)
        return left;
    if (index == 1)
        return right;
    return nullptr;
}

Sub::~Sub() {
    delete left;
    delete right;
}
