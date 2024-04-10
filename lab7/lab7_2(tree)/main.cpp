//
// Created by Marius Beschieru on 10.04.2024.
//
#include "Tree.h"
#include <iostream>

bool compare(const int &a, const int &b) {
    return a == b;
}

bool compare2(const int &a, const int &b) {
    return a < b;
}

int main() {
    Tree<int> tree;
    tree.add_node(nullptr, 4);
    auto root = tree.get_root();
    auto test = new TreeNode<int>(15);
    tree.add_node(test, 12);
    std::cout << root->next << '\n';
    tree.delete_node(test);
    std::cout << root->next << '\n';
    auto test2 = new TreeNode<int>(14);
    auto test3 = new TreeNode<int>(16);
    tree.add_node(test2, 8);
    tree.add_node(test3, 3);
    tree.add_node(test3, 2);

    std::cout << tree.get_node(test2) << '\n';
    auto foundNode = tree.find(8, compare);
    std::cout << foundNode << '\n';
    tree.insert(test3, 4, 1);
    std::cout << test3->root_children->next->value << '\n';
    std::cout << tree.count(test3) << '\n';
    tree.sort(test3, compare2);
    std::cout << test3->root_children->value << " " << test3->root_children->next->value;
}