//
// Created by Marius Beschieru on 13.03.2024.
//

#include <cstring>
#include <iostream>
#include "Canvas.h"

Canvas::Canvas(int width, int height) : width(width), height(height) {
    matrix = new char *[height];
    for (int i = 0; i < height; i++) {
        matrix[i] = new char[width];
        std::memset(matrix[i], ' ', width);
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < height; i++)
        delete[] matrix[i];
    delete[] matrix;
    width = 0;
    height = 0;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {


    if (ray > 0) {
        SetPoint(x - ray, y, ch);
        SetPoint(x + ray, y, ch);
        SetPoint(x, y - ray, ch);
        SetPoint(x, y + ray, ch);
    }

    int dy = 0;
    int p = 1 - ray;

    while (ray > dy) {
        dy++;

        if (p <= 0) {
            p = p + 2 * dy + 1;
        } else {
            ray--;
            p = p + 2 * dy - 2 * ray + 1;
        }

        if (ray < dy) {
            break;
        }

        SetPoint(x + ray, y - dy, ch);
        SetPoint(x - ray, y - dy, ch);
        SetPoint(x + ray, y + dy, ch);
        SetPoint(x - ray, y + dy, ch);

    }
}


void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height)
        matrix[y][x] = ch;
    else
        std::cout << "X or Y out of bounds ! \n";
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
            std::cout << matrix[i][j];
        std::cout << '\n';
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            matrix[i][j] = ' ';
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
    DrawCircle(x, y, ray, ch);
    for (int i = 0; i < height; i++) {
        bool ok = false;
        if (i != y + ray && i != y - ray)
            for (int j = 0; j < width; j++) {
                if (!ok && matrix[i][j] == ch)
                    ok = true, j++;
                if (ok && matrix[i][j] == ch)
                    break;
                if (ok && matrix[i][j] == ' ')
                    matrix[i][j] = ch;
            }
    }


}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1), stepX = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1), stepY = y1 < y2 ? 1 : -1;
    int error = dx + dy, aux;

    while (1) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2)
            break;
        aux = 2 * error;
        if (aux <= dx)
            error += dx, y1 += stepY;
        if (aux >= dy)
            error += dy, x1 += stepX;
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    DrawLine(left, top, right, top, ch);
    DrawLine(right, top, right, bottom, ch);
    DrawLine(right, bottom, left, bottom, ch);
    DrawLine(left, bottom, left, top, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top ; i < bottom; i++)
        DrawLine(left, i, right, i, ch);
}
