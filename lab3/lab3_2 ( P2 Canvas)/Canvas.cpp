//
// Created by Marius Beschieru on 13.03.2024.
//

#include <cstring>
#include <iostream>
#include "Canvas.h"

Canvas::Canvas(int lines, int columns) : lines(lines), columns(columns) {
    matrix = new char *[lines];
    for (int i = 0; i < lines; i++) {
        matrix[i] = new char[columns];
        std::memset(matrix[i], ' ', columns);
    }
    clear();
}

Canvas::~Canvas() {
    for (int i = 0; i < lines; i++)
        delete[] matrix[i];
    delete[] matrix;
    lines = 0;
    columns = 0;
}

void Canvas::clear() {
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = ' ';
}

void Canvas::set_pixel(int x, int y, char value) {
    if (x >= 0 && x < lines && y >= 0 && y < columns)
        matrix[x][y] = value;
    else
        std::cout << "X or Y out of bounds ! \n";
}

void Canvas::print() const {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++)
            std::cout << matrix[i][j];
        std::cout << '\n';
    }
}

void Canvas::set_pixels(int count, ...) {
    va_list args;
    va_start(args,count);
    for (int i = 0 ; i < count ; i ++)
    {
        int x = va_arg(args,int);
        int y = va_arg(args,int);
        char value = static_cast<char>(va_arg(args,int));
        set_pixel(x,y,value);
    }
}
