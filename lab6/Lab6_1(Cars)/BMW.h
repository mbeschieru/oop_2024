//
// Created by Marius Beschieru on 01.04.2024.
//

#ifndef LAB6_BMW_H
#define LAB6_BMW_H
#include "Car.h"

class BMW : public Car {
public:
    BMW();
    void setAverageSpeedOnWeather() override;
};


#endif //LAB6_BMW_H
