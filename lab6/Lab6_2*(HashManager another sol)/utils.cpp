//
// Created by Marius Beschieru on 02.04.2024.
//

#include "utils.h"

bool utils::isVowel(char ch) {
    if (ch <= 'a') {
        ch += 32;
    }
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    }
    return false;
}

bool utils::isLetter(char ch) {
    if (ch <= 'a') {
        ch += 32;
    }
    if (ch >= 'a' && ch <= 'z') {
        return true;
    }
    return false;
}

int utils::getStringSize(const char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

bool utils::compareString(const char *string1, const char *string2) {
    int size1 = getStringSize(string1);
    int size2 = getStringSize(string2);
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++)
        if (string1[i] != string2[i])
            return false;
    return true;
}
