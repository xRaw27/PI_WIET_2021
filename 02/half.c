#include <stdlib.h>

int main() {
    short int n = 0;
    scanf("%hd", &n);

    short int *arr = malloc(n * sizeof(short int));
    if (arr == NULL) {
        printf("malloc failed");
        return -1; // jesli nie uda sie zaalokowac pamieci program zostaje przerwany
    }

    for (int i = 0; i < n; ++i) {
        scanf("%hd", &arr[i]);
    }

    short int p = 0, q = n - 1;
    int sum_left = 0, sum_right = 0;
    while (p < q) {
        if (sum_left < sum_right) {
            sum_left += arr[p];
            ++p;
        }
        else if (sum_right < sum_left) {
            sum_right += arr[q];
            --q;
        } else {
            sum_left += arr[p];
            sum_right += arr[q];
            ++p;
            --q;
        }
    }
    printf("%hd", p);

    free(arr);

    return 0;
}