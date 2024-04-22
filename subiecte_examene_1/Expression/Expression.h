//
// Created by Marius Beschieru on 04.04.2024.
//

#ifndef EXPRESSION_EXPRESSION_H
#define EXPRESSION_EXPRESSION_H

#include <iostream>

class Expression {
public:
    virtual ~Expression() = default;

    virtual int compute() = 0;

    virtual int get_children_count() = 0;

    virtual Expression *get_child(int index) = 0;

    virtual void print() = 0;

};


#endif //EXPRESSION_EXPRESSION_H
