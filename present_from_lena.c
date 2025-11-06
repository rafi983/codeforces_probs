#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < (n - i) * 2; j++) {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) {
            printf("%d", j);
            if (j < i) {
                printf(" ");
            }
        }

        for (int j = i - 1; j >= 0; j--) {
            printf(" %d", j);
        }

        printf("\n");
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < (n - i) * 2; j++) {
            printf(" ");
        }

        for (int j = 0; j <= i; j++) {
            printf("%d", j);
            if (j < i) {
                printf(" ");
            }
        }

        for (int j = i - 1; j >= 0; j--) {
            printf(" %d", j);
        }

        printf("\n");
    }

    return 0;
}

