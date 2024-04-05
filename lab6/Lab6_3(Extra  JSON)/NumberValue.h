//
// Created by Marius Beschieru on 05.04.2024.
//

#ifndef LAB6_3_EXTRA__JSON__NUMBERVALUE_H
#define LAB6_3_EXTRA__JSON__NUMBERVALUE_H

#include "JsonValue.h"

class NumberValue : public JsonValue {
private:
    int *value;
public:
    NumberValue(int value);

    ~NumberValue() override;

    void print(std::ostream &out) const override;
};


#endif //LAB6_3_EXTRA__JSON__NUMBERVALUE_H
