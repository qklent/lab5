#include <iostream>
#include "D:\c++\utils\safe_input.h"

template <typename T>
class Array {
    size_t size = 10;
    T* array;

public:
    Array() {
        array = (T*)std::malloc(sizeof(T) * size);
    }

    Array(size_t size): size(size) {
        array = (T*)std::malloc(sizeof(T) * size);
    }

    ~Array() {
        delete[] array;
    }

    void init() {
        for (int i = 0; i < size; ++i) {
            array[i] = cin<T>();
        }
    }

    void print_array() { 
        for (int i = 0; i < size; ++i) {
            std::cout << array[i] << ' ';
        }
        std::cout << '\n';
    }
    
    T calc_sum(int left, int right) {
        if (check_index(left) && check_index(right)) {
            T sum = 0;
            for (int i = left; i <= right; ++i) {
                sum += array[i];
            }
            return sum;
        }
        else {
            std::cout << "index out of range\n";
            return -1;
        }
    }

    bool check_index(int index) {
        return (0 < index && index < size);
    }
};

// template<>
// class Array<int> {
// public:
//     int calc_sum(int left, int right) { 
//         if (check_index(left) && check_index(right)) {
//             int sum = 0;
//             for (int i = left; i <= right; ++i) {
//                 if (array[i] > 0) { 
//                     sum += array[i];
//                 }
//             }
//             return sum;
//         }
//         else {
//             std::cout << "index out of range\n";
//             return -1;
//         }
//     }
// };

int main () {
    std::cout << "enter size of array\n";
    size_t n = cin_only_positive<size_t>();
    Array<double> array(n);
    
    std::cout << "enter 1 number per line\n";
    array.init();
    array.print_array();
    std::cout << array.calc_sum(1, 3) << '\n';

}