//
// Created by Marius Beschieru on 05.04.2024.
//

#ifndef LAB6_3_EXTRA__JSON__NULLVALUE_H
#define LAB6_3_EXTRA__JSON__NULLVALUE_H

#include "JsonValue.h"

class NullValue : public JsonValue {
private:
    int *value;
public:

    NullValue();

    ~NullValue() override;

    void print(std::ostream &out) const override;
};


#endif //LAB6_3_EXTRA__JSON__NULLVALUE_H
