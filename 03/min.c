#include <stdio.h>
#include <stdlib.h>

int left(int i){
    return 2 * i + 1;
}

int right(int i){
    return 2 * i + 2;
}

int parent(int i) {
    return (i - 1) / 2;
}


void max_heapify(int *A, int n, int i) {
    int l, r, m;
    l = left(i);
    r = right(i);
    m = i;
    if (l < n && A[l] > A[m]) {
        m = l;
    }
    if (r < n && A[r] > A[m]) {
        m = r;
    }
    if (m != i) {
        l = A[i];
        A[i] = A[m];
        A[m] = l;
        max_heapify(A, n, m);
    }
}

void build_max_heap(int *A, int n) {
    for (int i = parent(n - 1); i >=0; --i) {
        max_heapify(A, n, i);
    }
}


int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    int *t = malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
    }

    // dzięki zastosowaniu kopca złożoność algorytmu wynosi O(n + k*logn)
    build_max_heap(t, n);
    for (int i = 0; i < k; ++i) {
        t[0] = t[0] / 2;
        max_heapify(t, n, 0);
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += t[i];
    }
    printf("%d", sum);

    free(t);
    return 0;
}