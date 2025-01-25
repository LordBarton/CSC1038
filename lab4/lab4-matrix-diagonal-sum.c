#include <stdio.h>
#include <stdlib.h>

int diagonal_sum(int *matrix, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(matrix + i * n + i);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);

    int *matrix = (int *)malloc(n * n * sizeof(int));

    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n * n; i++) {
        matrix[i] = atoi(argv[i + 2]);
    }

    int result = diagonal_sum(matrix, n);

    printf("%d\n", result);

    return 0;
}
