#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a = 1, b = 1;
    while (a * b < n) {
        b = a + b;
        a = b - a;
    }

    if (a * b == n) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}
