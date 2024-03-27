//
// Created by Marius Beschieru on 27.03.2024.
//


#include "Complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return {real(), -imag()};
}

Complex &Complex::operator()(double real, double imag) {
    real_data = real;
    imag_data = imag;
    return *this;
}

Complex &Complex::operator++() {
    real_data++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex aux(*this);
    ++(*this);
    return aux;
}

Complex &Complex::operator--() {
    real_data--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex aux(*this);
    --(*this);
    return aux;
}

Complex operator+(const Complex &l, const Complex &r) {
    return {l.real() + r.real(), l.imag() + r.imag()};
}

Complex operator+(const Complex &l, double r) {
    return l + Complex(r, 0);
}

Complex operator+(double l, const Complex &r) {
    return r + Complex(l, 0);
}

Complex operator-(const Complex &l, const Complex &r) {
    return {l.real() - r.real(), l.imag() - r.imag()};
}

Complex operator-(const Complex &l, double r) {
    return l - Complex(r, 0);
}

Complex operator-(double l, const Complex &r) {
    return r - Complex(l, 0);
}

Complex operator*(const Complex &l, const Complex &r) {
    double real_part = l.real() * r.real() - l.imag() * r.imag();
    double imag_part = l.real() * r.imag() + l.imag() * r.real();
    return {real_part, imag_part};
}

Complex operator*(const Complex &l, double r) {
    return l * Complex(r, 0);
}

Complex operator*(double l, const Complex &r) {
    return r * Complex(l, 0);
}

Complex operator-(const Complex &obj) {
    return {-obj.real(), -obj.imag()};
}

bool operator==(const Complex &l, const Complex &r) {
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex &l, const Complex &r) {
    return !(l == r);
}

std::ostream &operator<<(std::ostream &out, const Complex &complex) {
    out << complex.real() << " + " << complex.imag() << "i";
    return out;
}
