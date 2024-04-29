//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef BIBLIEOTECA_BIBLIOTECA_H
#define BIBLIEOTECA_BIBLIOTECA_H

#include "Carte.h"
#include <vector>
#include <functional>
#include <iostream>
class Biblioteca {
private:
    std::vector<Carte *> carti;
    int count;
public:
    Biblioteca();

    ~Biblioteca();

    Biblioteca &operator+=(Carte *newCarte);

    std::vector<Carte *>::iterator begin();

    std::vector<Carte *>::iterator end();

    explicit operator int();

    void PrintFilter(bool (*func)(Carte *c));


};


#endif //BIBLIEOTECA_BIBLIOTECA_H
