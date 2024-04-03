//
// Created by Marius Beschieru on 01.04.2024.
//

#include "RangeRover.h"

RangeRover::RangeRover() {
    setName("Range Rover");
    setFuelCapacity(160);
    setFuelConsumption(8);
}

void RangeRover::setAverageSpeedOnWeather() {
    switch (getWeather()) {

        case Rain:
            setAverageSpeed(70);
            break;
        case Sunny:
            setAverageSpeed(110);
            break;
        case Snowy:
            setAverageSpeed(60);
            break;
    }
}
