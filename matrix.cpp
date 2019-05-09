#include <iostream>

template <typename T, size_t rows, size_t cols>
T diagonal_sum(const T (&arr)[rows][cols]) {
    T sum = 0;

    for(int i = 0; i < (rows < cols ? rows : cols); i++) {
        sum += arr[i][i];
    }

    return sum;
}

int main() {
    return 0;
}