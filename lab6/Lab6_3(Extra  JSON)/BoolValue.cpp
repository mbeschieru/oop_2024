//
// Created by Marius Beschieru on 05.04.2024.
//

#include "BoolValue.h"

BoolValue::~BoolValue() {
    delete value;
}

void BoolValue::print(std::ostream &out) const {
    if (value)
        out << "true";
    else out << "false";
}

BoolValue::BoolValue(bool value) {
    this->value = new bool;
    *this->value = value;
}
