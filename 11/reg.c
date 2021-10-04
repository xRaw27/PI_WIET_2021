#include <stdio.h>
#include <stdlib.h>

struct tuple {
    unsigned int result, len;
};

struct tuple recursive_test(unsigned int x, unsigned int t, unsigned int result, unsigned int len) {
    struct tuple res, temp;
    res.result = 0;
    res.len = 0;

    if (x == t) {
        res.result = result;
        res.len = len;
        return res;
    } else if (x > t) {
        return res;
    }

    unsigned best = 50;

    if (x < 31623 && x != 1) {
        res = recursive_test(x * x, t, result, len + 1);
        best = res.len;
    }

    temp = recursive_test(2 * x, t, result + (1 << len), len + 1);
    if (best == 0 || (temp.len > 0 && temp.len < best)) {
        res = temp;
    }

    return res;
}

void print_result(unsigned int len, unsigned int x) {
    int i;
    unsigned int arr[len];

    for (i = len - 1; i >= 0; --i) {
        if (x >= (1 << i)) {
            arr[i] = 1;
            x -= 1 << i;
        } else {
            arr[i] = 0;
        }
    }

    for (i = 0; i < len; ++i) {
        if (arr[i] == 1) {
            printf("+");
        } else {
            printf("*");
        }
    }
}

int main() {
    unsigned int s, t;

    scanf("%u %u", &s, &t);

    if (t == 0) {
        printf("-");
        return 0;
    }

    if (t == 1) {
        printf("/");
        return 0;
    }

    struct tuple result1, result2;

    result1 = recursive_test(s, t, 0, 0);
    printf("%u %u", result1.result, result1.len);

    printf("\n");

    result2 = recursive_test(1, t, 0, 0);
    printf("%u %u", result2.result, result2.len);

    if (result1.len == 0 && result2.len == 0) {
        printf("NO");
        return 0;
    }
    else if (result2.len == 0) {
        print_result(result1.len, result1.result);
        return 0;
    }
    else if (result1.len == 0) {
        printf("/");
        print_result(result2.len, result2.result);
        return 0;
    }
    else if (result1.len <= result2.len + 1) {
        print_result(result1.len, result1.result);
        return 0;
    }
    else {
        printf("/");
        print_result(result2.len, result2.result);
        return 0;
    }
}
