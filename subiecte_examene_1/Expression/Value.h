//
// Created by Marius Beschieru on 04.04.2024.
//

#ifndef EXPRESSION_VALUE_H
#define EXPRESSION_VALUE_H

#include "Expression.h"

class Value : public Expression {
private:
    int value;
public:
    Value(int value);

    int compute() override;

    int get_children_count() override;

    Expression *get_child(int index) override;

    void print() override;
};


#endif //EXPRESSION_VALUE_H
