//
// Created by Marius Beschieru on 05.04.2024.
//

#ifndef LAB6_3_EXTRA__JSON__ARRAYVALUE_H
#define LAB6_3_EXTRA__JSON__ARRAYVALUE_H

#include "JsonValue.h"
#include <iostream>

class ArrayValue : public JsonValue {
private:
    JsonValue **values;
    int count;
    static constexpr int MAX_SIZE = 16;
public:
    ArrayValue();

    void add(JsonValue *value);

    ~ArrayValue() override;

    void print(std::ostream &out) const override;

};


#endif //LAB6_3_EXTRA__JSON__ARRAYVALUE_H
