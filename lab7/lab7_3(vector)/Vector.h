//
// Created by Marius Beschieru on 09.04.2024.
//

#ifndef LAB7_3_VECTOR__VECTOR_H
#define LAB7_3_VECTOR__VECTOR_H

#include <iostream>

template<typename T>
class Vector {
private:
    T **elements;
    int count;
    int MAX_SIZE = 16;

    void expandSize();

public:
    Vector();

    ~Vector();

    Vector(Vector &other);

    Vector(Vector &&other) noexcept;

    void insert(int index, T value);

    void remove(int index);

    void print() const;

    void sort(int (*func)(T value1, T value2));

    T operator[](int index);
};

template<typename T>
T Vector<T>::operator[](int index) {
    if (index < 0 || index > MAX_SIZE)
        return -1;
    return *elements[index];
}

template<typename T>
void Vector<T>::expandSize() {
    MAX_SIZE += 10;
    T **newElements = new T *[MAX_SIZE]{};
    for (int i = 0; i < count; ++i) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

template<typename T>
Vector<T>::Vector() {
    elements = new T *[MAX_SIZE]{};
    count = 0;
}

template<typename T>
Vector<T>::~Vector() {
    for (int i = 0; i < count; i++)
        delete elements[i];
    delete[] elements;
}

template<typename T>
Vector<T>::Vector(Vector &other) {
    elements = new T *[MAX_SIZE]{};
    count = other.count;
    for (int i = 0; i < count; i++)
        elements[i] = new T(*other.elements[i]);
}

template<typename T>
Vector<T>::Vector(Vector &&other) noexcept {
    elements = other.elements;
    count = other.count;
    other.elements = nullptr;
    other.count = 0;
}

template<typename T>
void Vector<T>::insert(int index, T value) {
    if (index < 0 || index > count)
        return;

    if (count == MAX_SIZE) expandSize();

    elements[count] = new T(value);
    if (index < count) {
        for (int i = count; i > index; i--)
            elements[i] = elements[i - 1];
        *elements[index] = value;
    }
    count++;
}

template<typename T>
void Vector<T>::remove(int index) {
    if (index < 0 || index >= count)
        return;
    delete elements[index];
    for (int i = index; i < count - 1; i++) {
        elements[i] = elements[i + 1];
    }
    elements[count - 1] = nullptr;
    count--;
}

template<typename T>
void Vector<T>::print() const {
    for (int i = 0; i < count; i++)
        std::cout << *elements[i] << " ";
    std::cout << "\n";
}

template<typename T>
void Vector<T>::sort(int (*func)(T, T)) {
    std::sort(elements, elements + count, [&](T *a, T *b) { return func(*a, *b); });
}

#endif //LAB7_3_VECTOR__VECTOR_H
