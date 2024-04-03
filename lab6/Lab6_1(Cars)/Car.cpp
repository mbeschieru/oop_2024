//
// Created by Marius Beschieru on 01.04.2024.
//

#include "Car.h"


double Car::getFuelCapacity() const {
    return fuelCapacity;
}

double Car::getFuelConsumption() const {
    return fuelConsumption;
}

double Car::getAverageSpeed() const {
    return averageSpeed;
}

char *Car::getName() const {
    return name;
}

void Car::setFuelCapacity(double fuelCapacity) {
    this->fuelCapacity = fuelCapacity;
}

void Car::setFuelConsumption(double fuelConsumption) {
    this->fuelConsumption = fuelConsumption;
}

void Car::setAverageSpeed(double averageSpeed) {
    this->averageSpeed = averageSpeed;
}

void Car::setName(const char *name) {
    size_t size = std::strlen(name);
    delete[] this->name;
    this->name = new char[size + 1];
    std::strcpy(this->name, name);
    this->name[size] = '\0';
}

double Car::getTime(double distance) const {
    double time = distance / averageSpeed;
    if (time * fuelConsumption > fuelCapacity)
        return -1;
    return time;
}

Weather Car::getWeather() {
    return weather;
}

void Car::setWeather(Weather weather) {
    this->weather = weather;
}

