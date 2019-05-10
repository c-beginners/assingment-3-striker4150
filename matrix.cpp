#include <iostream>

template <typename T>
int diagonal_sum(const T &mat, int size) {
    int sum = 0;

    for(int i = 0; i < size; i++) {
        sum += mat[i][i];
    }

    return sum;
}

template <typename T>
void print_mat(const T &mat, int size) {
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            std::cout << mat[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void transpose_mat(const T &mat, T &output, int size) {
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            output[col][row] = mat[row][col];
        }
    }
}

int main() {
    int **mat, **transpose, size;

    std::cout << "Enter an matrix size: ";
    std::cin >> size;

    // Dynamically allocate memory for matrix
    mat = new int*[size];
    for(int i = 0; i < size; i++) {
        mat[i] = new int[size];
    }

    // Dynamically allocate memory for transposed matrix
    transpose = new int*[size];
    for(int i = 0; i < size; i++) {
        transpose[i] = new int[size];
    }

    std::cout << "Enter the matrix data:" << std::endl;
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            std::cin >> mat[row][col];
        }
    }

    std::cout << "Original matrix:" << std::endl;
    print_mat(mat, size);

    std::cout << "Diagonal sum: " << diagonal_sum(mat, size) << std::endl;

    transpose_mat(mat, transpose, size);
    std::cout << "Transposed matrix:" << std::endl;
    print_mat(transpose, size);

    // Free matrix
    for(int i = 0; i < size; i++) {
        delete[] mat[i];
    }
    delete[] mat;

    // Free transposed matrix
    for(int i = 0; i < size; i++) {
        delete[] transpose[i];
    }
    delete[] transpose;

    return 0;
}