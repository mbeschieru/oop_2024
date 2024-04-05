//
// Created by Marius Beschieru on 04.04.2024.
//

#include "Value.h"

Value::Value(int value) {
    this->value = value;
}

int Value::compute() {
    return value;
}

int Value::get_children_count() {
    return 0;
}

Expression *Value::get_child(int index) {
    return nullptr;
}

void Value::print() {
    std::cout << value;
}
