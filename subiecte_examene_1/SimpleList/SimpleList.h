//
// Created by Marius Beschieru on 16.04.2024.
//

#ifndef P555555555_SIMPLELIST_H
#define P555555555_SIMPLELIST_H

#include <initializer_list>

template<typename T>
class SimpleList {
private:
    static constexpr int MAX_SIZE = 64;
    T **array;
    int count;
public:
    SimpleList(std::initializer_list<T> list);

    class Iterator {
    private:
        T **ptr;
    public:
        Iterator(T **array);

        Iterator operator++();

        T &operator*();

        bool operator!=(const Iterator &other);
    };

    Iterator begin();

    Iterator end();

    SimpleList<T> &operator+=(T value);

    SimpleList<T> &operator+=(std::initializer_list<T> list);

    int operator[](int value);

    explicit operator int();

    SimpleList<T> &operator-=(T value);
};

template<typename T>
SimpleList<T> &SimpleList<T>::operator-=(T value) {
    for (int i = 0; i < count; i++) {
        if (*array[i] == value) {
            for (int j = i; j < count - 1; j++)
                array[j] = array[j + 1];
            count--;
            array[count] = nullptr;
            i--;
        }
    }
    return *this;
}

template<typename T>
SimpleList<T>::operator int() {
    return count;
}

template<typename T>
int SimpleList<T>::operator[](int value) {
    int nr = 0;
    for (int i = 0; i < count; i++) {
        if (*array[i] == value)
            nr++;
    }
    return nr;
}

template<typename T>
SimpleList<T> &SimpleList<T>::operator+=(std::initializer_list<T> list) {
    int toAddSize = list.size();
    if (count >= MAX_SIZE || count + toAddSize >= MAX_SIZE)
        return *this;
    for (auto el: list) {
        *this += el;
    }
    return *this;
}

template<typename T>
SimpleList<T> &SimpleList<T>::operator+=(T value) {
    if (count >= MAX_SIZE || count + 1 >= MAX_SIZE) {
        return *this;
    }
    count++;
    for (int i = count - 1; i >= 1; i--) {
        array[i] = array[i - 1];
    }
    array[0] = new int(value);
    return *this;
}

template<typename T>
typename SimpleList<T>::Iterator SimpleList<T>::begin() {
    return SimpleList::Iterator(array);
}

template<typename T>
typename SimpleList<T>::Iterator SimpleList<T>::end() {
    return SimpleList::Iterator(array + count);
}

template<typename T>
bool SimpleList<T>::Iterator::operator!=(const SimpleList::Iterator &other) {
    return this->ptr != other.ptr;
}

template<typename T>
T &SimpleList<T>::Iterator::operator*() {
    return **ptr;
}

template<typename T>
typename SimpleList<T>::Iterator SimpleList<T>::Iterator::operator++() {
    ++ptr;
    return *this;
}

template<typename T>
SimpleList<T>::Iterator::Iterator(T **array) {
    ptr = array;
}

template<typename T>
SimpleList<T>::SimpleList(std::initializer_list<T> list) {
    count = list.size();
    if (count >= MAX_SIZE) {
        count = 0;
        return;
    }
    int index = count - 1;
    array = new T *[MAX_SIZE];
    for (auto el: list) {
        array[index--] = new T(el);
    }
}

#endif //P555555555_SIMPLELIST_H
