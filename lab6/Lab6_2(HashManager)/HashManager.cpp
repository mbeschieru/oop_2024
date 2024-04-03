//
// Created by Marius Beschieru on 02.04.2024.
//

#include "HashManager.h"

HashManager::HashManager() {
    hashes = new Hash *[MAX_SIZE];
    keys = new char *[MAX_SIZE];
    count = 0;
}

HashManager::~HashManager() {
    for (int i = 0; i < count; i++) {
        delete hashes[i];
        delete keys[i];
    }
    delete[] hashes;
    delete[] keys;
    count = 0;
}

void HashManager::print_hashes(const char *string) {
    for (int i = 0; i < count; i++)
        std::cout << hashes[i]->calculate(string) << '\n';
}

void HashManager::addHash(const char *key, Hash *hash) {
    if (count < MAX_SIZE) {
        int size = utils::getStringSize(key);
        keys[count] = new char[64];
        keys[count][size] = '\0';
        for (int i = 0; i < size; i++)
            keys[count][i] = key[i];
        hashes[count] = hash;
        count++;
    }
}

HashManager::Proxy HashManager::operator[](const char *key) {
    return Proxy(*this, key);
}

HashManager::Proxy::Proxy(HashManager &manager, const char *key) : manager(manager), key(key) {}

HashManager::Proxy &HashManager::Proxy::operator=(Hash *hash) {
    manager.addHash(key, hash);
    return *this;
}
