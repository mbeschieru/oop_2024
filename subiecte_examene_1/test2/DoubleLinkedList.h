//
// Created by Marius Beschieru on 15.03.2024.
//

#ifndef TEST2_DOUBLELINKEDLIST_H
#define TEST2_DOUBLELINKEDLIST_H

#include "Node.h"
#include <iostream>

template<typename T>
class DoubleLinkedList {
private:
    int count;
    Node<T> *front, *rear;
public:
    DoubleLinkedList();

    ~DoubleLinkedList();

    void PushOnFront(T value);

    void PushOnBack(T value);

    void PrintAll(void (*printFunction)(const T &value));

    int GetCount();

    T PopFromBack();
};

template<typename T>
T DoubleLinkedList<T>::PopFromBack() {
    if (count == 0)
        throw std::underflow_error("List is empty");
    T value = rear->value;
    auto* temp = rear;
    rear = rear->prev;
    if (rear) {
        rear->next = nullptr;
    } else{
        front = nullptr;
    }
    delete temp;
    count--;
    return value;
}

template<typename T>
int DoubleLinkedList<T>::GetCount() {
    return count;
}

template<typename T>
void DoubleLinkedList<T>::PrintAll(void (*printFunction)(const T &)) {
    auto *current = front;
    std::cout << "Elements: " << count << " =>";
    while (current != nullptr) {
        printFunction(current->value);
        current = current->next;
    }
    std::cout << '\n';
}

template<typename T>
void DoubleLinkedList<T>::PushOnBack(T value) {
    auto *newNode = new Node<T>;
    newNode->value = value;
    newNode->next = nullptr;
    if (count == 0) {
        front = rear = newNode;
        newNode->prev = nullptr;
    } else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    count++;
}

template<typename T>
void DoubleLinkedList<T>::PushOnFront(T value) {
    auto *newNode = new Node<T>;
    newNode->value = value;
    newNode->prev = nullptr;
    if (count == 0) {
        front = rear = newNode;
        newNode->next = nullptr;
    } else {
        front->prev = newNode;
        newNode->next = front;
        front = newNode;
    }
    count++;
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
    while (front != nullptr) {
        Node<T> *tmp = front;
        front = front->next;
        delete tmp;
    }
    count = 0;
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    front = rear = nullptr;
    count = 0;
}

#endif //TEST2_DOUBLELINKEDLIST_H
