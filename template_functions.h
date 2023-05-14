#include <iostream>
#include "D:\c++\utils\safe_input.h"

template <typename T>
void init(T* array, size_t size) {
    std::cout << "enter 1 number per line\n";
    for (int i = 0; i < size; ++i) {
        array[i] = cin<T>();
    }
}

template <typename T>
void print(T array, size_t size) { 
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

bool check_index(int index, size_t size) {
    return (0 < index && index < size);
}

template <typename T>
T calc_sum(T* array, int left, int right, size_t size) {
    if (check_index(left, size) && check_index(right, size)) {
        T sum = 0;
        for (int i = left; i <= right; ++i) {
            sum += array[i];
        }
        return sum;
    }
    else {
        std::cout << "array index out of range\n";
        return -1;
    }
}

template <>
int calc_sum(int* array, int left, int right, size_t size) {
    if (check_index(left, size) && check_index(right, size)) {
        int sum = 0;
        for (int i = left; i <= right; ++i) {
            if (array[i] > 0) { 
                sum += array[i];
            }
        }
        return sum;
    }
    else {
        std::cout << "array index out of range\n";
        return -1; 
    }
}