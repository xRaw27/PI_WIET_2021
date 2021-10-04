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

    scanf("%d %d", &n, &k);

    int **T = alloc_2d_array(n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &T[i][j]);
        }
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            // w prawo
            sum = 0;
            x = j;
            for (l = 0; l < k; ++l) {
                sum += T[i][x];
                x = (x + 1) % n;
            }
            if (sum > result) {
                result = sum;
            }

            // w dół
            sum = 0;
            y = i;
            for (l = 0; l < k; ++l) {
                sum += T[y][j];
                y = (y + 1) % n;
            }
            if (sum > result) {
                result = sum;
            }

            // w prawo dół
            sum = 0;
            x = j;
            y = i;
            for (l = 0; l < k; ++l) {
                sum += T[y][x];
                x = (x + 1) % n;
                y = (y + 1) % n;
            }
            if (sum > result) {
                result = sum;
            }

            // w prawo górę
            sum = 0;
            x = j;
            y = i;
            for (l = 0; l < k; ++l) {
                sum += T[y][x];
                x = (x + 1) % n;
                --y;
                if (y == -1) {
                    y = n - 1;
                }
            }
            if (sum > result) {
                result = sum;
            }

        }
    }

    printf("%d", result);

    free_2d_array(T, n);

    return 0;
}
