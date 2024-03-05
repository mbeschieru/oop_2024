//
// Created by Marius Beschieru on 05.03.2024.
//

#include "Movie.h"

Movie::Movie(const char *name, int year, double score, int length) {
    size_t size = strlen(name);
    if (size > 256) {
        std::cout << "Name exceeds 256 characters";
        return;
    }
    this->name = new char[size + 1];
    std::strcpy(this->name, name);
    this->year = year;
    this->score = score;
    this->length = length;
}

char *Movie::getName() {
    return name;
}

int Movie::getYear() const {
    return year;
}

double Movie::getScore() const {
    return score;
}

int Movie::getLength() const {
    return length;
}


void Movie::set_name(const char *_name) {
    size_t size = strlen(_name);
    if (size > 256) {
        std::cout << "Name exceeds 256 characters";
        return;
    }
    this->name = new char[size + 1];
    std::strcpy(this->name, _name);
}

void Movie::set_year(int _year) {
    this->year = _year;
}

void Movie::set_score(double _score) {
    this->score = _score;
}

void Movie::set_length(int _length) {
    this->length = _length;
}

int Movie::getPassedYears() const {
    return 2024 - this->year;
}



