//
// Created by Marius Beschieru on 05.03.2024.
//

#include "MovieSeries.h"

void MovieSeries::init() {
    count = 0;
}

void MovieSeries::add(Movie *movie) {
    if (count == MAX_SIZE) {
        std::cout << "Max limit reached ";
        return;
    }
    movies[count++] = movie;
}

void MovieSeries::sort() {

    for (int i = 0; i < count - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < count - i - 1; ++j) {
            if (movies[j]->getPassedYears() < movies[j+1]->getPassedYears()) {
                Movie* aux = movies[j];
                movies[j] = movies[j+1];
                movies[j+1] = aux;
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

void MovieSeries::print() {
    for (int i = 0; i < count; ++i) {
        std::cout << "Name: " << movies[i]->getName() << std::endl;
        std::cout << "Year: " << movies[i]->getYear() << std::endl;
        std::cout << "Rating: " << movies[i]->getScore() << std::endl;
        std::cout << "Length: " << movies[i]->getLength() << std::endl;
        std::cout << "Passed Years: " << movies[i]->getPassedYears() << std::endl;
        std::cout << std::endl;
    }
}

