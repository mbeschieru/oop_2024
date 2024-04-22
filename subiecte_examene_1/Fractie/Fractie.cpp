//
// Created by Marius Beschieru on 04.04.2024.
//

#include "Fractie.h"

Fractie::Fractie(int up, int down) {
    this->up = up;
    this->down = down;
}

void Fractie::print() {
    std::cout << up << "/" << down;
}

Fractie Fractie::operator+(const Fractie &other) const {
    int finalDown = utils::findCmmmc(this->down, other.down);
    int newUp = (this->up * (finalDown / this->down)) + (other.up * (finalDown / other.down));
    return {newUp, finalDown};
}

Fractie Fractie::operator-(const Fractie &other) const {
    int finalDown = utils::findCmmmc(this->down, other.down);
    int newUp = (this->up * (finalDown / this->down)) - (other.up * (finalDown / other.down));
    return {newUp, finalDown};
}

Fractie Fractie::operator*(const Fractie &other) const {
    int newUp = this->up * other.up;
    int newDown = this->down * other.down;
    return {newUp, newDown};
}

Fractie Fractie::simplify() const {
    int cmmdc = utils::findCmmdc(this->up, this->down);
    int newUp = this->up / cmmdc;
    int newDown = this->down / cmmdc;
    return {newUp, newDown};
}

Fractie::Fractie(const char *string) {
    int i = 0;
    int nr = 0;
    int ok = false;
    while (string[i] != '\0') {
        if (string[i] == '/') {
            up = nr;
            ok = true;
            nr = 0;
        } else {
            nr = nr * 10 + (string[i] - '0');
        }
        i++;
    }
    if (ok) {
        down = nr;
    } else {
        up = nr;
        down = 1;
    }
}

bool Fractie::operator==(const Fractie &other) {

    Fractie cpy1 = (*this).simplify();
    Fractie cpy2 = other.simplify();
    bool upBool = (cpy1.up == cpy2.up);
    bool downBool = (cpy1.down == cpy2.down);
    return upBool && downBool;
}

int Fractie::operator[](const char *string) const {
    if (utils::stringEqual(string, "numerator"))
        return up;
    else if (utils::stringEqual(string, "denominator"))
        return down;
    else
        return -1;
}
