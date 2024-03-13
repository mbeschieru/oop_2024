//
// Created by Marius Beschieru on 13.03.2024.
//

#ifndef LAB3_2___P2_CANVAS__CANVAS_H
#define LAB3_2___P2_CANVAS__CANVAS_H


class Canvas {
private:
    int lines, columns;
    char **matrix;
public:
    // contructor will call the clear method
    Canvas(int lines, int columns);

    ~Canvas();

    //set the character at the position x and y to value
    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();

    void print() const;
};


#endif //LAB3_2___P2_CANVAS__CANVAS_H
