#include <stdio.h>

int main() {
    int n, b, d;
    scanf("%d %d %d", &n, &b, &d);

    int waste = 0;
    int emptyCount = 0;

    for (int i = 0; i < n; i++) {
        int orange;
        scanf("%d", &orange);

        if (orange <= b) {
            waste += orange;

            if (waste > d) {
                emptyCount++;
                waste = 0;
            }
        }
    }

    printf("%d\n", emptyCount);

    return 0;
}