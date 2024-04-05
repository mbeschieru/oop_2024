//
// Created by Marius Beschieru on 05.04.2024.
//

#ifndef LAB6_3_EXTRA__JSON__STRINGVALUE_H
#define LAB6_3_EXTRA__JSON__STRINGVALUE_H

#include "JsonValue.h"
#include "Utils.h"
#include <iostream>

class StringValue : public JsonValue {
private:
    char *string;
    int size;
    static constexpr int MAX_SIZE = 255;
public:
    StringValue(const char *string);

    ~StringValue() override;

    void print(std::ostream &out) const override;
};


#endif //LAB6_3_EXTRA__JSON__STRINGVALUE_H
