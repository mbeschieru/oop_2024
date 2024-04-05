//
// Created by Marius Beschieru on 28.03.2024.
//

#ifndef SIMPLELIST2_SIMPLELIST_H
#define SIMPLELIST2_SIMPLELIST_H

#include <initializer_list>

template<typename T>
class SimpleList {
private:
    T *list;
    size_t size;
    static constexpr int MAX_SIZE = 100;

public:
    SimpleList(std::initializer_list<T> list);

    ~SimpleList();

    class Iterator {
    private:
        T *aux;
    public:
        Iterator(T *list);

        Iterator &operator++();

        T &operator*();

        bool operator!=(const Iterator &other);

    };

    Iterator begin();

    Iterator end();

    explicit operator int();

    SimpleList<T> &operator+=(T value);

    SimpleList<T> &operator+=(std::initializer_list<T> initializerList);

    SimpleList<T> &operator-=(T value);

    int operator[](int index);

};

template<typename T>
SimpleList<T> &SimpleList<T>::operator-=(T value) {
    int i = 0;
    while (i < size) {
        if (list[i] == value) {
            for (int j = i; j < size; j++) {
                list[j] = list[j + 1];
            }
            size--;
        } else
            i++;
    }
    return *this;
}

template<typename T>
SimpleList<T> &SimpleList<T>::operator+=(std::initializer_list<T> initializerList) {
    for (auto el: initializerList)
        *this += el;
    return *this;
}

template<typename T>
SimpleList<T> &SimpleList<T>::operator+=(T value) {
    for (int i = size - 1; i >= 0; i--)
        list[i + 1] = list[i];
    list[0] = value;
    size++;
    return *this;
}

template<typename T>
int SimpleList<T>::operator[](int index) {
    int count = 0;
    for (size_t i = 0; i < size; i++) {
        if (list[i] == index) {
            count++;
        }
    }
    return count;
}

template<typename T>
SimpleList<T>::operator int() {
    return size;
}

template<typename T>
typename SimpleList<T>::Iterator SimpleList<T>::end() {
    return Iterator(list + size);
}

template<typename T>
typename SimpleList<T>::Iterator SimpleList<T>::begin() {
    return Iterator(list);
}

template<typename T>
bool SimpleList<T>::Iterator::operator!=(const SimpleList::Iterator &other) {
    return aux != other.aux;
}

template<typename T>
T &SimpleList<T>::Iterator::operator*() {
    return *aux;
}

template<typename T>
typename SimpleList<T>::Iterator &SimpleList<T>::Iterator::operator++() {
    ++aux;
    return *this;
}

template<typename T>
SimpleList<T>::Iterator::Iterator(T *list) : aux(list) {}

template<typename T>
SimpleList<T>::~SimpleList() {
    delete[]list;
    size = 0;
}

template<typename T>
SimpleList<T>::SimpleList(std::initializer_list<T> list) {
    size = list.size();
    this->list = new T[MAX_SIZE];
    size_t i = size - 1;
    for (auto el: list)
        this->list[i--] = el;
}

#endif //SIMPLELIST2_SIMPLELIST_H
