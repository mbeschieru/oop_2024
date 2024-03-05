//
// Created by Marius Beschieru on 05.03.2024.
//

#ifndef LAB2_1_MOVIESERIES_H
#define LAB2_1_MOVIESERIES_H

#include "Movie.h"

class MovieSeries {
    int count;
    static const int MAX_SIZE = 16;
    Movie *movies[MAX_SIZE];
public:
    MovieSeries() = default;

    void init();

    void add(Movie *movie);

    void sort();

    void print();
};


#endif //LAB2_1_MOVIESERIES_H
