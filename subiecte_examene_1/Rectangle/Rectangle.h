//
// Created by Marius Beschieru on 22.03.2024.
//

#ifndef RECTANGLE_RECTANGLE_H
#define RECTANGLE_RECTANGLE_H

struct Punct {
    int x, y;

    Punct(int x, int y);

    bool compareTo(Punct *other);
};

class Rectangle {
private:
    int width, height;
    Punct **coordonate;


public:
    Rectangle(int x, int y, int x2, int y2);

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

    explicit operator bool ();

    explicit operator int();

    Punct& GetTopLeftPoint();

    int Width();

    int Height();

    Rectangle& operator& (Rectangle& other) ;
};


#endif //RECTANGLE_RECTANGLE_H
