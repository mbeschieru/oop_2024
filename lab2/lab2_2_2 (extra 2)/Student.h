//
// Created by Marius Beschieru on 06.03.2024.
//

#ifndef LAB2_2_2__EXTRA_2__STUDENT_H
#define LAB2_2_2__EXTRA_2__STUDENT_H

#include <cstring>
#include <iostream>
#include <iomanip>

class Student {
    char *name{};
    double mathGrade{};
    double engGrade{};
    double hisGrade{};
    double avgGrade{};
public:
    Student() = default;

    explicit Student(const char *name);

    Student(const char *name, double mathGrade, double engGrade, double hisGrade);

    [[nodiscard]] char* getName() const ;

    [[nodiscard]] double getMathGrade() const;

    [[nodiscard]] double getEngGrade() const;

    [[nodiscard]] double getHisGrade() const;

    [[nodiscard]] double getAvgGrade() const;

    void setName(const char* name);

    void setMathGrade(double grade);

    void setEngGrade(double grade);

    void setHisGrade(double grade);

    void calculateAvgGrade();

   void showInfo();

};


#endif //LAB2_2_2__EXTRA_2__STUDENT_H
