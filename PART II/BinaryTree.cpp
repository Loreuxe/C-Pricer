#include "BinaryTree.h"

template <class T>
void BinaryTree<T>::setDepth(int depth) {
    _depth = depth;
    _tree.resize(_depth+1);

    for (int i = 0; i <= _depth; ++i) {
        _tree[i].resize(i+1);
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
    for (int row = 0; row <= _depth; row++) {
        for (int col = 0; col <= row; col++) {
            std::cout << _tree[row][col] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    int row = 1;
    int num1 = size_float(_tree[0][0]);
    if (num1 < 3){
        std::cout << " ";
    }
    for (int k = 0; k < 3 * (_depth - row + 1); k++)
        std::cout << " ";
    std::cout << _tree[0][0];
    std::cout << std::endl;
    for (int k = 0; k < 3 * (_depth - row + 1) - 1; k++){
        std::cout << " ";
}
    std::cout << "/   \\ ";
        
    std::cout << std::endl;
    for (row; row < _depth; row++) {
        for (int k = 0; k < 3 * (_depth - row)+1; k++)
            std::cout << " ";
        for (int col = 0; col <= row; col++) {
            std::cout << _tree[row][col];
            int num1 = size_float(_tree[row][col]);
            int num2 = 0;
            if(col<row)
                num2 = size_float(_tree[row][col+1]);
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
                if (size_float(_tree[row][col]) == 1) {
                    std::cout << "   ";
                }
                else {
                    std::cout << "    ";
                }
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
    std::cout << " ";

    for (int col = 0; col <= row; col++) {
        std::cout << _tree[row][col];
        int num1 = size_float(_tree[row][col]);
        int num2 = 0;
        if (col < row)
            num2 = size_float(_tree[row][col + 1]);
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
            if (size_float(_tree[row][col]) == 1) {
                std::cout << "   ";
            }
            else {
                std::cout << "    ";
            }
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
    std::cout << std::endl;

    
}