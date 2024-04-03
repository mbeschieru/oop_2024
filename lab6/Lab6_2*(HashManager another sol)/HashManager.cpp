//
// Created by Marius Beschieru on 03.04.2024.
//

#include <stdexcept>
#include <iostream>
#include "HashManager.h"

HashMap::HashMap(char *key, Hash *hash) : key(key), hash(hash) {}

HashMap::HashMap(const char *key) : hash(nullptr) {
    int size = utils::getStringSize(key);
    this->key = new char[size];
    int i = 0;
    while (key[i] != '\0') {
        this->key[i] = key[i];
        i++;
    }
    this->key[size] = '\0';
}


HashManager::HashManager() {
    hashMap = new HashMap *[MAX_SIZE];
    count = 0;

}

HashManager::~HashManager() {
    for (int i = 0; i < count; i++)
        delete hashMap[i];
    delete[] hashMap;
}

Hash *&HashManager::operator[](const char *string) {
    if (count >= MAX_SIZE) {
        return (Hash *&) (hashMap[MAX_SIZE]);
    }
    for (int i = 0; i < count; i++)
        if (utils::compareString(hashMap[i]->key, string))
            return hashMap[i]->hash;
    hashMap[count] = new HashMap(string);
    return hashMap[count++]->hash;
}

void HashManager::print_hashes(const char *string) {
    for (int i = 0; i < count; i++) {
        std::cout << hashMap[i]->hash->calculate(string) << '\n';
    }
}
