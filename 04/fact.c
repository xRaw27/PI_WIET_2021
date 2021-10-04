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

void factorial(int n) {
    Array t;
    initArray(&t, 2);
    appendArray(&t, 1);

    int temp, last = 0;
    for (int x = 2; x <= n; ++x) {
        temp = 0;
        for (int i = 0; i <= last; ++i) {
            temp += t.array[i] * x;
            t.array[i] = temp % 10;
            temp /= 10;
        }
        while (temp > 0) {
            appendArray(&t, temp % 10);
            last += 1;
            temp /= 10;
        }
    }

    for (int i = last; i >= 0; --i) {
        printf("%d", t.array[i]);
    }
    printf("\nsize: %d %d", t.used, t.size);

    freeArray(&t);
}

int main() {
    int k = 0;
    scanf("%d", &k);
    factorial(k);

    return 0;
}
