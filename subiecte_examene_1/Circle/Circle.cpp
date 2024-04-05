//
// Created by Marius Beschieru on 22.03.2024.
//

#include "Circle.h"

Punct::Punct(int x, int y) {
    this->x = x;
    this->y = y;

}

Circle::Circle(int x, int y, int raza) {
    this->raza = raza;
    this->centre = Punct(x, y);
    this->coordonate = new Punct *[4];
    this->coordonate[0] = new Punct(this->centre.x, this->centre.y - raza);
    this->coordonate[1] = new Punct(this->centre.x + raza, this->centre.y);
    this->coordonate[2] = new Punct(this->centre.x, this->centre.y + raza);
    this->coordonate[3] = new Punct(this->centre.x - raza, this->centre.y);
}

Circle::Itterator Circle::begin() {
    return coordonate;
}

Circle::Itterator Circle::end() {
    return coordonate + 4;
}

bool Circle::operator==(Punct punct) {
    int rez = calculateDistance(punct.x, punct.y, centre.x, centre.y);
    return rez * rez == raza * raza;
}

int Circle::calculateDistance(int x1, int y1, int x2, int y2) {
    int r1 = (x1 - x2);
    int r2 = (y1 - y2);
    int rez = sqrt(r1 * r1 + r2 * r2);
    return rez;
}

bool Circle::operator>(Punct punct) {
    int minX = centre.x - raza;
    int minY = centre.y - raza;
    int maxX = centre.x + raza;
    int maxY = centre.y + raza;
    return punct.x >= minX && punct.x <= maxX
           && punct.y >= minY && punct.y <= maxY;
}

Circle::operator int() {
    return 2 * raza;
}

Circle &Circle::operator()(const char *string, int value) {
    int rezult1 = std::strcmp("add_to_x", string);
    int rezult2 = std::strcmp("add_to_y", string);
    int rezult3 = std::strcmp("add_to_ray", string);
    if (rezult1 == 0) {
        centre.x += value;
    } else if (rezult2 == 0) {
        centre.y += value;
    } else if (rezult3 == 0) {
        raza += value;
    }
    *this = Circle(centre.x, centre.y, raza);
    return *this;
}

int Circle::operator[](const char *string) {
    int rezult1 = std::strcmp("x", string);
    int rezult2 = std::strcmp("y", string);
    int rezult3 = std::strcmp("ray", string);
    if (rezult1 == 0) {
        return centre.x;
    } else if (rezult2 == 0) {
        return centre.y;
    } else if (rezult3 == 0) {
        return raza;
    }
    return -1;
}

Punct &Circle::Itterator::operator*() {
    return **ptr;
}

Circle::Itterator &Circle::Itterator::operator++() {
    ptr++;
    return *this;
}

bool Circle::Itterator::operator!=(const Circle::Itterator &other) {
    return this->ptr != other.ptr;
}

Circle::Itterator::Itterator(Punct **ptr) : ptr(ptr) {}
