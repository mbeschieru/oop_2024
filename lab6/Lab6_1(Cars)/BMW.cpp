//
// Created by Marius Beschieru on 01.04.2024.
//

#include "BMW.h"

BMW::BMW() {
    setName("BMW");
    setFuelCapacity(50);
    setFuelConsumption(10);
}

void BMW::setAverageSpeedOnWeather() {
    switch (getWeather()) {

        case Rain:
            setAverageSpeed(120);
            break;
        case Sunny:
            setAverageSpeed(200);
            break;
        case Snowy:
            setAverageSpeed(80);
            break;
    }
}
