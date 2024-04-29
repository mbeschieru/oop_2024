//
// Created by Marius Beschieru on 23.04.2024.
//

#include "Database.h"

Database &Database::operator+=(Entry *newEntry) {
    entries.push_back(newEntry);
    return *this;
}

void Database::Print() {
    for (auto entry: entries) {
        entry->Print();
    }
    std::cout << '\n';
}

std::vector<Entry *>::iterator Database::begin() {
    return entries.begin();
}

std::vector<Entry *>::iterator Database::end() {
    return entries.end();
}

Database &Database::operator+=(IntegerData *newEntry) {
    auto castEntry = dynamic_cast<Entry *> (newEntry);
    entries.push_back(castEntry);
    return *this;
}

Database &Database::operator+=(StringData *newEntry) {
    auto castEntry = dynamic_cast<Entry *> (newEntry);
    entries.push_back(castEntry);
    return *this;
}

Database &Database::operator-=(const std::string nume) {
    for (auto it = entries.begin(); it != entries.end();) {
        if ((*it)->GetName() == nume) {
            it = entries.erase(it);
        } else {
            ++it;
        }
    }
    return *this;
}

