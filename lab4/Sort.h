//
// Created by Marius Beschieru on 19.03.2024.
//

#ifndef LAB4_SORT_H
#define LAB4_SORT_H

#include <random>
#include <iostream>
#include <initializer_list>
#include <cstring>

class Sort {
private:
    static constexpr int MAX_SIZE = 50;
    int *array;
    int count;

    static constexpr bool direction(bool ascendent, int a, int b);

    int partition(bool ascending, int start, int end);

    void quicksort(bool ascendent, int start, int end);

public:

    Sort(int count, int min, int max);

    Sort(int *list, int listSize);

    Sort(std::initializer_list<int> list);

    Sort(int count, ...);

    Sort(const char *string);

    void InsertSort(bool ascendent = false);

    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();

    int GetElementsCount();

    int GetElementFromIndex(int index);
};


#endif //LAB4_SORT_H
