#pragma once
#include <vector>
#include <iostream>
#include <string>
template <typename T>
class BinaryTree {
    private:
        int _depth;
        std::vector<std::vector<T>> _tree;

    public:
        BinaryTree() : _depth(0) {}

        void setDepth(int);

        void setNode(int, int, T);

        T getNode(int , int );

        void display();
        };

        