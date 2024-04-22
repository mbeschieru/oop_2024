//
// Created by Marius Beschieru on 04.04.2024.
//

#ifndef EXPRESSION_NEG_H
#define EXPRESSION_NEG_H

#include "Expression.h"

class Neg : public Expression {
private:
    Expression *child;
public:
    Neg(Expression *c);

    ~Neg() override;

    int compute() override;

    int get_children_count() override;

    Expression *get_child(int index) override;

    void print() override;
};


#endif //EXPRESSION_NEG_H
