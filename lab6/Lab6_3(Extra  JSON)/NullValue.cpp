//
// Created by Marius Beschieru on 05.04.2024.
//

#include "NullValue.h"

NullValue::~NullValue() {
    delete value;
};

void NullValue::print(std::ostream &out) const {
    out << "null";
}

NullValue::NullValue() {
    value = new int;
    *value = 0;
}
