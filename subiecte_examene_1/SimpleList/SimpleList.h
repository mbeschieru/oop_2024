//
// Created by Marius Beschieru on 28.03.2024.
//

#ifndef SIMPLELIST_SIMPLELIST_H
#define SIMPLELIST_SIMPLELIST_H

template<typename T>
struct Node {
    T value;
    Node<T> *next;
};

template<typename T>
class SimpleList {
private:
    static constexpr int MAX_SIZE = 50;
    Node<T> *head;
    int count{};

    void insertInList(T value);

public:
    SimpleList(std::initializer_list<T> v);

    class Itterator {
    private:
        Node<T> *current;
    public:

        Itterator(Node<T> *node);

        Itterator &operator++();

        T operator*();

        bool operator!=(const Itterator &other);
    };

    Itterator begin();

    Itterator end();
};

template<typename T>
SimpleList<T>::Itterator::Itterator(Node<T> *node): current(node) {}

template<typename T>
typename SimpleList<T>::Itterator SimpleList<T>::end() {
    return Itterator(nullptr);
}

template<typename T>
typename SimpleList<T>::Itterator SimpleList<T>::begin() {
    return Itterator(head);
}

template<typename T>
bool SimpleList<T>::Itterator::operator!=(const SimpleList::Itterator &other) {
    return current != other.current;
}

template<typename T>
T SimpleList<T>::Itterator::operator*() {
    if (current != nullptr)
        return current->value;
    return T();
}

template<typename T>
typename SimpleList<T>::Itterator &SimpleList<T>::Itterator::operator++() {
    if (current)
        current = current->next;
    return *this;
}

template<typename T>
SimpleList<T>::SimpleList(std::initializer_list<T> v) {
    for (auto el: v) {
        insertInList(el);
    }
}


template<typename T>
void SimpleList<T>::insertInList(T value) {
    if (head == nullptr) {
        head = new Node<T>;
        head->value = value;
        head->next = nullptr;
        count = 1;
        return;
    }
    auto *aux = new Node<T>;
    aux->value = value;
    aux->next = head;
    head = aux;
    count++;
}

#endif //SIMPLELIST_SIMPLELIST_H
