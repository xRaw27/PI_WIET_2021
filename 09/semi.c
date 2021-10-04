#include <stdio.h>

int main() {
    unsigned int i, n, m, x, result, a;
    scanf("%u %u", &n, &m);

    result = 0;
    for (x = 0; x < (1 << n); ++x) {
        if (x % m == 0) {
            continue;
        }
        for (i = 0; i < n; ++i) {
            a = (x ^ (1 << i));
            if ((a % m == 0) && (a != 0)) {
                ++result;
                break;
            }
        }

    }
    printf("%u", result);

    return 0;
}
