#include <stdio.h>
#include <stdlib.h>

int partition(int *A, int p, int r) {
    int x, pivot, i;
    x = p + (rand() % (r - p));
    pivot = A[x];
    A[x] = A[r];
    A[r] = pivot;
    i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j] <= pivot) {
            x = A[j];
            A[j] = A[i + 1];
            A[i + 1] = x;
            ++i;
        }
    }
    x = A[r];
    A[r] = A[i + 1];
    A[i + 1] = x;
    return i + 1;
}

void quick_sort(int *A, int p, int r) {
    int q;
    while (p < r) {
        q = partition(A, p, r);
        if (q - p <= r - q) {
            quick_sort(A, p, q - 1);
            p = q + 1;
        }
        else {
            quick_sort(A, q + 1, r);
            r = q - 1;
        }
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    int *t = malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }

    quick_sort(t, 0, n - 1);


    int result = 0, j;
    for (int i = 0; i < n; ++i) {
        j = i;
        while (j + 1 < n && t[j + 1] == t[j]) {
            ++j;
        }

        if ((i - 1 > 0 && t[i] - t[i - 1] <= k) || (j + 1 < n && t[j + 1] - t[j] <= k)) {
            result += j - i + 1;
        }
        i = j;
    }

    printf("%d", result);
    free(t);

    return 0;
}