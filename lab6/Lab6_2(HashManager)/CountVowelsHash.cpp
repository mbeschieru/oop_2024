//
// Created by Marius Beschieru on 02.04.2024.
//

#include "CountVowelsHash.h"

int CountVowelsHash::calculate(const char *string) {
    int count = 0;
    int size = utils::getStringSize(string);
    for (int i = 0; i < size; i++) {
        if (utils::isLetter(string[i]) && utils::isVowel(string[i])) {
            count++;
        }
    }
    return count;
}
