#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        if (n % 2 == 1) {
            printf("-1\n");
        } else {
            printf("0 0 %d\n", n / 2);
        }
    }

    return 0;
}

