#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int w, h, n;
        scanf("%d %d %d", &w, &h, &n);

        int pieces = 1;
        while (w % 2 == 0) {
            pieces *= 2;
            w /= 2;
        }

        while (h % 2 == 0) {
            pieces *= 2;
            h /= 2;
        }

        if (pieces >= n) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

