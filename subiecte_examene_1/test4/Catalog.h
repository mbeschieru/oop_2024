//
// Created by Marius Beschieru on 16.03.2024.
//

#ifndef TEST4_CATALOG_H
#define TEST4_CATALOG_H

#include <Student.h>

class Catalog {
private:
    Student **studenti;
    int size;
    static constexpr int MAX_SIZE = 10;
public:
    Catalog();

    ~Catalog();

    void operator+=(const char* nume);

    Student& operator[](const char* nume);

    Student& operator[](int index);

    int GetCount();
};


#endif //TEST4_CATALOG_H
