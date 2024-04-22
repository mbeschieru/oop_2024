//
// Created by Marius Beschieru on 15.03.2024.
//

#ifndef TEST2_NODE_H
#define TEST2_NODE_H
template<typename T>
struct Node {
    T value;
    Node<T> *next, *prev;
};
#endif //TEST2_NODE_H
