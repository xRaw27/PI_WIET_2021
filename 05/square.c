#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int used;
    int size;
} Array;

void initArray(Array *arr, int initialSize) {
    arr->array = malloc(initialSize * sizeof(int));
    arr->used = 0;
    arr->size = initialSize;
}

void appendArray(Array *arr, int element) {
    if (arr->used == arr->size) {
        arr->size *= 2;
        arr->array = realloc(arr->array, arr->size * sizeof(int));
    }
    arr->array[arr->used++] = element;
}

void freeArray(Array *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

int check_square(int **arr, int x, int y, int r) {
    int sum = 0;
    for (int i = x - r; i <= x + r; ++i) {
        sum += arr[i][y - r];
        sum += arr[i][y + r];
    }

    for (int i = y - r + 1; i <= y + r - 1; ++i) {
        sum += arr[x - r][i];
        sum += arr[x + r][i];
    }

    return sum;
}

int main() {
    int n, k, i, j, r, result = 0;
    scanf("%d %d", &n, &k);

    Array res_x;
    initArray(&res_x, 2);

    Array res_y;
    initArray(&res_y, 2);

    int **A = malloc(n * sizeof(int *));
    for (i = 0; i < n; ++i) {
        A[i] = malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            r = 1;
            while (i - r >= 0 && j - r >= 0 && i + r <= n - 1 && j + r <= n - 1) {
                if (check_square(A, i, j, r) == k) {
                    appendArray(&res_x, i);
                    appendArray(&res_y, j);
                    result += 1;
                }
                r += 2;
            }
        }
    }

    printf("%d\n", result);
    for (i = 0; i < result; ++i) {
        printf("%d %d\n", res_x.array[i], res_y.array[i]);
    }

    freeArray(&res_x);
    freeArray(&res_y);

    for (i = 0; i < n; ++i) {
        free(A[i]);
    }
    free(A);

    return 0;
}