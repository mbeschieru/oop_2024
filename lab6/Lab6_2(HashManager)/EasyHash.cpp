//
// Created by Marius Beschieru on 02.04.2024.
//

#include "EasyHash.h"

int EasyHash::calculate(const char *string) {
    int count = 0;
    int size = utils::getStringSize(string);
    for (int i = 0; i < size; i++) {
        if (utils::isLetter(string[i])) {
            if (utils::isVowel(string[i])) {
                count += string[i] * 10;
            } else {
                count += string[i] * 11;
            }
        } else {
            count += string[i] * 12;
        }
    }
    return count;
}
