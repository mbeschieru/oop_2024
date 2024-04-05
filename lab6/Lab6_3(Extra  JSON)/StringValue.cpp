//
// Created by Marius Beschieru on 05.04.2024.
//

#include "StringValue.h"

StringValue::~StringValue() {
    delete[] string;
}

void StringValue::print(std::ostream &out) const {
    out << '"' << string << '"';
}

StringValue::StringValue(const char *string) {
    int _size = Utils::getSize(string);
    if (_size > MAX_SIZE) {
        std::cerr << "Size exceeds limit !\n";
        return;
    }
    size = _size;
    this->string = new char[size + 1];
    for (int i = 0; i < size; i++)
        this->string[i] = string[i];
    this->string[size] = '\0';
}

