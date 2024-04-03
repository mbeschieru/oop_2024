//
// Created by Marius Beschieru on 02.04.2024.
//

#ifndef LAB6_2_HASHMANAGER__HASHMANAGER_H
#define LAB6_2_HASHMANAGER__HASHMANAGER_H

#include "Hash.h"
#include "utils.h"
#include <iostream>

class HashManager {
private:
    Hash **hashes;
    char **keys;
    static constexpr int MAX_SIZE = 4;
    int count;
public:

    class Proxy {
    private:
        HashManager &manager;
        const char *key;
    public:
        Proxy(HashManager &manager, const char *key);

        Proxy &operator=(Hash *hash);
    };

    HashManager();

    ~HashManager();

    void addHash(const char *key, Hash *hash);

    void print_hashes(const char *string);

    Proxy operator[](const char *key);

};


#endif //LAB6_2_HASHMANAGER__HASHMANAGER_H
