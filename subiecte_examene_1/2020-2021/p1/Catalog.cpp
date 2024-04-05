//
// Created by Marius Beschieru on 21.03.2024.
//

#include <iostream>
#include "Catalog.h"

Student::Student(const char *nume, int nota) {
    int size = getStringSize(nume);
    this->nume = new char[size + 1];
    for (int i = 0; i <= size; ++i) {
        this->nume[i] = nume[i];
    }
    this->nota = nota;
}

char *Student::getNume() const {
    return nume;
}

double Student::getNota() const {
    return nota;
}

bool Student::equalNames(const char *nume1, const char *nume2) {
    int size1 = getStringSize(nume1);
    int size2 = getStringSize(nume2);
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++)
        if (nume1[i] != nume2[i])
            return false;
    return true;
}

int Student::getStringSize(const char *nume) {
    int size = 0;
    while (nume[size] != '\0')
        size++;
    return size;
}

void Student::Print() const {
    std::cout << "Student: " << nume << " => Grade: " << nota << "\n";
}

bool Student::operator!=(Student &other) const {
    return equalNames(nume, other.getNume());
}

Catalog::Catalog(const char *materie) {
    this->catalog = new Student *[MAX_SIZE];
    int size = Student::getStringSize(materie);
    this->materie = new char[size + 1];
    for (int i = 0; i <= size; ++i) {
        this->materie[i] = materie[i];
    }
    this->count = 0;
}

Catalog &Catalog::operator+=(Student student) {
    if (count >= MAX_SIZE)
        return *this;
    for (int i = 0; i < count; i++)
        if (Student::equalNames(this->catalog[i]->getNume(), student.getNume()))
            return *this;
    catalog[count++] = new Student(student.getNume(), student.getNota());
    return *this;
}

Catalog::operator int() {
    return count;
}

Catalog::operator float() {
    float sum = 0;
    for (int i = 0; i < count; i++)
        sum += catalog[i]->getNota();
    return sum/count;
}


Catalog::operator const char *() {
    return materie;
}

bool Catalog::operator==(const char *nume) {
    for (int i = 0; i < count; i++)
        if (Student::equalNames(catalog[i]->getNume(), nume))
            return true;
    return false;
}

Catalog &Catalog::operator-=(const char *nume) {
    for (int i = 0; i < count; i++)
        if (Student::equalNames(catalog[i]->getNume(), nume)) {
            delete catalog[i];
            for (int j = i; j < count - 1; j++)
                catalog[j] = catalog[j + 1];
            count--;
            return *this;
        }
    return *this;
}


Catalog::~Catalog() {
    for (int i = 0; i < count; i++)
        delete catalog[i];
    delete[] catalog;
    delete[] materie;
    this->count = 0;
}

Catalog::Itterator Catalog::begin() {
    return Itterator(catalog);
}

Catalog::Itterator Catalog::end() {
    return Itterator(catalog + count);
}


Catalog::Itterator::Itterator(Student **ptr) : ptr(ptr) {}

Student &Catalog::Itterator::operator*() const {
    return **ptr;
}

Catalog::Itterator &Catalog::Itterator::operator++() {
    ptr++;
    return *this;
}

bool Catalog::Itterator::operator!=(const Catalog::Itterator &other) {
    return ptr != other.ptr;
};


