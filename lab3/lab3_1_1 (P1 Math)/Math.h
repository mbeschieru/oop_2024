//
// Created by Marius Beschieru on 13.03.2024.
//

#ifndef LAB3_1_MATH_H
#define LAB3_1_MATH_H


class Math {
public:
    static int Add(int, int);

    static int Add(int, int, int);

    static int Add(double, double);

    static int Add(double, double, double);

    static int Mul(int, int);

    static int Mul(int, int, int);

    static int Mul(double, double);

    static int Mul(double, double, double);

    static int Add(int count, ...);

    static char *Add(const char *, const char *);
};


#endif //LAB3_1_MATH_H
