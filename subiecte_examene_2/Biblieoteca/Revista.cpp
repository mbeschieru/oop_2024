//
// Created by Marius Beschieru on 23.04.2024.
//

#include "Revista.h"

std::string Revista::GetInfo() {
    return titlu + " cu " + std::to_string(nrArticole);
}

Revista::Revista(std::string titlu, int nrArticole) {
    this->titlu = titlu;
    this->nrArticole = nrArticole;
}


