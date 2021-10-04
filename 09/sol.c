#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int i, j, n, g, x, result;

    scanf("%u %u", &n, &g);
    unsigned int *T = malloc(n * sizeof(int));
    unsigned int *bits = calloc(32, sizeof(int));

    for (i = 0; i < n; ++i) {
        scanf("%u", &T[i]);
    }

    for (i = 0; i < n; ++i) {
        if ((g | T[i]) != g) {
            T[i] = 0;
        }
    }

    for (i = 0; i < n; ++i) {
        x = T[i];
        j = 0;
        while (x > 0) {
            bits[j] += x % 2;
            x /= 2;
            ++j;
        }
    }

    result = 32;
    i = 0;
    while (g > 0) {
        if (g % 2 == 1 && bits[i] < result) {
            result = bits[i];
        }
        g /= 2;
        ++i;
    }

    printf("%u", result);
    free(T);
    free(bits);

    return 0;
}
