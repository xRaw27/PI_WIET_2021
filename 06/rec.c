#include <stdio.h>
#include <stdlib.h>

int **alloc_2d_array(int n, int m) {
    int **arr = malloc(n * sizeof(int *));

    for (int i = 0; i < n; ++i) {
        arr[i] = malloc(m * sizeof(int));
    }

    return arr;
}

void free_2d_array(int **T, int n) {
    for (int i = 0; i < n; ++i) {
        free(T[i]);
    }
    free(T);
}

int solve(int size, int n) {
    int i, j, x1, x2, y1, y2, x, y, result = 0;

    int **T = alloc_2d_array(size, size);
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            T[i][j] = 0;
        }
    }

    for (i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (x = x1 + (size / 2); x < x2 + (size / 2); ++x) {
            for (y = y1 + (size / 2); y < y2 + (size / 2); ++y) {
                T[x][y] = (T[x][y] + 1) % 2;
            }
        }
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            result += T[i][j];
        }
    }

    free_2d_array(T, size);

    return result;
}

int main() {
    int n, result;
    scanf("%d", &n);

    result = solve(200, n);
    printf("%d", result);

    return 0;
}
