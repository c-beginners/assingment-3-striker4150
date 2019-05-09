#include <iostream>

template <typename T, size_t rows, size_t cols>
T diagonal_sum(const T (&arr)[rows][cols]) {
    T sum = 0;

    for(int i = 0; i < (rows < cols ? rows : cols); i++) {
        sum += arr[i][i];
    }

    return sum;
}

template <typename T, size_t rows, size_t cols>
void print_arr(const T (&arr)[rows][cols]) {
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            std::cout << arr[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T, size_t rows, size_t cols>
void transpose_arr(const T (&arr)[rows][cols], T (&output)[cols][rows]) {
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            output[col][row] = arr[row][col];
        }
    }
}

int main() {
    int arr[3][2] = {{1,2},{3,4},{5,6}}, transpose[2][3];

    std::cout << "Original array:" << std::endl;
    print_arr(arr);

    std::cout << "Diagonal sum: " << diagonal_sum(arr) << std::endl;

    transpose_arr(arr, transpose);
    std::cout << "Transposed array:" << std::endl;
    print_arr(transpose);

    return 0;
}