//
// Created by Marius Beschieru on 06.03.2024.
//

#include "global.h"

int compare_name(Student &s1, Student &s2) {
    int result = std::strcmp(s1.getName(), s2.getName());
    if (result == 0)
        return 0;
    if (result < 0)
        return -1;
    return 1;
}

int compare_mathGrade(Student &s1, Student &s2) {
    double grade_1, grade_2;
    grade_1 = s1.getMathGrade();
    grade_2 = s2.getMathGrade();
    if (grade_1 == grade_2)
        return 0;
    if (grade_1 < grade_2)
        return -1;
    return 1;
}

int compare_engGrade(Student &s1, Student &s2) {
    double grade_1, grade_2;
    grade_1 = s1.getEngGrade();
    grade_2 = s2.getEngGrade();
    if (grade_1 == grade_2)
        return 0;
    if (grade_1 < grade_2)
        return -1;
    return 1;
}

int compare_hisGrade(Student &s1, Student &s2) {
    double grade_1, grade_2;
    grade_1 = s1.getHisGrade();
    grade_2 = s2.getHisGrade();
    if (grade_1 == grade_2)
        return 0;
    if (grade_1 < grade_2)
        return -1;
    return 1;
}

int compare_avgGrade(Student &s1, Student &s2) {
    double grade_1, grade_2;
    grade_1 = s1.getAvgGrade();
    grade_2 = s2.getAvgGrade();
    if (grade_1 == grade_2)
        return 0;
    if (grade_1 < grade_2)
        return -1;
    return 1;
}