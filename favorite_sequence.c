#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int b[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        int a[n];
        int left = 0;
        int right = n - 1;
        int idx = 0;

        while (left <= right) {
            if (idx % 2 == 0) {
                a[idx] = b[left];
                left++;
            } else {
                a[idx] = b[right];
                right--;
            }
            idx++;
        }

        for (int i = 0; i < n; i++) {
            printf("%d", a[i]);
            if (i < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

