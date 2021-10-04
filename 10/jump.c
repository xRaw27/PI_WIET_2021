#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int n, i, len, end = 0;

    scanf("%u", &n);
    unsigned int *input1 = calloc(n, sizeof(unsigned int));
    unsigned long *input2 = calloc(n, sizeof(unsigned long));

    for (i = 0; i < n; ++i) {
        scanf("%u %lu", &input1[i], &input2[i]);
    }

    len = input1[n - 1] + 101;
    unsigned long *fields = calloc(len, sizeof(unsigned long));

    for (i = 0; i < n; ++i) {
        fields[input1[i] + 50] = input2[i];
    }

    while (end == 0) {
        end = 1;
        for (i = 0; i < len; ++i) {
            if (fields[i] >= 3) {
                fields[i - 2] += fields[i] / 3;
                fields[i + 2] += fields[i] / 3;
                fields[i] %= 3;
                end = 0;
            }
        }
    }

    i = len - 2;
    while (1) {
        if (i <= 2) {
            break;
        } if (fields[i] > 0 && fields[i + 1] > 0) {
            fields[i] -= 1;
            fields[i + 1] -= 1;
            fields[i + 2] += 1;
            i += 2;
        } else if (fields[i] == 2 && fields[i - 1] > 0) {
            i -= 1;
        } else if (fields[i] == 2 && fields[i + 1] == 0) {
            fields[i] = 0;
            fields[i - 2] += 1;
            fields[i + 1] += 1;
            i += 1;
        } else if (fields[i] == 3) {
            fields[i - 2] += 1;
            fields[i + 2] += 1;
            fields[i] = 0;
            i += 2;
        } else {
            i -= 1;
            while (fields[i] == 0) {
                i -= 1;
                if (i <= 2) {
                    break;
                }
            }
        }
    }

    for (i = 0; i < len; ++i) {
        if (fields[i] == 1) {
            printf("%d ", i - 50);
        }
    }

    free(input1);
    free(input2);
    free(fields);

    return 0;
}
