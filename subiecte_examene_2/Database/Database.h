//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H

#include "Entry.h"
#include "IntegerData.h"
#include "StringData.h"
#include <vector>
#include <iostream>

class Database {
private:
    std::vector<Entry *> entries;
public:
    Database() = default;

    Database& operator+=(Entry *newEntry);

    Database& operator+=(IntegerData *newEntry);

    Database& operator+=(StringData *newEntry);

    Database& operator-=(const std::string nume);

    void Print();

    std::vector<Entry *>::iterator begin();

    std::vector<Entry *>::iterator end();
};


#endif //DATABASE_DATABASE_H
