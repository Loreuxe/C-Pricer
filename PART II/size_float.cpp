#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
int getLength(T number) {
    // Convert the number to a string
    std::string numberString = std::to_string(number);

    // Remove trailing zeros after the decimal point (for floating-point numbers)
    if constexpr (std::is_floating_point_v<T>) {
        size_t found = numberString.find_last_not_of('0');
        if (found != std::string::npos && numberString[found] == '.')
            found--;

        return static_cast<int>(found) + 1;
    } else {  // For integer numbers
        return static_cast<int>(numberString.size());
    }
}


