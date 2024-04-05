//
// Created by Marius Beschieru on 04.04.2024.
//

#include "Propozitie.h"

Propozitie::Propozitie(const char *string) {
    computeAll(string);
}

void Propozitie::GetNumberCount() {
    for (int i = 0; i < cuvinte_count; i++)
        if (Utils::isNumber(cuvinte[i]))
            number_count++;
}

int Propozitie::operator[](const char *string) {
    if (Utils::equalStrings(string, "count"))
        return cuvinte_count;
    else if (Utils::equalStrings(string, "total_chars"))
        return caractere_count;
    else if (Utils::equalStrings(string, "vowals"))
        return vowals_count;
    else if (Utils::equalStrings(string, "numbers"))
        return number_count;
    else
        return -1;
}

char *Propozitie::operator[](int index) {
    if (index > cuvinte_count)
        return nullptr;
    if (index >= 0)
        return cuvinte[index];
    return cuvinte[cuvinte_count + index];
}

Propozitie::~Propozitie() {
    for (int i = 0; i < cuvinte_count; i++)
        delete cuvinte[i];
    delete[] cuvinte;
}

void Propozitie::Set(const char *string) {
    if (cuvinte_count != 0) {
        for (int i = 0; i < cuvinte_count; i++) {
            delete[] cuvinte[i];
        }
        delete[] cuvinte;
    }
    computeAll(string);
}

void Propozitie::computeAll(const char *string) {
    cuvinte = new char *[MAX_SIZE];
    cuvinte_count = 0;
    int size = Utils::GetSize(string);
    caractere_count = size - Utils::countEmptySpace(string);
    vowals_count = Utils::countVowels(string);
    cuvinte[cuvinte_count] = new char[MAX_SIZE];
    number_count = 0;
    int charIndex = 0;
    for (int i = 0; i < size; i++) {
        if (!Utils::isSeparator(string[i]) && string[i] != '\0') {
            cuvinte[cuvinte_count][charIndex++] = string[i];
        } else if (charIndex > 0) {
            cuvinte[cuvinte_count][charIndex] = '\0';
            cuvinte_count++;
            if (i < size - 1) {
                cuvinte[cuvinte_count] = new char[MAX_SIZE];
                charIndex = 0;
            }
        }
        if (charIndex > 0 && string[i] == '\0')
            cuvinte_count++;
    }
    if (charIndex > 0) {
        cuvinte_count++;
    }
    GetNumberCount();
}

int Propozitie::operator()(int index) {
    int count = 0;
    for (int i = 0; i < cuvinte_count; i++) {
        if (Utils::GetSize(cuvinte[i]) == 2) {
            count++;
        }
    }
    return count;
}
