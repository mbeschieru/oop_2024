//
// Created by Marius Beschieru on 05.04.2024.
//

#include "ObjectValue.h"

Object::Object(const char *key, JsonValue *value) {
    int size = Utils::getSize(key);
    this->key = new char[size + 1];
    for (int i = 0; i < size; i++)
        this->key[i] = key[i];
    this->value = value;
}

ObjectValue::ObjectValue() {
    objects = new Object *[MAX_SIZE];
    count = 0;
}

void ObjectValue::add(const char *key, JsonValue *value) {
    if (count >= MAX_SIZE) {
        std::cerr << "Array is full";
        return;
    }
    objects[count++] = new Object(key, value);
}

ObjectValue::~ObjectValue() {
    for (int i = 0; i < count; i++) {
        delete objects[i];
    }
    delete[] objects;
}

void ObjectValue::print(std::ostream &out) const {
    out << '{';
    for (int i = 0; i < count; i++) {
        out << '"';
        out << objects[i]->key;
        out << '"' << ':';
        objects[i]->value->print(out);
        if (i != count - 1)
            out << ", ";
    }
    out << '}';
}


ObjectValue::operator unsigned int *() const {
    auto unsignedCount = static_cast<unsigned int >(count);
    return &unsignedCount;
}
