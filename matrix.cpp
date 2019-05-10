#include <iostream>

template <typename T, size_t size>
T diagonal_sum(const T (&arr)[size][size]) {
    T sum = 0;

    for(int i = 0; i < size; i++) {
        sum += arr[i][i];
    }

    return sum;
}

template <typename T, size_t size>
void print_arr(const T (&arr)[size][size]) {
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            std::cout << arr[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T, size_t size>
void transpose_arr(const T (&arr)[size][size], T (&output)[size][size]) {
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            output[col][row] = arr[row][col];
        }
    }
}

int main() {
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}, transpose[3][3];

    std::cout << "Original array:" << std::endl;
    print_arr(arr);

    std::cout << "Diagonal sum: " << diagonal_sum(arr) << std::endl;

    transpose_arr(arr, transpose);
    std::cout << "Transposed array:" << std::endl;
    print_arr(transpose);

    return 0;
}