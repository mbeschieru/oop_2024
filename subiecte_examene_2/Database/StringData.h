//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef DATABASE_STRINGDATA_H
#define DATABASE_STRINGDATA_H

#include "Entry.h"
#include <iostream>
class StringData : public Entry{
private:
    std::string value;
public:

    StringData(std::string name , std::string value);

    void Add(std::string toAdd) override;

    bool Substract(int toSubstract) override;

    void Print() override;
};


#endif //DATABASE_STRINGDATA_H
