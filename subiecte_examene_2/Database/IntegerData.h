//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef DATABASE_INTEGERDATA_H
#define DATABASE_INTEGERDATA_H

#include "Entry.h"
#include <iostream>

class IntegerData : public Entry{
private:
    int value;
public:

    IntegerData(std::string name , std::string value);

    void Add(std::string toAdd) override;

    bool Substract(int toSubstract) override;

    void Print() override;
};


#endif //DATABASE_INTEGERDATA_H
