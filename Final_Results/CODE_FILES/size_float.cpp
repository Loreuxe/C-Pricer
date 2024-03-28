#include <iostream>

#include <sstream>


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

    return static_cast<int>(str.length());
}