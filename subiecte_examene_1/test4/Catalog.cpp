//
// Created by Marius Beschieru on 16.03.2024.
//

#include "Catalog.h"

Catalog::Catalog() {
    studenti = new Student *[MAX_SIZE + 1];
    size = 0;
}

void Catalog::operator+=(const char *nume) {
    if (size == MAX_SIZE)
        return;
    for (int i = 0; i < size; i++)
        if (std::strcmp(studenti[i]->GetName(), nume) == 0)
            return;
    auto student = new Student(nume);
    studenti[size++] = student;
}

Student &Catalog::operator[](const char *nume) {
    for (int i = 0; i < size; i++)
        if (std::strcmp(studenti[i]->GetName(), nume) == 0)
            return *studenti[i];
    studenti[size] = new Student(nume);
    return *studenti[size++];
}

int Catalog::GetCount() {
    return size;
}

Student &Catalog::operator[](int index) {
    return *studenti[index];
}

Catalog::~Catalog() {
    for (int i = 0; i < size; i++)
        delete studenti[i];
    delete[] studenti;
    size = 0;
}
