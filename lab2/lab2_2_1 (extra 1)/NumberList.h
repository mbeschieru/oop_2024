//
// Created by Marius Beschieru on 06.03.2024.
//

#ifndef LAB2_2_1_NUMBERLIST_H
#define LAB2_2_1_NUMBERLIST_H

#include <iostream>
class NumberList {
    int numbers[10];
    int count;
public:
    void Init();

    bool Add(int x);

    void Sort();

    void Print();
};


#endif //LAB2_2_1_NUMBERLIST_H
