//
// Created by Marius Beschieru on 04.04.2024.
//

#ifndef EXPRESSION_ADD_H
#define EXPRESSION_ADD_H

#include "Expression.h"

class Add : public Expression {
private:
    Expression *left;
    Expression *right;
public:
    Add(Expression *l, Expression *r);

    ~Add() override;

    int compute() override;

    int get_children_count() override;

    Expression *get_child(int index) override;

    void print() override;
};


#endif //EXPRESSION_ADD_H
