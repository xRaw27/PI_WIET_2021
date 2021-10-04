#include <stdio.h>
#include <stdlib.h>

long long int power(int n, int p) {
    long long int result = 1;
    for (int i = 1; i <= p; ++i) {
        result *= n;
    }
    return result;
}

int main() {
    short int m, b;
    scanf("%hd%hd", &m, &b);

    // używamy long long int ponieważ dla danych wejsciowych m=8 b=16 typ int jest za mały
    long long int number_decimal, number_decimal_limit, sum;
    short int *number = malloc(m * sizeof(short int));
    long long int *powers = malloc(b * sizeof(long long int));
    char symbols[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < m; ++i) {
        number[i] = 0;
    }
    for (int i = 0; i < b; ++i) {
        powers[i] = power(i, m);
    }

    number[m - 1] = 1;
    number_decimal = power(b, m - 1);
    number_decimal_limit = power(b, m);

    short int not_found = 1;
    while (number_decimal < number_decimal_limit) {
        sum = 0;
        for (int i = 0; i < m; ++i) {
            sum += powers[number[i]];
        }

        if (sum == number_decimal) {
            for (int i = m - 1; i >= 0; --i) {
                printf("%c", symbols[number[i]]);
            }
            printf(" ");
            not_found = 0;
        }

        for (int i = 0; i < m; ++i) {
            number[i] += 1;
            if (number[i] == b) {
                number[i] = 0;
            } else {
                break;
            }
        }
        ++number_decimal;
    }
    if (not_found) {
        printf("NO");
    }

    free(number);
    free(powers);

    return 0;
}