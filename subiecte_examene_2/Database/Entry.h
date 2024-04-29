//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef DATABASE_ENTRY_H
#define DATABASE_ENTRY_H

#include <string>

class Entry {
private:
    std::string name;
public:
    Entry(std::string name);

    std::string GetName();

    virtual void Add(std::string toAdd) = 0;

    virtual bool Substract(int toSubstract) = 0;

    virtual void Print() = 0;

};


#endif //DATABASE_ENTRY_H
