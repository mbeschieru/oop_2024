//
// Created by Marius Beschieru on 02.04.2024.
//

#include "CountAsciiHash.h"

int CountAsciiHash::calculate(const char *string) {
    int count = 0;
    int size = utils::getStringSize(string);
    for (int i = 0; i < size; i++) {
        count += string[i];
    }
    return count;
}
