//
// Created by Marius Beschieru on 06.03.2024.
//

#include "NumberList.h"

void NumberList::Init() {
    count = 0;
}

bool NumberList::Add(int x) {
    if (count == 10) {
        std::cout<<"Array is full \n";
        return false;
    }
    numbers[count++] = x;
    return true;
}

void NumberList::Sort() {
    for (int i = 0 ; i < count-1 ; ++i)
    {
        bool swapped = false;
        for (int j = 0 ; j < count-i-1; ++j)
            if (numbers[j] > numbers[j+1])
                std::swap(numbers[j],numbers[j+1]), swapped = true;
        if (!swapped)
            break;
    }
}

void NumberList::Print() {
    for (int i = 0 ; i < count ; i++)
        std::cout<<numbers[i]<<" ";
    std::cout<<'\n';
}
