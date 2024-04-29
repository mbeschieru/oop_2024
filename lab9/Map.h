//
// Created by Marius Beschieru on 29.04.2024.
//

#ifndef LAB9_MAP_H
#define LAB9_MAP_H

#include <stdexcept>
#include <tuple>

template<typename K, typename V>
struct obj {

    int index;
    K key;
    V value;

    obj(K key, V value);

};


template<typename K, typename V>
obj<K, V>::obj(K key, V value) {
    this->key = key;
    this->value = value;
}


template<typename K, typename V>
class Map {
private:
    obj<K, V> **objects;
    static constexpr int MAX_SIZE = 64;
    int size;

    class Iterator {
    private:
        obj<K, V> **ptr;
        obj<K, V> **end;
    public:
        Iterator(obj<K, V> **ptr, obj<K, V> **end);

        bool operator!=(const Iterator &other);

        Iterator &operator++();

        auto operator*() -> std::tuple<K &, V &, int &>;
    };

public:
    Map();

    ~Map();

    V &operator[](K key);

    Iterator begin();

    Iterator end();

};

template<typename K, typename V>
Map<K, V>::~Map() {
    for (int i = 0; i < size; i++) {
        if (objects[i] != nullptr) {
            delete objects[i];
        }
    }
    delete[] objects;
}

template<typename K, typename V>
auto Map<K, V>::Iterator::operator*() -> std::tuple<K &, V &, int &> {
    return std::tie((*ptr)->key, (*ptr)->value, (*ptr)->index);
}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::begin() {
    auto start = objects;
    while (*start == nullptr && start < objects + MAX_SIZE) {
        ++start;
    }
    return Iterator(start, objects + MAX_SIZE);
}

template<typename K, typename V>
typename Map<K, V>::Iterator Map<K, V>::end() {
    return Map::Iterator(objects + MAX_SIZE, objects + MAX_SIZE);
}

template<typename K, typename V>
Map<K, V>::Iterator::Iterator(obj<K, V> **ptr, obj<K, V> **end) {
    this->ptr = ptr;
    this->end = end;
}

template<typename K, typename V>
bool Map<K, V>::Iterator::operator!=(const Map::Iterator &other) {
    return this->ptr != other.ptr;
}

template<typename K, typename V>
typename Map<K, V>::Iterator &Map<K, V>::Iterator::operator++() {
    do {
        ++ptr;
    } while (ptr < end && *ptr == nullptr);  // Check if within bounds and not null
    return *this;
}


template<typename K, typename V>
V &Map<K, V>::operator[](K key) {
    if (objects[key] != nullptr)
        return objects[key]->value;
    if (size >= MAX_SIZE)
        throw std::out_of_range("Map is full");
    objects[key] = new obj<K, V>(key, V{});
    objects[key]->index = size;
    size++;
    return objects[key]->value;
}

template<typename K, typename V>
Map<K, V>::Map() {
    objects = new obj<K, V> *[MAX_SIZE]();
    size = 0;
}


#endif //LAB9_MAP_H
