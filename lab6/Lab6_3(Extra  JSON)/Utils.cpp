//
// Created by Marius Beschieru on 05.04.2024.
//

#include "Utils.h"

int Utils::getSize(const char *string) {
    int i = 0;
    while (string[i] != '\0')
        i++;
    return i;
}
