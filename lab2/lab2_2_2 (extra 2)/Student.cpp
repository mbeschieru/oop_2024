//
// Created by Marius Beschieru on 06.03.2024.
//

#include "Student.h"

Student::Student(const char *name) {
    setName(name);
}

Student::Student(const char *name, double mathGrade, double engGrade, double hisGrade) : Student(name) {
    this->mathGrade = mathGrade;
    this->engGrade = engGrade;
    this->hisGrade = hisGrade;
    calculateAvgGrade();
}

char *Student::getName() const {
    return name;
}

double Student::getMathGrade() const {
    return mathGrade;
}

double Student::getEngGrade() const {
    return engGrade;
}

double Student::getHisGrade() const {
    return hisGrade;
}

double Student::getAvgGrade() const {
    return avgGrade;
}

void Student::setName(const char *_name) {
    size_t size = strlen(_name);
    this->name = new char[size + 1];
    std::strcpy(this->name, _name);
}


void Student::setMathGrade(double grade) {
    mathGrade = grade;
};

void Student::setEngGrade(double grade) {
    engGrade = grade;
}

void Student::setHisGrade(double grade) {
    hisGrade = grade;
}

void Student::calculateAvgGrade() {
    avgGrade = (engGrade + hisGrade + mathGrade) / 3;
}

void Student::showInfo() {
    std::cout << "Name: " << name << " , Average grade : " << std::setprecision(3)<<avgGrade << '\n';
}


