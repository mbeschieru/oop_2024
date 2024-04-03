//
// Created by Marius Beschieru on 01.04.2024.
//

#include "Volvo.h"

Volvo::Volvo() {
    setName("Volvo");
    setFuelCapacity(50);
    setFuelConsumption(5);
}

void Volvo::setAverageSpeedOnWeather() {
    switch (getWeather()) {
        case Weather::Sunny:
            setAverageSpeed(100);
             break;
        case Rain:
            setAverageSpeed(50);
            break;
        case Snowy:
            setAverageSpeed(30);
            break;
    }
}
