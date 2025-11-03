#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int phase = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            if (phase >= 1) {
                printf("NO\n");
                return 0;
            }
        } else if (a[i] == a[i-1]) {
            if (phase == 0) {
                phase = 1;
            } else if (phase == 2) {
                printf("NO\n");
                return 0;
            }
        } else {
            if (phase == 2) {
                phase = 2;
            } else {
                phase = 2;
            }
        }
    }

    printf("YES\n");
    return 0;
}

