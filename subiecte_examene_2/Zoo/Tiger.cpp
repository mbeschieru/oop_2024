//
// Created by Marius Beschieru on 23.04.2024.
//

#include "Tiger.h"

std::string Tiger::GetName() {
    return "Tiger";
}

bool Tiger::IsAFish() {
    return false;
}

bool Tiger::IsABird() {
    return false;
}

bool Tiger::IsAMammal() {
    return true;
}

int Tiger::GetSpeed() {
    return 100;
}
