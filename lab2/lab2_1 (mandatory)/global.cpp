//
// Created by Marius Beschieru on 05.03.2024.
//

#include "global.h"

int movie_compare_name(Movie &m1, Movie &m2) {
    char *name_1 , *name_2;
    name_1 = m1.getName();
    name_2 = m2.getName();
    int result = std::strcmp(name_1,name_2);
    if (result == 0 )
        return 0;
    if (result < 0 )
        return -1;
    return 1;
}

int movie_compare_year(Movie &m1, Movie &m2) {
    int year_1, year_2;
    year_1 = m1.getYear();
    year_2 = m2.getYear();
    if (year_1 == year_2)
        return 0;
    if (year_1 < year_2)
        return -1;
    return 1;
}

int movie_compare_score(Movie &m1, Movie &m2) {
    double score_1, score_2;
    score_1 = m1.getScore();
    score_2 = m2.getScore();
    if (score_1 == score_2)
        return 0;
    if (score_1 < score_2)
        return -1;
    return 1;
}

int movie_compare_length(Movie &m1, Movie &m2) {
    int length_1, length_2;
    length_1 = m1.getLength();
    length_2 = m2.getLength();
    if (length_1 == length_2)
        return 0;
    if (length_1 < length_2)
        return -1;
    return 1;
}

int movie_compare_passed_years(Movie &m1, Movie &m2) {
    int passed_1, passed_2;
    passed_1 = m1.getPassedYears();
    passed_2 = m2.getPassedYears();
    if (passed_1 == passed_2)
        return 0;
    if (passed_1 < passed_2)
        return -1;
    return 1;

}