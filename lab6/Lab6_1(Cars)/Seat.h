//
// Created by Marius Beschieru on 01.04.2024.
//

#ifndef LAB6_SEAT_H
#define LAB6_SEAT_H
#include "Car.h"

class Seat : public  Car{
public:
    Seat();
    void setAverageSpeedOnWeather() override;
};


#endif //LAB6_SEAT_H
