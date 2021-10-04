#include <stdio.h>

int print_if_ascending(int n) {
    int number = n, a = 10;
    while (n > 0) {
        if (n % 10 > a) {
            return 0;
        }
        a = n % 10;
        n = n / 10;
    }
    printf("%d\n", number);
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int t[n];

    for (int i = 0; i < n; ++i) {
        t[i] = 1;
    }

    int i = 2, j = 0;
    while (i * i <= n) {
        j = i * i;
        if (t[i - 1] == 1) {
            print_if_ascending(i);
            while (j <= n) {
                t[j - 1] = 0;
                j += i;
            }
        }
        ++i;
    }

    while (i <= n) {
        if (t[i - 1] == 1) {
            print_if_ascending(i);
        }
        ++i;
    }

    return 0;
}
