#include <iostream>
#include "D:\c++\utils\safe_input.h"
#include "template_functions.h"

template <typename T>
void test(T array, size_t size) {
    init(array, size);
    print(array, size);
    std::cout << "enter a left index\n";
    int left = cin_in_range<int>(0, size);
    std::cout << "enter a right index\n";
    int right = cin_in_range<int>(left, size);
    int sum = calc_sum(array, left, right, size);
    std::cout << sum << '\n';
}

void test_int() {
    std::cout << "enter the size of the array\n";
    size_t size = cin_only_positive<size_t>();
    int* array = (int*)std::malloc(sizeof(int) * size);
    test(array, size);
}

void test_double() {
    std::cout << "enter the size of the array\n";
    size_t size = cin_only_positive<size_t>();
    double* array = (double*)std::malloc(sizeof(double) * size);
    test(array, size);

}

int main() {
    std::cout << "Testing int...\n";
    test_int();
    std::cout << "Teseting double...\n";
    test_double();
}