//
// Created by Marius Beschieru on 19.03.2024.
//

#include "Sort.h"

Sort::Sort(int count, int min, int max) {
    if (count > MAX_SIZE)
        return;
    this->array = new int[MAX_SIZE];
    this->count = count;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(min, max);
    auto element = std::bind(distribution, generator);
    for (int i = 0; i < count; i++)
        array[i] = element();
    std::cout << "Sort(count,min,max) : \n";
    Print();
}

void Sort::Print() {
    for (int i = 0; i < count; i++)
        std::cout << array[i] << " ";
    std::cout << '\n';
}

Sort::Sort(int *list, int listSize) {
    if (listSize > MAX_SIZE)
        return;
    this->array = new int[MAX_SIZE];
    this->count = listSize;
    for (int i = 0; i < count; i++)
        this->array[i] = list[i];
    std::cout << "Sort(vector) : \n";
    Print();
}

Sort::Sort(std::initializer_list<int> list) {
    if (list.size() > MAX_SIZE)
        return;
    this->array = new int[MAX_SIZE];
    this->count = list.size();
    int i = 0;
    for (auto el: list)
        this->array[i++] = el;
    std::cout << "Sort(initializer list) : \n";
    Print();
}

Sort::Sort(int count, ...) {
    if (count > MAX_SIZE)
        return;
    this->array = new int[MAX_SIZE];
    this->count = count;
    std::va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
        this->array[i] = va_arg(args, int);
    va_end(args);
    std::cout << "Sort(va_list) : \n";
    Print();
}

Sort::Sort(const char *string) {
    this->count = 0;
    this->array = new int[MAX_SIZE];
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] == ',')
            i++;
        if (string[i] == '\0')
            break;
        int num = 0;
        while (string[i] != '\0' && string[i] != ',')
            num = num * 10 + (string[i] - '0'), i++;
        this->array[count++] = num;
    }
    std::cout << "Sort(string) : \n";
    Print();
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < count; i++) {
        int j = i - 1;
        int key = array[i];
        while (j >= 0 && direction(ascendent, array[j], key)) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    std::cout << "Array after insert sort(" << (ascendent ? "ascending" : "descending") << ")\n";
    Print();
}

constexpr bool Sort::direction(bool ascendent, int a, int b) {
    if (a == b)
        return false;
    if (ascendent)
        return a > b;
    return a < b;
}

int Sort::GetElementsCount() {
    return count;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= count)
        return -1;
    return array[index];
}

void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < count - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < count - i - 1; j++) {
            if (direction(ascendent, array[j], array[j + 1])) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    std::cout << "Array after bubble sort(" << (ascendent ? "ascending" : "descending") << ")\n";
    Print();
}

int Sort::partition(bool ascending, int start, int end) {
    int pivot = array[end];
    int smallerIndex = start;
    int greaterIndex = end;
    int *aux = new int[end - start + 1];

    for (int i = start; i < end; i++) {
        if (!direction(ascending, array[i], pivot)) {
            aux[smallerIndex - start] = array[i];
            smallerIndex++;
        } else if (direction(ascending, array[i], pivot)) {
            aux[greaterIndex - start] = array[i];
            greaterIndex--;
        }
    }

    for (int i = smallerIndex; i <= greaterIndex; i++) {
        aux[i - start] = pivot;
    }

    for (int i = start; i <= end; i++) {
        array[i] = aux[i - start];
    }

    delete[] aux;
    return smallerIndex;
}


void Sort::quicksort(bool ascendent, int start, int end) {
    if (start < end) {
        int index = partition(ascendent, start, end);
        quicksort(ascendent, start, index - 1);
        quicksort(ascendent, index + 1, end);
    }
}

void Sort::QuickSort(bool ascendent) {
    quicksort(ascendent, 0, count - 1);
    std::cout << "Array after quick sort(" << (ascendent ? "ascending" : "descending") << ")\n";
    Print();
}
