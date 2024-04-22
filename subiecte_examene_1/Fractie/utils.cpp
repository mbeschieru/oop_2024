//
// Created by Marius Beschieru on 04.04.2024.
//

#include "utils.h"

int utils::findCmmdc(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int utils::findCmmmc(int a, int b) {
    return (a * b) / findCmmdc(a, b);
}

int utils::findSize(const char *string) {
    int i = 0;
    while (string[i] != '\0') {
        i++;
    }
    return i;
}

bool utils::stringEqual(const char *string1, const char *string2) {
    int size1 = findSize(string1);
    int size2 = findSize(string2);
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++)
        if (string1[i] != string2[i])
            return false;
    return true;
}
