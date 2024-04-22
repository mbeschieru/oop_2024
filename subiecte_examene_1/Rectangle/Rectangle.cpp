//
// Created by Marius Beschieru on 22.03.2024.
//

#include <algorithm>
#include "Rectangle.h"

Punct::Punct(int x, int y) {
    this->x = x;
    this->y = y;
}


Rectangle::Rectangle(int x, int y, int x2, int y2) {
    int minX = x < x2 ? x : x2;
    int minY = y < y2 ? y : y2;
    int maxX = x > x2 ? x : x2;
    int maxY = y > y2 ? y : y2;
    this->width = maxX - minX;
    this->height = maxY - minY;
    this->coordonate = new Punct *[4];
    this->coordonate[0] = new Punct(minX, minY);
    this->coordonate[1] = new Punct(maxX, minY);
    this->coordonate[2] = new Punct(maxX, maxY);
    this->coordonate[3] = new Punct(minX, maxY);
}

Rectangle::Itterator Rectangle::begin() {
    return coordonate;
}

Rectangle::Itterator Rectangle::end() {
    return coordonate + 4;
}

Rectangle::operator bool() {
    return height == width;
}

Punct &Rectangle::GetTopLeftPoint() {
    return *coordonate[0];
}

Rectangle::operator int() {
    return height * width;
}

int Rectangle::Width() {
    return width;
}

int Rectangle::Height() {
    return height;
}

Rectangle &Rectangle::operator&(Rectangle &other) {

    int minX = std::min(this->coordonate[0]->x, other.coordonate[0]->x);
    int minY = std::min(this->coordonate[0]->y, other.coordonate[0]->y);
    int maxX = std::max(this->coordonate[2]->x, other.coordonate[2]->x);
    int maxY = std::max(this->coordonate[2]->y, other.coordonate[2]->y);
    auto rectangle = new Rectangle(minX, minY, maxX, maxY);
    return *rectangle;
}

Rectangle::Itterator::Itterator(Punct **ptr) : ptr(ptr) {}

Punct &Rectangle::Itterator::operator*() {
    return **ptr;
}

Rectangle::Itterator &Rectangle::Itterator::operator++() {
    ptr++;
    return *this;
}

bool Rectangle::Itterator::operator!=(const Rectangle::Itterator &other) {
    return this->ptr != other.ptr;
}

