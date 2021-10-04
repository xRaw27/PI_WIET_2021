#include <stdio.h>

int main() {
    long long n, n2, k = 1, i = 1, result = 0, test = 0;

    scanf("%lld", &n);
    n2 = n;

    while (n / i > 9){
        i *= 10;
        k += i;
    }

    while (n > 0) {
        result += (n / k) * i;
        n %= k;
        i /= 10;
        k /= 10;
    }

    n = result;
    while (n > 0) {
        test += n;
        n /= 10;
    }

    if (test != n2) {
        printf("-1");
    } else {
        printf("%lld", result);
    }

    return 0;
}
