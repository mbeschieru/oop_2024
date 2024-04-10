//
// Created by Marius Beschieru on 10.04.2024.
//

#ifndef LAB7_2_TREE__TREE_H
#define LAB7_2_TREE__TREE_H

#include "ListNode.h"
#include "TreeNode.h"

template<typename T>
using func = bool (*)(const T &a, const T &b);

template<typename T>
class Tree {
private:
    TreeNode<T> *root;

    TreeNode<T> *find_recursive(TreeNode<T> *node, const T &value, func<T> compare);

public:
    Tree();

    void add_node(TreeNode<T> *parentNode, T val);

    TreeNode<T> *get_root();

    TreeNode<T> *get_node(TreeNode<T> *parentNode);

    void delete_node(TreeNode<T> *parentNode);

    TreeNode<T> *find(const T &value, func<T> compare);

    void insert(TreeNode<T> *parentNode, T value, int index);

    int count(TreeNode<T> *parentNode);

    void sort(TreeNode<T> *parentNode, func<T> comp);
};

template<typename T>
void Tree<T>::sort(TreeNode<T> *parentNode, func<T> comp) {
    auto tmp = root;
    if (parentNode == nullptr)
        return;
    while (tmp != nullptr) {
        if (tmp == parentNode) {
            parentNode->sort_children(comp);
            return;
        }
        tmp = tmp->next;
    }
}


template<typename T>
int Tree<T>::count(TreeNode<T> *parentNode) {
    if (parentNode == nullptr)
        return root->count();
    auto tmp = root;
    bool inTree = false;
    while (tmp != nullptr) {
        if (tmp == parentNode) {
            inTree = true;
            break;
        }
        tmp = tmp->next;
    }
    if (inTree)
        return parentNode->count();
    return -1;
}

template<typename T>
void Tree<T>::insert(TreeNode<T> *parentNode, T value, int index) {
    if (parentNode == nullptr) {
        return;
    }

    auto newNode = new ListNode<T>(value);
    if (index == 0) {
        newNode->next = parentNode->root_children;
        parentNode->root_children = newNode;
        return;
    }

    auto tmp = parentNode->root_children;
    int count = 0;
    while (tmp != nullptr && count < index - 1) {
        tmp = tmp->next;
        count++;
    }
    if (tmp != nullptr) {
        newNode->next = tmp->next;
        tmp->next = newNode;
    }

}

template<typename T>
TreeNode<T> *Tree<T>::find(const T &value, func<T> compare) {
    return find_recursive(root, value, compare);
}

template<typename T>
TreeNode<T> *Tree<T>::find_recursive(TreeNode<T> *node, const T &value, func<T> compare) {
    if (node == nullptr) {
        return nullptr;
    }
    if (compare(node->value, value)) { return node; }

    for (auto child = node->root_children; child != nullptr; child = child->next) {
        if (child->value == value)
            return node;
    }
    return find_recursive(node->next, value, compare);
}

template<typename T>
void Tree<T>::delete_node(TreeNode<T> *parentNode) {
    if (parentNode == nullptr)
        return;

    parentNode->delete_children();
    if (parentNode == root) {
        auto nextRoot = root->next;
        delete root;
        root = nextRoot;
        return;
    }

    auto tmp = root;
    TreeNode<T> *prev = nullptr;
    while (tmp != nullptr && tmp != parentNode) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == parentNode) {
        if (prev != nullptr) {
            prev->next = tmp->next;
        }
        delete tmp;
    }
}

template<typename T>
TreeNode<T> *Tree<T>::get_node(TreeNode<T> *parentNode) {
    if (parentNode == nullptr)
        return root;
    return parentNode;
}

template<typename T>
TreeNode<T> *Tree<T>::get_root() {
    return root;
}

template<typename T>
void Tree<T>::add_node(TreeNode<T> *parentNode, T val) {
    if (parentNode == nullptr) {
        auto newNode = new TreeNode<T>(val);
        newNode->next = root;
        root = newNode;
    } else {
        TreeNode<T> *tmp = root;
        bool parentNodeFound = false;

        while (tmp != nullptr) {
            if (tmp == parentNode) {
                parentNodeFound = true;
                break;
            }
            tmp = tmp->next;
        }
        if (parentNodeFound) {
            parentNode->add_node(val);
        } else {
            parentNode->add_node(val);
            if (root == nullptr) {
                root = parentNode;
            } else {
                tmp = root;
                while (tmp->next != nullptr) {
                    tmp = tmp->next;
                }
                tmp->next = parentNode;
            }
        }
    }
}

template<typename T>
Tree<T>::Tree() {
    root = nullptr;
}


#endif //LAB7_2_TREE__TREE_H
