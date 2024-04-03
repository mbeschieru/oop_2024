//
// Created by Marius Beschieru on 01.04.2024.
//

#include "Seat.h"

Seat::Seat() {
    setName("Seat");
    setFuelCapacity(120);
    setFuelConsumption(4);
}

void Seat::setAverageSpeedOnWeather() {
    switch (getWeather()) {
        case Rain:
            setAverageSpeed(50);
            break;
        case Sunny:
            setAverageSpeed(80);
            break;
        case Snowy:
            setAverageSpeed(30);
            break;
    }
}
