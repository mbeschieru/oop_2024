//
// Created by Marius Beschieru on 01.04.2024.
//

#include "Circuit.h"

void Circuit::setLength(double legnth) {
    this->length = legnth;
}

double Circuit::getLength() {
    return length;
}

Weather Circuit::getWeather() {
    return weather;
}

void Circuit::setWeather(Weather weather) {
    this->weather = weather;
}

Circuit::Circuit() {
    this->cars = new Car *[MAX_SIZE];
    this->length = 0;
    this->weather = Sunny;
    this->count = 0;
    this->raceInfo = new RaceInfo *[MAX_SIZE];
}

void Circuit::AddCar(Car *car) {
    if (count >= MAX_SIZE)
        return;
    for (int i = 0; i < count; i++)
        if (std::strcmp(cars[i]->getName(), car->getName()) == 0) {
            std::cout << "This car already exists \n";
            return;
        }
    cars[count++] = car;
    car->setWeather(weather);
    car->setAverageSpeedOnWeather();
}

void Circuit::Race() {
    for (int i = 0; i < count; i++) {
        double time = cars[i]->getTime(length);
        bool finished = time > 0;
        raceInfo[i] = new RaceInfo(cars[i]->getName(), finished, time);
    }
}

void Circuit::showFinalRanks() {
    int k = 1;
    for (int i = 0; i < count; i++) {
        if (raceInfo[i]->finished) {
            std::cout << k << ".";
            raceInfo[i]->printFinished();
            k++;
        }
    }
    std::cout<<'\n';
}

void Circuit::showWhoDidNotFinish() {
    int k = 1;
    for (int i = 0; i < count; i++) {
        if (!raceInfo[i]->finished) {
            std::cout << k << ".";
            raceInfo[i]->printNotFinished();
            k++;
        }
    }
    std::cout<<'\n';
}

Circuit::~Circuit() {
    for (int i = 0; i < count; ++i) {
        delete cars[i];
        delete raceInfo[i];
    }
    delete[] cars;
    delete[] raceInfo;
}


RaceInfo::RaceInfo(const char *name, bool finished, double time) {
    int size = strlen(name);
    this->name = new char[size + 1];
    std::strcpy(this->name, name);
    this->finished = finished;
    this->time = time;
}

void RaceInfo::printFinished() const {
    std::cout << "Car " << name << " finished in : " << time << " minutes\n";
}

void RaceInfo::printNotFinished() const {
    std::cout << "Car " << name << " failed to finish the race\n";
}
