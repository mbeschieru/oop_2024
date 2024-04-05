//
// Created by Marius Beschieru on 04.04.2024.
//

#include "Add.h"

void Add::print() {
    std::cout << "(";
    left->print();
    std::cout << " + ";
    right->print();
    std::cout << " )";
}

Add::Add(Expression *l, Expression *r) {
    left = l;
    right = r;
}

int Add::compute() {
    return left->compute() + right->compute();
}

int Add::get_children_count() {
    return 2;
}

Expression *Add::get_child(int index) {
    if (index == 0)
        return left;
    if (index == 1)
        return right;
    return nullptr;
}

Add::~Add() {
    delete left;
    delete right;
}
