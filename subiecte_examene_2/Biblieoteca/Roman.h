//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef BIBLIEOTECA_ROMAN_H
#define BIBLIEOTECA_ROMAN_H

#include "Carte.h"

class Roman : public Carte {
private:
    std::string nume;
    std::string autor;
public:
    Roman(std::string nume , std::string titlu);

    std::string GetInfo() override;
};


#endif //BIBLIEOTECA_ROMAN_H
