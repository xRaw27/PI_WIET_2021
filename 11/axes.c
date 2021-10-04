#include <stdio.h>
#include <stdlib.h>
#include <math.h>


unsigned int symmetries(unsigned int n, double **vertices)
{
    double p1, p2, q1, q2, a1, a2, b1, b2;
    unsigned int i, j, k = 0, symmetric, counter = 0;
    double P[4 * n][2];

    for (i = 0; i < n; ++i) {
        P[k][0] = vertices[i][0];
        P[k][1] = vertices[i][1];
        P[k + 2 * n][0] = vertices[i][0];
        P[k + 2 * n][1] = vertices[i][1];
        k += 2;
    }

    for (k = 1; k < 4 * n; k += 2) {
        P[k][0] = (P[k - 1][0] + P[k + 1][0]) / 2;
        P[k][1] = (P[k - 1][1] + P[k + 1][1]) / 2;
    }

    for (i = 0; i < n; ++i) {
        symmetric = 1;

        p1 = P[i][0];
        p2 = P[i][1];
        q1 = P[i + n][0];
        q2 = P[i + n][1];

        for (j = 1; j < n; ++j) {
            a1 = P[i + n + j][0];
            a2 = P[i + n + j][1];
            b1 = P[i + n - j][0];
            b2 = P[i + n - j][1];

            if (sqrt((p1 - a1) * (p1 - a1) + (p2 - a2) * (p2 - a2)) != sqrt((p1 - b1) * (p1 - b1) + (p2 - b2) * (p2 - b2)) || sqrt((q1 - a1) * (q1 - a1) + (q2 - a2) * (q2 - a2)) != sqrt((q1 - b1) * (q1 - b1) + (q2 - b2) * (q2 - b2))) {
                symmetric = 0;
                break;
            }
        }

        if (symmetric == 1) {
            counter++;
        }
    }

    return counter;
}


int main() {
    unsigned int i, j, t, n;

    scanf("%u", &t);
    unsigned int *result = malloc(t * sizeof(unsigned int));

    for (i = 0; i < t; ++i) {
        scanf("%u", &n);

        double **vertices = malloc(n * sizeof(double *));
        for (j = 0; j < n; ++j) {
            vertices[j] = malloc(2 * sizeof(double));
        }

        for (j = 0; j < n; ++j) {
            scanf("%lf %lf", &vertices[j][0], &vertices[j][1]);
        }

        result[i] = symmetries(n, vertices);

        free(vertices);
    }

    for (i = 0; i < t; ++i) {
        printf("%u\n", result[i]);
    }

    return 0;
}