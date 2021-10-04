#include <stdio.h>
#include <stdlib.h>

int test(int *t, short int curr, int w) {
    if (w == 0) return 1;
    if (curr < 0) return 0;

    return test(t, curr - 1, w - t[curr]) || test(t, curr - 1, w) || test(t, curr - 1, w + t[curr]);
}

int main() {
    short int n;
    int w, sum = 0;
    scanf("%hd%d", &n, &w);

    int *t = malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i) {
        scanf("%d", &t[i]);
        sum += t[i];
    }

    --n;
    if (sum < w || !test(t, n, w)) {
        printf("NO");
    }
    else {
        printf("YES");
    }

    return 0;
}