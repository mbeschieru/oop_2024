//
// Created by Marius Beschieru on 01.04.2024.
//

#ifndef LAB6_VOLVO_H
#define LAB6_VOLVO_H

#include "Car.h"

class Volvo : public Car {
public:
    Volvo();
    void setAverageSpeedOnWeather() override;
};


#endif //LAB6_VOLVO_H
