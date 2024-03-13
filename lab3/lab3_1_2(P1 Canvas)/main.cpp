#include <iostream>
#include "Canvas.h"

int main() {
    Canvas canvas(20, 10);
    canvas.DrawCircle(10, 5, 3, '*');
    canvas.Print();
    canvas.Clear();
    canvas.FillCircle(10, 5, 3, '*');
    canvas.Print();
    canvas.Clear();
    canvas.DrawRect(2, 2, 17, 7, '*');
    canvas.Print();
    canvas.Clear();
    canvas.FillRect(2, 2, 17, 7, '*');
    canvas.Print();
    canvas.Clear();
    return 0;
}
