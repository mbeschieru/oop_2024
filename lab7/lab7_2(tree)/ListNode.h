//
// Created by Marius Beschieru on 10.04.2024.
//

#ifndef LAB7_2_TREE__LISTNODE_H
#define LAB7_2_TREE__LISTNODE_H

template<typename T>
struct ListNode {
    T value;
    ListNode<T> *next;

    ListNode(T value);

};

template<typename T>
ListNode<T>::ListNode(T value) {
    this->value = value;
    next = nullptr;
}

#endif //LAB7_2_TREE__LISTNODE_H
