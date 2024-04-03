//
// Created by Marius Beschieru on 01.04.2024.
//

#ifndef LAB6_RANGEROVER_H
#define LAB6_RANGEROVER_H
#include "Car.h"

class RangeRover : public Car{
public:
    RangeRover();
    void setAverageSpeedOnWeather() override;
};


#endif //LAB6_RANGEROVER_H
