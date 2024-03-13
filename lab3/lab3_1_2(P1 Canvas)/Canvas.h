//
// Created by Marius Beschieru on 13.03.2024.
//

#ifndef LAB3_2_CANVAS_H
#define LAB3_2_CANVAS_H


class Canvas {
private:
    int width;
    int height;
    char **matrix;
public:
    Canvas(int width, int height);

    ~Canvas();

    void DrawCircle(int x, int y, int ray, char ch);

    void FillCircle(int x, int y, int ray, char ch);

    void DrawRect(int left, int top, int right, int bottom, char ch);

    void FillRect(int left, int top, int right, int bottom, char ch);

    void SetPoint(int x, int y, char ch);

    void DrawLine(int x1, int y1, int x2, int y2, char ch);

    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};


#endif //LAB3_2_CANVAS_H
