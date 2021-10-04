#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n = 0, p, o, x, better;

    char *string = calloc(50, sizeof(char));
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    scanf("%s", string);

    for (i = 0; i < 50; ++i) {
        if (string[i] != 0) {
            ++n;
        }
    }

    char *best = calloc(n, sizeof(char));
    for (i = 0; i < n; ++i) {
        best[i] = 'z';
    }

    for (o = 0; o < n; ++o) {
        i = 0;
        p = prime[i];
        while (p < n) {
            better = 0;
            for (x = 0; x < n; ++x) {
                if (better == 1) {
                    best[x] = string[(o + p * x) % n];
                } else {
                    if (string[(o + p * x) % n] < best[x]) {
                        better = 1;
                        best[x] = string[(o + p * x) % n];
                    } else if (string[(o + p * x) % n] > best[x]) {
                        break;
                    }
                }
            }
            ++i;
            p = prime[i];
        }
    }

    for (i = 0; i < n; ++i) {
        printf("%c", best[i]);
    }

    return 0;
}
