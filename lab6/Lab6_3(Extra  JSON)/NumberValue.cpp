//
// Created by Marius Beschieru on 05.04.2024.
//

#include "NumberValue.h"

NumberValue::~NumberValue() {
    delete value;
}

void NumberValue::print(std::ostream &out) const {
    out << *value;
}

NumberValue::NumberValue(int value) {
    this->value = new int;
    *this->value = value;
}
