#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n = 0, k;
    char max = 0;
    char *string = calloc(50, sizeof(char));

    scanf("%s", string);

    for (i = 0; i < 50; ++i) {
        if (string[i] != 0) {
            ++n;
        }
    }

    k = -1;
    while (k < n - 1) {
        max = 0;
        for (i = k + 1; i < n; ++i) {
            if (string[i] > max) {
                k = i;
                max = string[i];
            }
        }
        printf("%c", max);
    }

    return 0;
}
