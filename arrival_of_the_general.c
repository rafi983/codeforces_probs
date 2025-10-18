#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    int max_val = 0, min_val = 101;
    int max_idx = 0, min_idx = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_idx = i;
        }
        if (arr[i] <= min_val) {
            min_val = arr[i];
            min_idx = i;
        }
    }

    int swaps = max_idx + (n - 1 - min_idx);

    if (max_idx > min_idx) {
        swaps--;
    }

    printf("%d\n", swaps);

    return 0;
}
