//
// Created by Marius Beschieru on 03.04.2024.
//

#ifndef LAB6_2_HASHMANAGER__HASHMANAGER_H
#define LAB6_2_HASHMANAGER__HASHMANAGER_H

#include "Hash.h"
#include "utils.h"

struct HashMap {
    char *key;
    Hash *hash;

    HashMap(char *key, Hash *hash);

    HashMap(const char *key);
};

class HashManager {
private:
    HashMap **hashMap;
    int count;
    static constexpr int MAX_SIZE = 5;
public:
    HashManager();

    ~HashManager();

    Hash *&operator[](const char *string);

    void print_hashes(const char *string);
};


#endif //LAB6_2_HASHMANAGER__HASHMANAGER_H
