//
// Created by Marius Beschieru on 04.04.2024.
//

#ifndef EXPRESSION_SUB_H
#define EXPRESSION_SUB_H

#include "Expression.h"

class Sub : public Expression {
private:
    Expression *left;
    Expression *right;
public:
    Sub(Expression *l, Expression *r);

    ~Sub() override;

    int compute() override;

    int get_children_count() override;

    Expression *get_child(int index) override;

    void print() override;

    void attack();
};


#endif //EXPRESSION_SUB_H
