#include <stdio.h>
#include <stdlib.h>

#define N 7

void generate_random_vector(int vector[], int size) {
    for (int i = 0; i < size; ++i) {
        vector[i] = rand() % N;
    }
}

void calculate_cooccurrences(int X[], int Y[], int M[][N]) {
    for (int i = 0; i < N; ++i) {
        M[X[i]][Y[i]] += 1;
    }
}

void print_matrix(int M[][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int X[N], Y[N];
    int M[N][N] = {0};

    // Seed para a função rand()
    srand((unsigned int)time(NULL));

    generate_random_vector(X, N);
    generate_random_vector(Y, N);

    printf("X = ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", X[i]);
    }

    printf("\nY = ");
    for (int i = 0; i < N; ++i) {
        printf("%d ", Y[i]);
    }

    calculate_cooccurrences(X, Y, M);

    printf("\n\nMatrix M:\n");
    print_matrix(M);

    return 0;
}
