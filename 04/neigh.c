#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, r, curr_sum, j, k;
    scanf("%d %d", &n, &r);

    int **F = malloc(n * sizeof(int *));
    int **W = malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        F[i] = malloc(n * sizeof(int));
        W[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &F[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        curr_sum = 0;
        for (j = 0; j <= r; ++j) {
            curr_sum += F[i][j];
        }

        j = r;
        k = 0;
        W[i][k] = curr_sum;
        while (k < n - 1) {
            ++k;
            ++j;
            if (k <= r) {
                curr_sum += F[i][j];
            } else if (k >= n - r) {
                curr_sum -= F[i][j - (2 * r) - 1];
            } else {
                curr_sum -= F[i][j - (2 * r) - 1];
                curr_sum += F[i][j];
            }
            W[i][k] = curr_sum;
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            F[x][y] = W[x][y];
        }
    }

    for (int i = 0; i < n; ++i) {
        curr_sum = 0;
        for (j = 0; j <= r; ++j) {
            curr_sum += F[j][i];
        }

        j = r;
        k = 0;
        W[k][i] = curr_sum;
        while (k < n - 1) {
            ++k;
            ++j;
            if (k <= r) {
                curr_sum += F[j][i];
            } else if (k >= n - r) {
                curr_sum -= F[j - (2 * r) - 1][i];
            } else {
                curr_sum -= F[j - (2 * r) - 1][i];
                curr_sum += F[j][i];
            }
            W[k][i] = curr_sum;
        }
    }

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf("%d ", W[x][y]);
        }
        printf("\n");
    }

    return 0;
}
