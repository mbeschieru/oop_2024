//
// Created by Marius Beschieru on 01.04.2024.
//

#ifndef LAB6_CIRCUIT_H
#define LAB6_CIRCUIT_H
#include "Car.h"
#include <iostream>

struct RaceInfo{
    char* name;
    bool finished;
    double time;

    RaceInfo(const char* name , bool finished , double time);
    void printFinished() const;
    void printNotFinished() const;
};

class Circuit {
private:
    Car** cars;
    int count ;
    double length;
    Weather weather;
    RaceInfo** raceInfo;
    static constexpr int MAX_SIZE = 50;
public:
    Circuit();
    ~Circuit();
    double getLength();
    Weather getWeather();
    void setWeather(Weather weather);
    void setLength(double legnth);
    void AddCar(Car* car);
    void Race();
    void showFinalRanks();
    void showWhoDidNotFinish();
};


#endif //LAB6_CIRCUIT_H
