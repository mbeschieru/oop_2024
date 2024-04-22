//
// Created by Marius Beschieru on 16.03.2024.
//

#ifndef TEST4_STUDENT_H
#define TEST4_STUDENT_H

#include <cstring>
#include <iostream>

class Student {
private:
    char *nume;
    char **materii;
    int *note;
    static constexpr int MAX_CAPACITY = 10;
    int size{};
public:
    Student(const char *nume);

    ~ Student();

    int &operator[](const char *nume);

    explicit operator float ();

    char* GetName();

    void PrintNote();
};


#endif //TEST4_STUDENT_H
