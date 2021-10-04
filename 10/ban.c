#include <stdio.h>
#include <stdlib.h>

int divide(int *n) {
    int i, carry = 0, new_carry, mod;

    mod = n[0] % 2;
    for (i = 31; i >= 0; --i) {
        new_carry = 10 * ((n[i] + carry) % 2);
        n[i] = (n[i] + carry) / 2;
        carry = new_carry;
    }

    return mod;
}


void convert(int *n, int a, int b) {
    int i, j, carry = 0;

    for (j = 127; j > 0; --j) {
        if (n[j] == 1) {
            break;
        }
    }

    for (i = 0; i < j + 3; ++i) {
        if (i % 2 == a) {
            n[i] += carry + 1;
        } else {
            n[i] += carry;
        }

        if (n[i] >= 2) {
            carry = 1;
            n[i] -= 2;
        } else {
            carry = 0;
        }

        if ((i % 2 == a && n[i] == 0) || (i % 2 == b && n[i] == 1)) {
            n[i] = 1;
        } else {
            n[i] = 0;
        }
    }
}


int main() {
    int i, j, end = 0, possible;

    char *string = calloc(32, sizeof(char));
    int *n = calloc(32, sizeof(int));
    int *binary1 = calloc(128, sizeof(int));
    int *binary2 = calloc(128, sizeof(int));
    scanf("%s", string);

    j = 0;
    for (i = 31; i >= 0; --i) {
        if (string[i] != 0) {
            n[j] = (int) string[i] - 48;
            j += 1;
        }
    }

    j = 0;
    while (end == 0) {
        binary1[j] = divide(n);
        ++j;

        end = 1;
        for (i = 0; i < 30; ++i) {
            if (n[i] != 0) {
                end = 0;
                break;
            }
        }
    }

    for (i = 0; i < 128; ++i) {
        binary2[i] = binary1[i];
    }

    convert(binary1, 1, 0);
    convert(binary2, 0, 1);

    possible = 1;
    for (i = 0; i < 128; ++i) {
        if (binary1[i] == 1 && i >= 100) {
            possible = 0;
        }
    }
    if (possible == 1) {
        for (i = 0; i < 128; ++i) {
            if (binary1[i] == 1) {
                printf("%d ", i);
            }
        }
    } else {
        printf("NO");
    }

    printf("\n");

    possible = 1;
    for (i = 0; i < 128; ++i) {
        if (binary2[i] == 1 && i >= 100) {
            possible = 0;
        }
    }
    if (possible == 1) {
        for (i = 0; i < 128; ++i) {
            if (binary2[i] == 1) {
                printf("%d ", i);
            }
        }
    } else {
        printf("NO");
    }

    free(string);
    free(n);
    free(binary1);
    free(binary2);

    return 0;
}
