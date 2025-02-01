#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

/*
template <typename T>
return_type function_name(parameters) {
    // function body
}
*/

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(const T& a, const T& b) {
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T max(const T& a, const T& b) {
    if (a > b)
        return a;
    else
        return b;
}

#endif