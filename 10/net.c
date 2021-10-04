#include <stdio.h>
#include <stdlib.h>

int f(int x, int **gates, int *input, int *F) {
    if (F[x] != -1) {
        return F[x];
    }

    int a = gates[x][0];
    int b = gates[x][1];

    if (a < 0) {
        a = input[-(a + 1)];
    } else {
        a = f(a - 1, gates, input, F);
    }

    if (b < 0) {
        b = input[-(b + 1)];
    } else {
        b = f(b - 1, gates, input, F);
    }

    F[x] = a ^ b;
    return a ^ b;
}

void add_one(int n, int *arr) {
    int i, carry = 0;
    arr[n - 1] += 1;

    for (i = n - 1; i >= 0; --i) {
        arr[i] += carry;
        if (arr[i] == 2) {
            arr[i] = 0;
            carry = 1;
        } else {
            break;
        }
    }
}

int equal(int n, const int *last, const int *first) {
    int i;
    for (i = 0; i < n; ++i) {
        if (last[i] != first[i]) {
            return 0;
        }
    }
    return 1;
}

int xor_network(int n, int m, int **gates, int *input, int *last, int output) {
    int i, result = 0;
    int *F = malloc(m * sizeof(int));

    for (i = 0; i < m; ++i) {
        F[i] = -1;
    }
    result += f(output - 1, gates, input, F);

    while (equal(n, input, last) == 0) {
        for (i = 0; i < m; ++i) {
            F[i] = -1;
        }
        add_one(n, input);
        result += f(output - 1, gates, input, F);
    }

    return result;
}


int main() {
    int n, m, output, i, result;

    scanf("%d %d %d", &n, &m, &output);

    int **gates = malloc(m * sizeof(int *));
    for (i = 0; i < m; ++i) {
        gates[i] = malloc(2 * sizeof(int));
    }

    char *string = malloc(n * sizeof(char));
    int *input = malloc(n * sizeof(int));
    int *last = malloc(n * sizeof(int));

    for (i = 0; i < m; ++i) {
        scanf("%d %d", &gates[i][0], &gates[i][1]);
    }

    scanf("%s", string);
    for (i = 0; i < n; ++i) {
        input[i] = (int) string[i] - 48;
    }

    scanf("%s", string);
    for (i = 0; i < n; ++i) {
        last[i] = (int) string[i] - 48;
    }

    result = xor_network(n, m, gates, input, last, output);
    printf("%d", result);

    return 0;
}
