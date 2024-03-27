//
// Created by Marius Beschieru on 26.03.2024.
//

#ifndef LAB5_1_NUMBER__NUMBER_H
#define LAB5_1_NUMBER__NUMBER_H

#include <iostream>

class Number {
private:
    char *value;
    int base;
    unsigned long long decimalValue;
    int *digitVector;

    void computeCharValue();

    char getDigitValue(int digit);

    void toDecimal();

    void computeDigitVector();

    void computeFromDigitVector();

    Number(unsigned long long decimalValue, int base);

public:
    Number(const char *value, int base);

    Number(unsigned long long decimalValue);

    ~Number();

    Number(const Number &other);

    char operator[](int index);

    Number &operator=(const Number &other);

    Number &operator-(const Number &other);

    Number &operator=(const int value);

    Number &operator+=(const Number &other);

    Number &operator=(const char *value);

    Number &operator--();

    Number operator--(int);

    Number operator+(Number &other);

    bool operator>(Number &other);

    bool operator<(Number &other);

    bool operator>=(Number &other);

    bool operator<=(Number &other);

    bool operator==(Number &other);

    bool operator!=(Number &other);

    void SwitchBase(int newBase);

    void Print();

    int GetDigitsCount() const;

    int GetBase() const;
};


#endif //LAB5_1_NUMBER__NUMBER_H
