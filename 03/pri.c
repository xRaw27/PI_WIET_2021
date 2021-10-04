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
            return 0;
        }
        i += 6;
    }

    return 1;
}

int is_onesquared(int n) {
    int k = 0;
    while (n != 1 && n != 4) {
//        printf("%d ", n);
        while (n > 0) {
            k += (n % 10) * (n % 10);
            n /= 10;
        }
        n = k;
        k = 0;
    }
    return n;
}


int main() {
    int l, u, k, result = 0;
    scanf("%d%d%d", &l, &u, &k);

    for (int i = l; i <= u; ++i) {
        if (is_prime(i) && is_onesquared(i) == 1) {
            k -= 1;
            if (k == 0) {
                result = i;
                break;
            }
        }
        if (u - i < k) {
            result = -1;
            break;
        }
    }

    printf("%d", result);

    return 0;
}
