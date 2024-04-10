//
// Created by Marius Beschieru on 10.04.2024.
//

#ifndef LAB7_2_TREE__TREENODE_H
#define LAB7_2_TREE__TREENODE_H

#include "ListNode.h"

template<typename T>
using func = bool (*)(const T &, const T &);

template<typename T>
struct TreeNode {
    T value;
    ListNode<T> *root_children;
    TreeNode<T> *next;

    TreeNode(T value);

    void add_node(T value);

    void delete_children();

    int count();

    void sort_children(func<T> comp = nullptr);
};

template<typename T>
void TreeNode<T>::sort_children(func<T> comp) {
    if (root_children == nullptr || root_children->next == nullptr)
        return;

    bool changed;
    do {
        changed = false;
        ListNode<T>* tmp = root_children;
        ListNode<T>* prev = nullptr;

        while (tmp != nullptr && tmp->next != nullptr) {
            bool shouldSwap = comp ? !comp(tmp->value, tmp->next->value)
                                   : tmp->value > tmp->next->value;

            if (shouldSwap) {
                auto aux = tmp->next;
                tmp->next = aux->next;
                aux->next = tmp;

                if (prev == nullptr) {
                    root_children = aux;
                } else {
                    prev->next = aux;
                }

                ListNode<T>* swapTmp = tmp;
                tmp = aux;
                aux = swapTmp;
                changed = true;
            }

            prev = tmp;
            tmp = tmp->next;
        }
    } while (changed);
}

template<typename T>
int TreeNode<T>::count() {
    int count = 0;
    auto tmp = root_children;
    while (tmp != nullptr) {
        tmp = tmp->next;
        count++;
    }
    return count;
}

template<typename T>
void TreeNode<T>::delete_children() {
    auto tmp = root_children;
    while (tmp != nullptr) {
        auto pNode = tmp->next;
        delete tmp;
        tmp = pNode;
    }
    root_children = nullptr;
}

template<typename T>
void TreeNode<T>::add_node(T value) {
    auto newNode = new ListNode<T>(value);
    if (root_children == nullptr) {
        root_children = newNode;
        return;
    }
    auto tmp = root_children;
    while (tmp->next != nullptr)
        tmp = tmp->next;
    tmp->next = newNode;
};

template<typename T>
TreeNode<T>::TreeNode(T value) {
    this->value = value;
    root_children = nullptr;
    next = nullptr;
};
#endif //LAB7_2_TREE__TREENODE_H
