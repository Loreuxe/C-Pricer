#include "BinaryTree.h"
template <class T>
void BinaryTree<T>::setDepth(int depth) {
    _depth = depth;
    _tree.resize(_depth+1);

    for (int i = 0; i <= _depth; ++i) {
        _tree[i].resize(1 << i);
    }
}


template <class T>
void BinaryTree<T>::setNode(int row, int col, T value) {
    if (row < 0 || row > _depth || col < 0 || col >row) {
        std::cerr << "Invalid row or column index." << std::endl;
        return;
    }
    _tree[row][col] = value;
}

template <class T>
T BinaryTree<T>::getNode(int row, int col) const {
    if (row < 0 || row > _depth || col < 0 || col >row) {
        std::cerr << "Invalid row or column index." << std::endl;
        return T();
    }
    return _tree[row][col];
}
template <class T>
void BinaryTree<T>::display() const {
    int row = 0;
    std::cout << " ";
    for (row; row < _depth; row++) {
        for (int k = 0; k < 3 * (_depth - row); k++)
            std::cout << " ";
        for (int col = 0; col <= row; col++) {
            std::cout << _tree[row][col];
            int num1 = std::to_string(_tree[row][col]).length();
            int num2 = 0;
            if(col<row)
                num2 = std::to_string(_tree[row][col + 1]).length();
            int numDigits = num1 + num2;

            switch (numDigits) {
            case 2:
                std::cout << "      ";
                break;
            case 3:
                std::cout << "     ";
                break;
            case 4:
                std::cout << "    ";
                break;
            case 5:
                if (std::to_string(_tree[row][col]).length() == 1)
                    std::cout << "   ";
                else
                    std::cout << "    ";
                break;

            case 6:
                std::cout << "   ";
                break;

            default:
                std::cout << "  ";
                break;
            }
        }
        std::cout<<std::endl;
        for (int k = 0; k < 3 * (_depth - row) - 1; k++)
            std::cout << " ";
        for (int col = 0; col <= row; col++) {
            std::cout << "/   \\ ";

        }
        std::cout << std::endl;

       
    }
    for (int col = 0; col <= row; col++) {
        std::cout << _tree[row][col];
        int num1 = std::to_string(_tree[row][col]).length();
        int num2 = 0;
        if (col < row)
            num2 = std::to_string(_tree[row][col + 1]).length();
        int numDigits = num1 + num2;

        switch (numDigits) {
        case 2:
            std::cout << "     ";
            break;
        case 3:
            std::cout << "     ";
            break;
        case 4:
            std::cout << "    ";
            break;
        case 5:
            if (std::to_string(_tree[row][col]).length() == 1)
                std::cout << "   ";
            else
                std::cout << "    ";
            break;

        case 6:
            std::cout << "   ";
            break;

        default:
            std::cout << "  ";
            break;
        }


    }
    std::cout << std::endl;


}