//
// Created by Marius Beschieru on 05.04.2024.
//

#include "ArrayValue.h"

ArrayValue::ArrayValue() {
    values = new JsonValue *[MAX_SIZE];
    count = 0;
}

void ArrayValue::add(JsonValue *value) {
    if (count >= MAX_SIZE) {
        std::cerr << "Array is full !";
        return;
    }
    values[count++] = value;
}

ArrayValue::~ArrayValue() {
    for (int i = 0; i < count; i++)
        delete values[i];
    delete[] values;
}

void ArrayValue::print(std::ostream &out) const {
    out << '[';
    for (int i = 0; i < count; i++) {
        values[i]->print(out);
        if (i != count - 1)
            out << ',';
    }
    out << ']';
}

/*
ArrayValue::operator unsigned *() {
    auto unsignedCount = static_cast<unsigned int >(count);
    return &unsignedCount;
}
*/
