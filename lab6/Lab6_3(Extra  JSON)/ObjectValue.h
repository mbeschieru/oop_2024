//
// Created by Marius Beschieru on 05.04.2024.
//

#ifndef LAB6_3_EXTRA__JSON__OBJECTVALUE_H
#define LAB6_3_EXTRA__JSON__OBJECTVALUE_H

#include "JsonValue.h"
#include "Utils.h"
#include <iostream>

struct Object {
    char *key;
    JsonValue *value;

    Object(const char *key, JsonValue *value);
};

class ObjectValue : public JsonValue {
private:
    Object **objects;
    int count;
    static constexpr int MAX_SIZE = 255;
public:
    ObjectValue();

    void add(const char *key, JsonValue *value);

    ~ObjectValue() override;

    void print(std::ostream &out) const override;

   operator unsigned () const;
};


#endif //LAB6_3_EXTRA__JSON__OBJECTVALUE_H
