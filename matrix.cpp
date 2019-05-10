#include <stdio.h>

template <typename T>
int diagonal_sum(const T &mat, const int size) {
    int sum = 0;

    for(int i = 0; i < size; i++) {
        sum += mat[i][i];
    }

    return sum;
}

template <typename T>
void print_mat(const T &mat, const int size) {
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            printf("%d ", mat[row][col]);
        }
        printf("\n");
    }
}

template <typename T>
void transpose_mat(const T &mat, T &output, const int size) {
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            output[col][row] = mat[row][col];
        }
    }
}

int main() {
    int **mat, **transpose, size;

    printf("Enter an matrix size: ");
    scanf(" %d", &size);

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

    printf("Enter the matrix data:\n");
    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++) {
            scanf(" %d", &mat[row][col]);
        }
    }

    printf("Original matrix:\n");
    print_mat(mat, size);

    printf("Diagonal sum: %d\n", diagonal_sum(mat, size));

    transpose_mat(mat, transpose, size);
    printf("Transposed matrix:\n");
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