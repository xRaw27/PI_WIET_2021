#include <stdio.h>

int is_prime(int n) {
    if (n == 2 || n == 3) {
        return 1;
    }
    if (n <= 1 || n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    int i = 5;
    while (i * i <= n) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return  0;
        }
        i += 6;
    }

    return 1;
}

int power(int n, int p) {
    int result = 1;
    for (int i = 1; i <= p; ++i) {
        result *= n;
    }
    return result;
}


int main() {
    int start, end;
    scanf("%d%d", &start, &end);

    int counter = 0, p = 2, numbers[10];

    while ((power(2, p) - 1) * (power(2, p - 1)) < start) {
        ++p;
    }

    while ((power(2, p) - 1) * (power(2, p - 1)) <= end) {
        if (is_prime(power(2, p) - 1) == 1) {
            numbers[counter] = (power(2, p) - 1) * (power(2, p - 1));
            ++counter;
        }
        ++p;
    }

    printf("%d\n", counter);
    for (int i = 0; i < counter; ++i){
        printf("%d ", numbers[i]);
    }

    return 0;
}
