#include <iostream>
#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"
#include "Seat.h"
#include "RangeRover.h"

int main() {
    Circuit c;
    c.setLength(1050);
    c.setWeather(Weather::Sunny);
    c.AddCar(new Volvo());
    c.AddCar(new BMW());
    c.AddCar(new Seat());
    c.AddCar(new RangeRover());
    c.Race();
    c.showFinalRanks();
    c.showWhoDidNotFinish();
    return 0;
}
