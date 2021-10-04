#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int main() {
    int n, min, index_min, prev_min = INT_MAX, empty = 0;
    scanf("%d", &n);
    int *current = malloc(n * sizeof(int));
    int **arr = malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        arr[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        current[i] = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }


    while (empty < n) {
        min = INT_MAX;
        for (int i = 0; i < n; i++) {
            if ((current[i] < n) && (arr[i][current[i]] < min)) {
                min = arr[i][current[i]];
                index_min = i;
            }
        }
        ++current[index_min];
        if (current[index_min] == n) {
            empty += 1;
        }

        if (min != prev_min) {
            printf("%d ", min);
        }
        prev_min = min;
    }

    return 0;
}
