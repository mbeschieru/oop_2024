//
// Created by Marius Beschieru on 23.04.2024.
//

#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    carti.reserve(100);
    count = 0;
}

Biblioteca::~Biblioteca() {
    carti.clear();
    count = 0;
}

Biblioteca &Biblioteca::operator+=(Carte *newCarte) {
    carti.push_back(newCarte);
    count++;
    return *this;
}

std::vector<Carte *>::iterator Biblioteca::begin() {
    return carti.begin();
}

std::vector<Carte *>::iterator Biblioteca::end() {
    return carti.end();
}

Biblioteca::operator int() {
    return count;
}

void Biblioteca::PrintFilter(bool (*func)(Carte *)) {
    for (auto carte: carti)
        if (func(carte))
            std::cout << carte->GetInfo()<<std::endl;

}
