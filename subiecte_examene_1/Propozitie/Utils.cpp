//
// Created by Marius Beschieru on 04.04.2024.
//

#include "Utils.h"

int Utils::GetSize(const char *string) {
    if (string == nullptr)
        return 0;
    int i = 0;
    while (string[i] != '\0')
        i++;
    return i;
}

void Utils::CopyString(char *destination, const char *source) {
    delete[] destination;
    int size = GetSize(source);
    destination = new char[size + 1];
    for (int i = 0; i < size; i++)
        destination[i] = source[i];
    destination[size] = '\0';
}

bool Utils::isVowel(char ch) {
    if (ch < 'a')
        ch += 32;
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    return false;
}

int Utils::countVowels(const char *string) {
    int total = 0;
    int size = GetSize(string);
    for (int i = 0; i < size; i++)
        if (isVowel(string[i]))
            total++;
    return total;
}

int Utils::isNumber(const char *string) {
    int size = GetSize(string);
    for (int i = 0; i < size; i++)
        if (!(string[i] <= '9' && string[i] >= '0'))
            return false;
    return true;
}

bool Utils::equalStrings(const char *string1, const char *string2) {
    int size1 = GetSize(string1);
    int size2 = GetSize(string2);
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; ++i) {
        if (string1[i] != string2[i])
            return false;
    }
    return true;
}

int Utils::countEmptySpace(const char *string) {
    int size = GetSize(string);
    int count = 0;
    for (int i = 0; i < size; i++)
        if (isSeparator(string[i]))
            count++;
    return count;
}

bool Utils::isSeparator(const char ch) {
    if (ch == ' ' || ch == ',')
        return true;
    return false;
}
