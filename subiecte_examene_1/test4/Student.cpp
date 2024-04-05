//
// Created by Marius Beschieru on 16.03.2024.
//

#include "Student.h"

Student::Student(const char *nume) {
    int size = std::strlen(nume);
    this->nume = new char[size + 1];
    std::strcpy(this->nume, nume);
    materii = new char *[MAX_CAPACITY];
    note = new int[MAX_CAPACITY];
    this->size = 0;
}

int &Student::operator[](const char *nume) {
    for (int i = 0; i < size; i++)
        if (std::strcmp(materii[i], nume) == 0)
            return note[i];
    note[size] = 0;
    materii[size] = new char[std::strlen(nume) + 1];
    std::strcpy(materii[size], nume);
    size++;
    return note[size - 1];
}

Student::operator float() {
    float s = 0;
    for (int i = 0; i < size; i++)
        s += note[i];
    return s / size;
}

char *Student::GetName() {
    return nume;
}

void Student::PrintNote() {
    for (int i = 0; i < size; i++)
        std::cout << materii[i] << " => " << note[i] << '\n';
}

Student::~Student() {
    delete[] nume;
    for (int i = 0; i < size; i++)
        delete[] materii[i];
    delete[] materii;
    delete[]note;
    size = 0;
}


