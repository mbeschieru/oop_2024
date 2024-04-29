//
// Created by Marius Beschieru on 23.04.2024.
//

#ifndef BIBLIEOTECA_REVISTA_H
#define BIBLIEOTECA_REVISTA_H

#include "Carte.h"

class Revista : public Carte{
private:
    std::string titlu;
    int nrArticole;
public:
    Revista(std::string titlu, int nrArticole);

    std::string GetInfo() override;
};


#endif //BIBLIEOTECA_REVISTA_H
