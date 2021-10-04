#include <stdio.h>
#include <stdlib.h>

void spiral(int **arr, int n) {
    int a = 0, b = n - 1, current_number = 1, i;

    while (a <= b) {
        for (i = a; i < b; ++i) {
            arr[a][i] = current_number;
            current_number += 1;
        }
        for (i = a; i < b; ++i) {
            arr[i][b] = current_number;
            current_number += 1;
        }
        for (i = b; i > a; --i) {
            arr[b][i] = current_number;
            current_number += 1;
        }
        for (i = b; i > a; --i) {
            arr[i][a] = current_number;
            current_number += 1;
        }
        ++a;
        --b;
    }

    if (n % 2) {
        arr[n / 2][n / 2] = current_number;
    }
}


int main() {
    int n, i, j;
    scanf("%d", &n);

    int **A = malloc(n * sizeof(int *));
    for (i = 0; i < n; ++i) {
        A[i] = malloc(n * sizeof(int));
    }

    spiral(A, n);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; ++i) {
        free(A[i]);
    }
    free(A);

    return 0;
}

