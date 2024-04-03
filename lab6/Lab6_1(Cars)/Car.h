//
// Created by Marius Beschieru on 01.04.2024.
//

#ifndef LAB6_CAR_H
#define LAB6_CAR_H

#include <cstring>


enum Weather {
    Rain,
    Sunny,
    Snowy
};

class Car {
private:
    double fuelCapacity;
    double fuelConsumption;
    double averageSpeed;
    double timeToFinish;
    char *name;
    Weather weather;
protected:
    void setAverageSpeed(double averageSpeed);
public:
    double getFuelCapacity() const;

    double getFuelConsumption() const;

    double getAverageSpeed() const;

    char *getName() const;

    Weather getWeather();

    void setFuelCapacity(double fuelCapacity);

    void setFuelConsumption(double fuelConsumption);

    virtual void setAverageSpeedOnWeather() = 0;

    void setName(const char *name);

    void setWeather(Weather weather);

    double getTime(double distance) const;
};


#endif //LAB6_CAR_H
