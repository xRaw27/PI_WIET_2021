#include <stdio.h>

struct Tuple {
    long long int  a;
    long long int  b;
};

struct Tuple compute(long long int  k) {
    // funkcja odejmuje kolejne wyrazy ciągu fibbonaciego i w ten sposób wyznacza i pozycję,
    // na której w wynikowym ciągu znajdzie się jedynka
    long long int  a, b, i = 0;
    k -= 2;
    i += 1;
    a = 1;
    b = 2;
    while (k > a) {
        k -= a;
        b = a + b;
        a = b - a;
        i += 1;
    }

    struct Tuple result = {i, k};
    return result;
}

int main() {
    long long int  n, k, i;
    scanf("%lld %lld", &n, &k);

    n -= 1;
    struct Tuple result;

    while (k > 2) {
        result = compute(k);
        if (result.a > n) {
            printf("-1");
            return 0;
        }

        for (i = n; i > result.a; --i) {
            printf("0");
        }
        printf("1");

        k = result.b;
        n = result.a - 1;
    }

    for (i = n; i > 0; --i) {
        printf("0");
    }
    if (k == 1) {
        printf("0");
    } else {
        printf("1");
    }

    return 0;
}
