//
// Created by Marius Beschieru on 05.04.2024.
//

#ifndef LAB6_3_EXTRA__JSON__BOOLVALUE_H
#define LAB6_3_EXTRA__JSON__BOOLVALUE_H

#include "JsonValue.h"

class BoolValue : public  JsonValue{
private:
    bool *value;
public:
    BoolValue(bool value);

    ~BoolValue() override;

    void print(std::ostream &out) const override;
};


#endif //LAB6_3_EXTRA__JSON__BOOLVALUE_H
