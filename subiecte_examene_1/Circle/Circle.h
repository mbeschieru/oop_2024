//
// Created by Marius Beschieru on 22.03.2024.
//

#ifndef CIRCLE_CIRCLE_H
#define CIRCLE_CIRCLE_H

#include <cmath>
#include <cstring>

struct Punct {
    int x, y;

    Punct() = default;

    Punct(int x, int y);
};

class Circle {
private:
    Punct **coordonate;
    Punct centre;
    int raza;

    int calculateDistance(int x1, int y1, int x2, int y2);

public:
    Circle(int x, int y, int raza);

    class Itterator {
    private:
        Punct **ptr;
    public:
        Itterator(Punct **ptr);

        Punct &operator*();

        Itterator &operator++();

        bool operator!=(const Itterator &other);
    };

    Itterator begin();

    Itterator end();

    bool operator==(Punct punct);

    bool operator>(Punct punct);

    explicit operator int();

    Circle &operator()(const char *string, int value);

    int operator[](const char*string);
};


#endif //CIRCLE_CIRCLE_H
