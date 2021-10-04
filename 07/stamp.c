#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int main() {
    int i, j, k, l, x, y, sum, n, result = INT_MIN;

    scanf("%d %d %d", &n, &k, &l);

    int **T = alloc_2d_array(n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &T[i][j]);
        }
    }

    int **P = alloc_2d_array(k, l);
    for (i = 0; i < k; i++) {
        for (j = 0; j < l; j++) {
            scanf("%d", &P[i][j]);
        }
    }

    for (i = 0; i < n - k + 1; ++i) {
        for (j = 0; j < n - l + 1; ++j) {
            sum = 0;
            for (x = 0; x < k; ++x) {
                for (y = 0; y < l; ++y) {
                    if (P[x][y]) {
                        sum += T[i + x][j + y];
                    }
                }
            }

            if (sum > result) {
                result = sum;
            }
        }
    }

    printf("%d", result);

    free_2d_array(T, n);
    free_2d_array(P, k);

    return 0;
}
