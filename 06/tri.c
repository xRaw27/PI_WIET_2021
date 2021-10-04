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

int solve(int n, int m) {
    int i, j, k, x, y, count = 0;

    int **T = alloc_2d_array(n, n);
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            T[i][j] = 0;
        }
    }

    for (i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        T[x - 1][y - 1] = 1;
    }

    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            for (k = 0; k < j; ++k) {
                if (i < k && T[i][j] == T[k][j] && T[k][j] == T[i][k]) {
                    ++count;
                }
            }
        }
    }

    free_2d_array(T, n);

    return count;
}

int main() {
    int n, m, result;
    scanf("%d %d", &n, &m);

    result = solve(n, m);
    printf("%d", result);

    return 0;
}
