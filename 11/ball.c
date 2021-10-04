#include <stdio.h>
#include <stdlib.h>


int max_color(int r, int g, int b) {
    int result;

    result = r;

    if (g > result) {
        result = g;
    }
    if (b > result) {
        result = b;
    }

    return result;
}


int separate_balls(int *R, int *G, int *B, int n) {
    int temp, i, j, k, all = 0, res;

    int color[3];
    int *S = malloc(n * sizeof(int));;

    for (i = 0; i < 3; ++i) {
        color[i] = 0;
    }

    int colors = 0;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < 3; ++j) {
            if (R[i] != 0 && color[j] == 0) {
                color[j] = 1;
                ++colors;
            }
        }

        if (colors > n) {
            free(S);
            return -1;
        }
        S[i] = R[i] + G[i] + B[i] - max_color(R[i], G[i], B[i]);
    }

    for (i = 0; i < n; ++i) {
        all += S[i];
    }

    res = 10 * all;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (j != i) {
                for (k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        temp = all - S[i] - S[j] - S[k];
                        temp += G[i] + B[i] + R[j] + B[j] + R[k] + G[k];

                        if (temp < res) {
                            res = temp;
                        }
                    }
                }
            }
        }
    }

    free(S);
    return res;
}


int main() {
    int n, result, i;

    scanf("%d", &n);

    int *R = malloc(n * sizeof(int));
    int *G = malloc(n * sizeof(int));
    int *B = malloc(n * sizeof(int));

    for (i = 0; i < n; ++i) {
        scanf("%d", &R[i]);
    }

    for (i = 0; i < n; ++i) {
        scanf("%d", &G[i]);
    }

    for (i = 0; i < n; ++i) {
        scanf("%d", &B[i]);
    }

    result = separate_balls(R, G, B, n);
    printf("%d", result);

    free(R);
    free(G);
    free(B);

    return 0;
}
