//
// Created by Marius Beschieru on 23.04.2024.
//

#include "Roman.h"

std::string Roman::GetInfo() {
    return "Roman " + nume + " de " + autor ;
}

Roman::Roman(std::string nume, std::string autor) {
    this->nume = nume;
    this->autor = autor;
}
