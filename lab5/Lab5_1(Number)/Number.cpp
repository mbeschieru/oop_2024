//
// Created by Marius Beschieru on 26.03.2024.
//

#include <locale>
#include "Number.h"

void Number::toDecimal() {
    this->decimalValue = 0;
    int i = 0;
    while (value[i] != '\0') {
        char digit = value[i];
        int digitValue = (std::isdigit(digit)) ? digit - '0' : 10 + digit - 'A';
        this->decimalValue = this->decimalValue * base + digitValue;
        i++;
    }
}

void Number::SwitchBase(int newBase) {
    this->base = newBase;
    toDecimal();
    computeDigitVector();
}

void Number::Print() {
    std::cout << decimalValue << "\n";
}

int Number::GetDigitsCount() const {
    if (decimalValue == 0) return 1;
    unsigned long long _decimalValueCopy = decimalValue;
    int count = 0;
    while (_decimalValueCopy != 0) {
        _decimalValueCopy /= 10, count++;
    }
    return count;
}

int Number::GetBase() const {
    return base;
}

Number::Number(const char *value, int base) {
    int size = std::strlen(value);
    this->value = new char[size + 1];
    std::strcpy(this->value, value);
    this->value[size] = '\0';
    this->base = base;
    this->digitVector = nullptr;
    toDecimal();
    computeDigitVector();
}

Number::~Number() {
    delete[] value;
    delete[] digitVector;
    base = 0;
}

char Number::operator[](int index) {
    if (index >= GetDigitsCount() || index < 0)
        return -1;
    return digitVector[index] + '0';
}

void Number::computeDigitVector() {
    int size = GetDigitsCount();
    delete[] digitVector;
    digitVector = new int[size];
    unsigned long long _decimalCopy = decimalValue;
    for (int k = size - 1; k >= 0; k--) {
        digitVector[k] = _decimalCopy % 10;
        _decimalCopy /= 10;
    }
}

Number Number::operator+(Number &other) {
    int b1 = this->GetBase();
    int b2 = other.GetBase();
    int newBase = (b1 > b2) ? b1 : b2;
    unsigned long long _decimalValue = this->decimalValue + other.decimalValue;
    Number newNumber(_decimalValue, newBase);
    return newNumber;
}

Number::Number(unsigned long long decimalValue, int base) {
    this->decimalValue = decimalValue;
    this->base = base;
    this->value = nullptr;
    this->digitVector = nullptr;
    computeDigitVector();
    computeCharValue();
}

Number::Number(const Number &other) {
    this->base = other.base;
    this->decimalValue = other.decimalValue;
    int size = std::strlen(other.value) + 1;
    value = new char[size];
    std::strcpy(value, other.value);
    int digitSize = other.GetDigitsCount();
    digitVector = new int[digitSize];
    for (int i = 0; i < digitSize; ++i) {
        digitVector[i] = other.digitVector[i];
    }
}

Number &Number::operator=(const Number &other) {
    if (this != &other) {
        delete[] value;
        delete[] digitVector;

        base = other.base;
        decimalValue = other.decimalValue;

        int size = std::strlen(other.value) + 1;
        value = new char[size];
        std::strcpy(value, other.value);

        int digitSize = other.GetDigitsCount();
        digitVector = new int[digitSize];
        for (int i = 0; i < digitSize; ++i) {
            digitVector[i] = other.digitVector[i];
        }
    }
    return *this;
}

void Number::computeCharValue() {
    int size = GetDigitsCount();
    delete[]value;
    value = new char[size + 1];
    for (int i = 0; i < size; i++) {
        value[i] = getDigitValue(digitVector[i]);
    }
    value[size] = '\0';
}

char Number::getDigitValue(int digit) {
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    } else if (digit >= 10 && digit < base) {
        return 'A' + (digit - 10);
    } else {
        return '?';
    }
}

Number &Number::operator-(const Number &other) {
    int b1 = this->GetBase();
    int b2 = other.GetBase();
    int newBase = (b1 > b2) ? b1 : b2;
    unsigned long long _decimalValue = this->decimalValue - other.decimalValue;
    Number newNumber(_decimalValue, newBase);
    return newNumber;
}

bool Number::operator>(Number &other) {
    return this->decimalValue > other.decimalValue;
}

bool Number::operator<(Number &other) {
    return this->decimalValue < other.decimalValue;
}

bool Number::operator>=(Number &other) {
    return this->decimalValue >= other.decimalValue;
}

bool Number::operator<=(Number &other) {
    return this->decimalValue >= other.decimalValue;
}

bool Number::operator==(Number &other) {
    return this->decimalValue == other.decimalValue;
}

bool Number::operator!=(Number &other) {
    return this->decimalValue != other.decimalValue;
}

Number::Number(unsigned long long int decimalValue) {
    this->decimalValue = decimalValue;
    this->base = 10;
    this->digitVector = nullptr;
    this->value = nullptr;
    computeDigitVector();
    computeCharValue();
}

Number &Number::operator=(const int value) {
    this->decimalValue = value;
    computeDigitVector();
    computeCharValue();
    return *this;
}

Number &Number::operator+=(const Number &other) {
    this->decimalValue += other.decimalValue;
    computeDigitVector();
    computeCharValue();
    return *this;
}

Number &Number::operator=(const char *value) {
    delete[] this->value;
    int size = std::strlen(value);
    this->value = new char[size + 1];
    std::strcpy(this->value, value);
    this->value[size] = '\0';
    toDecimal();
    computeDigitVector();
    return *this;
}

void Number::computeFromDigitVector() {
    unsigned long long x = 0;
    for (int i = 0; i < GetDigitsCount(); i++) {
        x = x * base + digitVector[i];
    }
    this->decimalValue = x;
}

Number &Number::operator--() {
    this->decimalValue /= 10;
    computeDigitVector();
    computeCharValue();
    return *this;
}

Number Number::operator--(int) {
    Number aux(*this);
    int size = this->GetDigitsCount();
    if (size <= 1)
        this->decimalValue = 0;
    else {
        unsigned long long newValue = 0;
        for (int i = 1; i < size; i++)
            newValue = newValue * 10 + this->digitVector[i];
        this->decimalValue = newValue;
    }
    computeDigitVector();
    computeCharValue();
    return aux;
}

