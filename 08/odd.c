#include <stdio.h>

unsigned long long arithmetic_seq_sum(unsigned long long n) {
    if (n % 2 == 0) {
        --n;
    }
    return (1 + n) * (n / 2 + 1) / 2;
}


int main() {
    unsigned long long n, sum = 0;

    scanf("%llu", &n);

    while (n > 0) {
        sum += arithmetic_seq_sum(n);
        n /= 2;
    }

    printf("%llu", sum);

    return 0;
}
