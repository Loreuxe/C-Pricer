#include "BinaryTree.h"
template <class T>
void BinaryTree<T>::setDepth(int depth) {
    _depth = depth;
    _tree.resize(_depth);

    for (int i = 0; i < _depth; ++i) {
        _tree[i].resize(1 << i);
    }
}


template <class T>
void BinaryTree<T>::setNode(int row, int col, T value) {
    if (row < 0 || row >= _depth || col < 0 || col >row) {
        std::cerr << "Invalid row or column index." << std::endl;
        return;
    }
    _tree[row][col] = value;
}

template <class T>
T BinaryTree<T>::getNode(int row, int col) const{
    if (row < 0 || row >= _depth || col < 0 || col >row) {
        std::cerr << "Invalid row or column index." << std::endl;
        return T();
    }
    return _tree[row][col];
}
template <class T>
void BinaryTree<T>::display() const{
    int col;
    int row;
    std::cout << " ";

    for (row = 0; row < _depth; row++) {
        for (int k=_depth-row - 1; k > 0; k=k-1) {
            std::cout << "   ";

        }
        for (col = 0; col <= row; col++) {
            if (col>0) {

                int numDigits = std::to_string(_tree[row][col]).length()+ std::to_string(_tree[row][col-1]).length();
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
                    if (std::to_string(_tree[row][col]).length()==1)
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
            std::cout << _tree[row][col];

            
        }
        if (row < _depth-1){
            std::cout << std::endl;
            std::cout << "  ";

            for (int k = _depth - row-2; k > 0; k--) {
                std::cout << "   ";

            }
            for (col = 0; col <= row; col++) {
               
                std::cout << "/   ";
                
                std::cout << "\\ ";
                
            }
            }
        std::cout << std::endl;
    }
}

