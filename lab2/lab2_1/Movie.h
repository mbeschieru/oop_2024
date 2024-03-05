//
// Created by Marius Beschieru on 05.03.2024.
//

#ifndef LAB2_1_MOVIE_H
#define LAB2_1_MOVIE_H

#include <cstring>
#include <iostream>

class Movie {
    char *name;
    int year;
    double score;
    int length;
public:
    Movie() = default;

    Movie(const char *name, int year, double score, int length);

    char *getName();

    [[nodiscard]] int getYear() const;

    [[nodiscard]] double getScore() const;

    [[nodiscard]] int getLength() const;

    void set_name(const char *_name);

    void set_year(int _year);

    void set_score(double _score);

    void set_length(int _length);

    [[nodiscard]] int getPassedYears() const;


};

#endif //LAB2_1_MOVIE_H
