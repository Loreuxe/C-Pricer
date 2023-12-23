#ifndef BinaryTree_H
#define BinaryTree_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>

template <class T>
class BinaryTree {
    private:
        int _depth;
        std::vector<std::vector<T>> _tree;

    public:
        BinaryTree() : _depth(0) {}

        void setDepth(int depth);

        void setNode(int, int, T);

        T getNode(int , int ) const;
        ~BinaryTree() = default;
        void display() const;
        };



template <typename T>
int size_float(T num) {
    std::ostringstream oss;
    oss << num;
    std::string str = oss.str();

    size_t dotPos = str.find('.');
    if (dotPos != std::string::npos) {
        size_t nonZeroPos = str.find_last_not_of('0');
        if (nonZeroPos != std::string::npos && nonZeroPos > dotPos) {
            str.erase(nonZeroPos + 1);
        }
    }

    return str.length();
}
#endif