#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int value) {
    stack[++(*top)] = value;
}

int pop(int *stack, int *top) {
    if (*top < 0) {
        return -1;
    } else {
        return stack[(*top)--];
    }
}

void update_max_field(int *max_field, int val) {
    if (val > *max_field) {
        *max_field = val;
    }
}

int main() {
    int n, i, j, max_field = 0, top, temp;
    scanf("%d", &n);

    int **A = malloc(n * sizeof(int *));
    for (i = 0; i < n; ++i) {
        A[i] = malloc(n * sizeof(int));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int *F = malloc(n * sizeof(int));
    for (i = 0; i < n; ++i) {
        F[i] = 0;
    }

    int *stack = malloc(n * sizeof(int));

    for (int row = 0; row < n; ++row) {
        for (i = 0; i < n; ++i) {
            if (A[row][i] == 1) {
                F[i] = 0;
            } else {
                F[i] += 1;
            }
        }

        top = -1;
        for (i = 0; i < n; ++i) {
            if (top == -1 || F[i] >= F[stack[top]]) {
                push(stack, &top, i);
            }
            else {
                while (top >= 0 && F[i] < F[stack[top]]) {
                    if (top == 0) {
                        temp = pop(stack, &top);
                        update_max_field(&max_field, i * F[temp]);
                    } else {
                        temp = pop(stack, &top);
                        update_max_field(&max_field, (i - stack[top] - 1) * F[temp]);
                    }
                }
                push(stack, &top, i);
            }
        }

        while (top >= 0) {
            if (top == 0) {
                temp = pop(stack, &top);
                update_max_field(&max_field, n * F[temp]);
            } else {
                temp = pop(stack, &top);
                update_max_field(&max_field, (n - temp) * F[temp]);
            }
        }
    }

    printf("%d", max_field);

    for (i = 0; i < n; ++i) {
        free(A[i]);
    }
    free(A);
    free(F);
    free(stack);

    return 0;
}
