//
// Created by Marius Beschieru on 13.03.2024.
//

#include <cstdarg>
#include <cstdio>
#include <cstring>
#include "Math.h"

int Math::Add(int x, int y) {
    return x + y;
}

int Math::Add(int x, int y, int z) {
    return x + y + z;
}

int Math::Add(double x, double y) {
    return static_cast<int>(x + y);
}

int Math::Add(double x, double y, double z) {
    return static_cast<int>(x + y + z);
}

int Math::Mul(int x, int y) {
    return x * y;
}

int Math::Mul(int x, int y, int z) {
    return x * y * z;
}

int Math::Mul(double x, double y) {
    return static_cast<int>(x * y);
}

int Math::Mul(double x, double y, double z) {
    return static_cast<int>(x * y * z);
}

int Math::Add(int count, ...) {
    int s = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
        s += va_arg(args, int);
    va_end(args);
    return s;
}

char *Math::Add(const char *x, const char *y) {
    if (x == nullptr || y == nullptr)
        return nullptr;

    size_t xSize = std::strlen(x);
    size_t ySize = std::strlen(y);
    size_t composedSize = xSize + ySize;
    char *composed = new char[composedSize + 1];
    strcpy(composed, x);
    strcat(composed, y);

    return composed;

}

